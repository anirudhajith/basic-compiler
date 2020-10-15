   .file	"test.c"
   .text
   .comm	glob,4,4
   .section	.rodata
.LC0:
   .string	"%d\n"
   .text
   .globl	main
   .type	main, @function
main:
.LFB0:
   .cfi_startproc
   pushq	%rbp
   .cfi_def_cfa_offset 16
   .cfi_offset 6, -16
   movq	%rsp, %rbp
   .cfi_def_cfa_register 6
   pushq $0
   pushq $0
   pushq $50
   popq -8(%rbp)
   pushq $100
   popq -16(%rbp)
   pushq -16(%rbp)
   pushq $3
   movq 0(%rsp), %rax
   cmp %rax, 8(%rsp)
   movq $0, 0(%rsp)
   jng L2
   notq 0(%rsp)
L2:
   popq %rax
   notq %rax
   pushq %rax
   cmp $0, 0(%rsp)
   popq %rax
   je L4
   pushq $5
   popq -16(%rbp)
   jmp L3
L4:
   pushq $4
   popq -16(%rbp)
L3:
   movl	-8(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-16(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
L7:
   pushq -8(%rbp)
   pushq $0
   movq 0(%rsp), %rax
   cmp %rax, 8(%rsp)
   movq $0, 0(%rsp)
   jng L5
   notq 0(%rsp)
L5:
   cmp $0, 0(%rsp)
   popq %rax
   je L6
   pushq -16(%rbp)
   pushq $2
   popq %rax
   popq %rbx
   addq %rax, %rbx
   pushq %rbx
   popq -16(%rbp)
   decq -8(%rbp)
   jmp L7
L6:
   movl	-8(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-16(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	$0, %eax
   leave
   .cfi_def_cfa 7, 8
   ret
   .cfi_endproc
.LFE0:
   .size	main, .-main
   .ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
   .section	.note.GNU-stack,"",@progbits
