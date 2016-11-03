
int life_and_stuff = 42;

char buf[42];

__thread int tls_thing;
__thread int tls_initialized_thing = 42;

__attribute__((constructor)) void start_me_up()
{
    tls_thing = 22;
    tls_initialized_thing = 2;
}

__attribute__((destructor)) void goin_down()
{
    tls_thing = -22;
}

int main()
{
    short *screen = (short*)0xB8000;
    static char message[] = "In kernel!!!";
    for (int i = 0; message[i]; ++i)
        screen[i] = 0x700 | message[i];

    return 42;
}
