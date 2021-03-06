#include "tui.h"
#include "screen.h"
#include "string.h"
#include "tui_scancode.h"

tui_str_t tui_dis_ena[] = {
    TSTR "disabled",
    TSTR "enabled"
};

static char const tui_numpad[] = {
    '7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.'
};

void tui_menu_renderer_t::measure()
{
    max_title = 0;
    max_value = 0;

    for (size_t i = 0; i < items->count; ++i) {
        int len = (*items)[i].title.len;
        if (max_title < len)
            max_title = len;
        for (size_t v = 0; v < (*items)[i].options.count; ++v) {
            len = (*items)[i].options[v].len;
            if (max_value < len)
                max_value = len;
        }
    }
}



void tui_menu_renderer_t::center(int offset)
{
    measure();

    int width = 2 + max_title + 1 + max_value + 2;
    int height = items->count + 2;

    if (height > 23)
        height = 23;

    left = 40 - (width >> 1);
    top = 12 - (height >> 1) + offset;
    resize(width, height);
}

void tui_menu_renderer_t::position(int x, int y)
{
    int width = 2 + max_title + 1 + max_value + 2;
    int height = 2 + items->count + 2;

    left = x;
    top = y;
    resize(width, height);
}

void tui_menu_renderer_t::resize(int width, int height)
{
    right = left + width;
    bottom = top + height;
}

void tui_menu_renderer_t::draw(size_t index, size_t selected, bool full)
{
    int height = bottom - top + 1;

    int selected_scrn_row = index - scroll_pos;

    // Clamp scroll position to force selection within viewport
    if (selected_scrn_row >= height) {
        scroll_pos = index - height + 1;
        full = true;
    } else if (selected_scrn_row < 0) {
        scroll_pos = index;
        full = true;
    }

    if (full)
        print_box(left, top, right - 1, bottom - 1, 7, true);

    for (size_t i = scroll_pos; (i < items->count) &&
         (i < size_t(scroll_pos + height)); ++i) {
        tui_menu_item_t& item = (*items)[i];

        auto attr = i == selected ? 0x70 : 0x07;

        if (full || i == index) {
            print_str_xy(left + 2, top + 1 + i - scroll_pos,
                         item.title, item.title, attr, max_title + 1);

            print_str_xy(left + 2 + max_title + 1,
                         top + 1 + i - scroll_pos,
                         item.options[item.index],
                    item.options[item.index],
                    attr, max_value);
        }
    }
}

// Wait for a key
int waitkey()
{
    while (!pollkey())
    {
        //pollmouse();
    }
    return readkey();
}

void tui_menu_renderer_t::interact_timeout(int ms)
{
    if (ms < 54)
        return;

    size_t selection = 0;
    draw(selection, selection, true);

    int ms_ticks = ms / 54;

    if (!wait_input(ms))
        return;

    // Wait timeout seconds for a keystroke
    int ticks_last = systime();
    int ticks_elap = 0;

    do {
        int ticks_this = systime();

        //*(int volatile*)0xb8000 = ticks_this;

        // Discard wraparound
        if (ticks_this <= ticks_last)
            continue;

        ticks_elap += ticks_this - ticks_last;
        ticks_last = ticks_this;

        // Check for timeout
        if (ticks_elap > ms_ticks)
            return;
    } while (!pollkey());

    for (;;) {
        int key = waitkey();

        tui_menu_item_t *menuitem;

        switch (key & 0xFF) {
        case 0x00:
            key >>= 8;
            if (key >= key_num_first && key <= key_num_last)
                key = tui_numpad[key - key_num_first];

            break;
        }

        switch (key & 0xFF) {
        case 0xE0:
            switch (key) {
            case key_up:
                // Deselect
                draw(selection, selection + 1, false);

                if (selection > 0)
                    --selection;
                else
                    selection = items->count - 1;

                draw(selection, selection, false);

                continue;

            case key_down:
                draw(selection, selection + 1, false);

                if (++selection >= items->count)
                    selection = 0;

                draw(selection, selection, false);

                continue;

            case key_left:
                menuitem = &(*items)[selection];
                if (menuitem->index > 0)
                    --menuitem->index;
                draw(selection, selection, false);
                break;

            case key_right:
                menuitem = &(*items)[selection];
                if (menuitem->index + 1 < menuitem->options.count)
                    ++menuitem->index;
                draw(selection, selection, false);
                break;

            case key_home:
                selection = 0;
                draw(selection, selection, false);
                continue;

            case key_end:
                selection = items->count - 1;
                draw(selection, selection, false);
                continue;

            case key_F10:
                // Same as esc
                key = '\x1b';
                break;

            }
            break;

        default:
            key &= 0xFF;
            break;

        }

        // Exit on esc
        if (key == '\x1b')
            break;
    }
}
