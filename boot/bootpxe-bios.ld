ENTRY(early_entry)

SECTIONS {
	.text 0x1000 : AT(0x1000) {
		___text_st = .;
		KEEP(*(.head))
		KEEP(*(.early))
		*(.text)
		*(.text.*)
		*(.text.unlikely)

		. = ALIGN(64);
		*(.data)
		*(.data.*)
		*(.rodata)
		*(.rodata.*)

		. = ALIGN(16);
		__init_array_start = .;
		KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)))
		KEEP(*(SORT_BY_INIT_PRIORITY(.ctors.*)))
		__init_array_end = .;

		__init_array_early_start = .;
		KEEP(*(.ctors))
		KEEP(*(.init_array))
		__init_array_early_end = .;

		. = ALIGN(16);
		___dtors_st = .;
		KEEP(*(.dtors))
		KEEP(*(.dtors.*))
		KEEP(*(.fini_array))
		KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*)))
		___dtors_en = .;

		. = ALIGN(64);
		___smp_st = .;
		KEEP(*(.smp.entry))
		KEEP(*(.smp.text))
		. = ALIGN(64);
		KEEP(*(.smp.data))
		___smp_en = .;

		/* self relocation code at end to avoid overwriting itself */
		KEEP(*(.text.reloc))

		/* packet align end */
		. = ALIGN(512);
		___initialized_data_en = .;
	} = 0

	.bss : {
		___bss_st = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		*(COMMON.*)
		*(COMMON*)

		. = ALIGN(16);
		. += 8;
		___bss_en = .;
	}

	___initial_stack_limit = .;
	. = ABSOLUTE(0xFFF0);
	___initial_stack = .;
	___heap_st = .;
	___end = .;

	.eh_frame       0 : { *(.eh_frame)      }
	.debug          0 : { *(.debug)         }
	.debug_info		0 : { *(.debug_info)    }
	.debug_abbrev	0 : { *(.debug_abbrev)  }
	.debug_aranges	0 : { *(.debug_aranges) }
	.debug_ranges	0 : { *(.debug_ranges)  }
	.debug_frame	0 : { *(.debug_frame)   }
	.debug_macro	0 : { *(.debug_macro)   }
	.debug_line		0 : { *(.debug_line)    }
	.debug_str		0 : { *(.debug_str)     }
	.debug_loc		0 : { *(.debug_loc)     }
	.comment        0 : { *(.comment)       }

	/DISCARD/		0 : { *(.interp)               }
	/DISCARD/		0 : { *(.comment)              }
	/DISCARD/		0 : { *(.note.gnu.build-id)    }
}
