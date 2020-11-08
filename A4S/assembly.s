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
      subq  $44, %rsp
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
      leaq -20(%rbp) , %rsi
      leaq .LC1(%rip) , %rdi
      movl $0 , %eax
      call scanf@PLT
      movl $10 , %eax
      movl %eax , -24(%rbp)
      movl $2 , %eax
      movl %eax , -32(%rbp)
      movl $6 , %eax
      movl %eax , -36(%rbp)
      movl -4(%rbp) , %eax
      movl %eax , -28(%rbp)
      movl -4(%rbp) , %eax
      imull $10 , %eax
      movl %eax , -40(%rbp)
      movl -40(%rbp) , %eax
      movl %eax , -4(%rbp)
      movl $52 , %eax
      movl %eax , -32(%rbp)
      movl $56 , %eax
      movl %eax , -36(%rbp)
      movl $60 , %eax
      movl %eax , -36(%rbp)
      movl -28(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -32(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      movl -36(%rbp) , %esi
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
