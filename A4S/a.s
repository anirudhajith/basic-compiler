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
      subq  $60, %rsp
      leaq -4(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      leaq -8(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      leaq -12(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      leaq -16(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl -8(%rbp) , %eax
      addl -12(%rbp) , %eax
      movl %eax , -20(%rbp)
      movl -20(%rbp) , %eax
      movl %eax , -4(%rbp)
      movl -20(%rbp) , %eax
      movl %eax , -16(%rbp)
      movl -20(%rbp) , %eax
      addl -20(%rbp) , %eax
      movl %eax , -36(%rbp)
      movl -36(%rbp) , %eax
      movl %eax , -16(%rbp)
      leaq -8(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl -8(%rbp) , %eax
      addl -12(%rbp) , %eax
      movl %eax , -40(%rbp)
      movl -40(%rbp) , %eax
      addl -40(%rbp) , %eax
      movl %eax , -48(%rbp)
      movl -48(%rbp) , %eax
      addl -40(%rbp) , %eax
      movl %eax , -56(%rbp)
      movl -56(%rbp) , %eax
      movl %eax , -16(%rbp)
      movl -4(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -12(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -16(%rbp) , %esi
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
