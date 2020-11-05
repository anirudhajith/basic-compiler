      .file	"a.c"
      .text
      .section  .rodata
.LC0:
      .string	"%d\n"
      .text
      .globl	main
      .type	main, @function
main:
      .cfi_startproc
      pushq    %rbp
      .cfi_def_cfa_offset 16
      .cfi_offset 6, -16
      movq	%rsp, %rbp
      .cfi_def_cfa_register 6
      subq  $12, %rsp
      movl $40 , %eax
      movl %eax , -4(%rbp)
      movl $25 , %eax
      movl %eax , -8(%rbp)
      movl $35 , %eax
      movl %eax , -8(%rbp)
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl $0 , %eax
      leave
      ret
      leave
      .cfi_def_cfa 7, 8
      ret
      .cfi_endproc
