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
   movq %rbp, %rsp
   subq $8, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $16, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $24, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $32, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $40, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $48, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $56, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $64, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $72, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $80, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $88, %rsp
   pushq $1
   popq %rax
   negq %rax
   pushq %rax
   popq -24(%rbp)
   pushq $2999
   popq -8(%rbp)
   pushq $2999
   pushq $6
   popq %rbx
   popq %rax
   cqto
   idivq %rbx
   pushq %rdx
   popq -16(%rbp)
   pushq $0
   popq -32(%rbp)
   pushq $90
   popq -72(%rbp)
   pushq $85
   popq -80(%rbp)
L4:
   pushq -16(%rbp)
   pushq $1
   popq %rax
   cmp %rax, 0(%rsp)
   movq $0, 0(%rsp)
   jnge L2
   notq 0(%rsp)
L2:
   cmp $0, 0(%rsp)
   popq %rax
   je L3
   pushq -24(%rbp)
   pushq $1
   popq %rax
   popq %rbx
   addq %rax, %rbx
   pushq %rbx
   popq -24(%rbp)
   pushq -16(%rbp)
   pushq $1
   popq %rax
   popq %rbx
   subq %rax, %rbx
   pushq %rbx
   popq -16(%rbp)
   pushq -32(%rbp)
   popq %rax
   notq %rax
   pushq %rax
   popq -32(%rbp)
   pushq -72(%rbp)
   pushq $1
   popq %rax
   popq %rbx
   subq %rax, %rbx
   pushq %rbx
   popq -72(%rbp)
   pushq -80(%rbp)
   pushq $1
   popq %rax
   popq %rbx
   addq %rax, %rbx
   pushq %rbx
   popq -80(%rbp)
   jmp L4
L3:
   pushq -24(%rbp)
   pushq $2
   popq %rbx
   popq %rax
   cqto
   idivq %rbx
   pushq %rdx
   popq -16(%rbp)
   pushq -24(%rbp)
   popq -8(%rbp)
   pushq -16(%rbp)
   pushq -32(%rbp)
   popq %rax
   popq %rbx
   andq %rax, %rbx
   pushq %rbx
   popq -40(%rbp)
   pushq $21
   pushq -8(%rbp)
   popq %rax
   imulq 0(%rsp)
   mov %rax, 0(%rsp)
   popq -48(%rbp)
   pushq $786
   pushq -48(%rbp)
   popq %rax
   popq %rbx
   subq %rax, %rbx
   pushq %rbx
   popq -56(%rbp)
   pushq $13
   pushq $51
   popq %rax
   imulq 0(%rsp)
   mov %rax, 0(%rsp)
   popq -64(%rbp)
   pushq -64(%rbp)
   pushq $3
   popq %rbx
   popq %rax
   cqto
   idivq %rbx
   pushq %rax
   popq -64(%rbp)
   pushq -64(%rbp)
   pushq -56(%rbp)
   popq %rax
   cmp %rax, 0(%rsp)
   movq $0, 0(%rsp)
   jng L5
   notq 0(%rsp)
L5:
   popq -80(%rbp)
   pushq -16(%rbp)
   popq %rax
   notq %rax
   pushq %rax
   cmp $0, 0(%rsp)
   popq %rax
   je L8
   pushq $0
   movq %rbp, %rsp
   subq $96, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $104, %rsp
   pushq $11
   pushq $2
   popq %rax
   popq %rbx
   addq %rax, %rbx
   pushq %rbx
   popq -104(%rbp)
   pushq -56(%rbp)
   popq -96(%rbp)
   pushq -96(%rbp)
   pushq -104(%rbp)
   popq %rbx
   popq %rax
   cqto
   idivq %rbx
   pushq %rdx
   popq -96(%rbp)
   pushq -96(%rbp)
   popq -8(%rbp)
   movl	-8(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   jmp L7
L8:
   pushq $0
   movq %rbp, %rsp
   subq $112, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $120, %rsp
   pushq -72(%rbp)
   popq -112(%rbp)
   pushq -80(%rbp)
   popq -120(%rbp)
   pushq -112(%rbp)
   pushq -120(%rbp)
   popq %rax
   cmp %rax, 0(%rsp)
   movq $0, 0(%rsp)
   jne L6
   notq 0(%rsp)
L6:
   popq -16(%rbp)
   movl	-16(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
L7:
   pushq -80(%rbp)
   popq %rax
   notq %rax
   pushq %rax
   popq -88(%rbp)
   cmp $0, 0(%rsp)
   popq %rax
   je L10
   movl	-24(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-40(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-56(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-72(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   jmp L9
L10:
   movl	-32(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-48(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-64(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
   movl	-80(%rbp), %eax
   movl	%eax, %esi
   leaq	.LC0(%rip), %rdi
   movl	$0, %eax
   call	printf@PLT
L9:
   movl	$0, %eax
   leave
   .cfi_def_cfa 7, 8
   ret
   .cfi_endproc
.LFE0:
   .size	main, .-main
   .ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
   .section	.note.GNU-stack,"",@progbits
