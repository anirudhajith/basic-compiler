	.text
	.section   .rodata
.LC0:
	.string "%d" 
.LC1:
	.string "%d\n" 
	.text
	.globl  main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$56, %rsp
	movl	$2, %eax
	pushq	%rax
	movl	$7, %eax
	popq	%rbx
	subl	%ebx, %eax
	pushq	%rax
	movl	$3, %eax
	popq	%rbx
	addl	%ebx, %eax
	pushq	%rax
	movl	$3, %eax
	pushq	%rax
	movl	$2, %eax
	popq	%rbx
	addl	%ebx, %eax
	popq	%rbx
	imul	%ebx, %eax
	movl	%eax, -4(%rbp)
	movl	$3, %eax
	pushq	%rax
	movl	$2, %eax
	popq	%rbx
	addl	%ebx, %eax
	pushq	%rax
	movl	$5, %eax
	pushq	%rax
	movl	-8(%rbp), %eax
	popq	%rbx
	addl	%ebx, %eax
	popq	%rbx
	imul	%ebx, %eax
	movl	%eax, -8(%rbp)
	movl	$10, %eax
	pushq	%rax
	movl	-4(%rbp), %eax
	popq	%rbx
	cmpl	%ebx, %eax
	jg	.L1
	movl	$0, %eax
	jmp	.L2
.L1:
	movl	$1, %eax
.L2:
	cmpl	$0, %eax
	je	.L3
	movl	$10, %eax
	pushq	%rax
	movl	-8(%rbp), %eax
	popq	%rbx
	addl	%ebx, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L3:
	movl	-8(%rbp), %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	movl	$0, %eax
	leave
	ret
	leave
	ret

