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
    __bss_start = .;
    *(.bss)
    __bss_end = .;
  }

}
