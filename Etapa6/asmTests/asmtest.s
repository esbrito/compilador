	.file	"asmtest.c"
	.globl	a
	.data
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.long	0
	.long	1081360384
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	3
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
	movl	b(%rip), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	a(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, a(%rip)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
