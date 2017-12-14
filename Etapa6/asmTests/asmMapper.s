
## DATA
.data

#for each string
stringVar:	.string	"teste"
formatIntString:	.string "%d"

## for each variable (and literals as variables beginning with _) in hashtable
var: .long	324
op1: .long 100
op2: .long 333
res: .long 0


## TAC BEGIN PROGRAM
	.globl	main
	.type	main, @function


##TAC BEGINFUN
main:
		.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6

##TAC PRINT STRING
	movl	$stringVar, %edi
	movl	$0, %eax
	call	printf

##TAC ASSIGN (assign variable, as mentioned literals will be variables)
	movl	op1(%rip), %eax
	movl	%eax, res(%rip)

##TAC ADD
  movl	op1(%rip), %eax
  movl	op2(%rip), %edx
  addl	%edx, %eax
  movl	%eax, res(%rip)

##TAC PRINT VARIABLE
	movl	res(%rip), %eax
	movl	%eax, %esi
	movl	$formatIntString, %edi
	movl	$0, %eax
	call	printf

##TAC ENDFUN
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
