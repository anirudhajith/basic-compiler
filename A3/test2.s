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
   subq $16, %rsp
   pushq $0
   movq %rbp, %rsp
   subq $24, %rsp
   pushq $13
   popq -16(%rbp)
   popq -24(%rbp)
   movl	-24(%rbp), %eax
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
