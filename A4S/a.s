      .file	"a.c"
      .text
      .section  .rodata
.LC0:
      .string	"%d\n"
.LC1:
      .string	"%d"
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
      subq  $28, %rsp
      leaq -4(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl -4(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -4(%rbp) , -12(%rbp)
      movl -12(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -4(%rbp) , %eax
      negl %eax
      movl %eax , -16(%rbp)
      movl -16(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -12(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -16(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -4(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl $0 , %eax
      leave
      ret
      leave
      .cfi_def_cfa 7, 8
      ret
      .cfi_endproc
