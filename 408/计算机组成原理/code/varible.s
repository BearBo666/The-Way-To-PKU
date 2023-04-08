	.file	"varible.c"
	.text
	.globl	var2
	.data
	.align 4
var2:
	.long	100
	.globl	var3
	.section .rdata,"dr"
	.align 4
var3:
	.long	200
	.data
	.align 4
var4:
	.long	300
	.comm	var5, 16, 4
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$16, %ecx
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
