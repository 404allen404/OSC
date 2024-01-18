SECTIONS
{
  . = 0x80000;

  .text :
  {
    *(.text)
  }

  .data : 
  {
    *(.data)
  }

  .bss :
  {
    __bss_start = ALIGN(0x10);
    *(.bss)
    __bss_end = ALIGN(0x10);
  }

}
