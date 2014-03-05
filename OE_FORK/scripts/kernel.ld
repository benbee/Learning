/*
 *		kernel.ld -- link file for kernel
 */
 ENTRY(start)
 SECTIONS
 {
		 /* section start */

		 . = 0x100000;
		 .text :
		 {
				*(.text)
				. = ALIGN(4096);
		 }

		 .data :
		 {
				*(.data)
				*(.rodata)
				. = ALIGH(4096);
		 }

		 .bss :
		 {
		 *(.bss)
		 . = ALIGN(4096);
		 }

		 .stab :
		 {
				*(.stab)
				. = ALIGN(4096);
		 }

		 .stabstr :
		 {
				*(.stabstr)
				. = ALIGN(4096);
		 }

		 /DISCARD/ : { *(.comment) *(.eh_frame) }
 }
