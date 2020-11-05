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
      subq  $48, %rsp
      movl $2 , %eax
      addl $3 , %eax
      movl %eax , -12(%rbp)
      movl $7 , %eax
      subl $2 , %eax
      movl %eax , -16(%rbp)
      movl $3 , %eax
      addl -16(%rbp) , %eax
      movl %eax , -20(%rbp)
      movl -12(%rbp) , %eax
      imull -20(%rbp) , %eax
      movl %eax , -24(%rbp)
      movl -24(%rbp) , %eax
      movl %eax , -4(%rbp)
      movl -8(%rbp) , %eax
      addl $5 , %eax
      movl %eax , -28(%rbp)
      movl $2 , %eax
      addl $3 , %eax
      movl %eax , -32(%rbp)
      movl -28(%rbp) , %eax
      imull -32(%rbp) , %eax
      movl %eax , -36(%rbp)
      movl -36(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl $10 , %eax
      movl -4(%rbp) , %ebx
      cmpl %eax , %ebx
      setg %al
      movzbl %al , %eax
      movl %eax , -40(%rbp)
      movl -40(%rbp) , %eax
      cmpl $0 , %eax
      je .L1
      movl -8(%rbp) , %eax
      addl $10 , %eax
      movl %eax , -44(%rbp)
      movl -44(%rbp) , %eax
      movl %eax , -8(%rbp)
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
      jmp .L2
.L1:
      movl -8(%rbp) , %esi
      leaq .LC0(%rip) , %rdi
      movl $0 , %eax
      call printf@PLT
.L2:
      movl $0 , %eax
      leave
      ret
      leave
      .cfi_def_cfa 7, 8
      ret
      .cfi_endproc
