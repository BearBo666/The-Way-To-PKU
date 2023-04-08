	.file	"func.cpp"
	.text
	.globl	_Z8testCallii
	.def	_Z8testCallii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8testCallii
_Z8testCallii:
.LFB1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	leaq	24(%rbp), %rax
	movq	%rax, %rdx
	leaq	16(%rbp), %rcx
	call	_Z3MaxIiERKT_S2_S2_
	movl	(%rax), %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3addii
	.def	_Z3addii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3addii
	; 重载格式 函数名 + 参数类型首字母 ii表示int、int
_Z3addii:
.LFB2:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3adddd
	.def	_Z3adddd;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3adddd
_Z3adddd:
.LFB3:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	16(%rbp), %xmm0
	addsd	24(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3addff
	.def	_Z3addff;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3addff
_Z3addff:
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	addss	24(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z12variableArgsii
	.def	_Z12variableArgsii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z12variableArgsii
_Z12variableArgsii:
.LFB5:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z16testVariableArgsv
	.def	_Z16testVariableArgsv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z16testVariableArgsv
_Z16testVariableArgsv:
.LFB6:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	; 传递5和10，缺省情况
	movl	$10, %edx
	movl	$5, %ecx
	call	_Z12variableArgsii
	movl	%eax, -4(%rbp)
	; 传递5和11，未缺省情况
	movl	$11, %edx
	movl	$5, %ecx
	call	_Z12variableArgsii
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3MaxIiERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_Z3MaxIiERKT_S2_S2_
	.def	_Z3MaxIiERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3MaxIiERKT_S2_S2_
_Z3MaxIiERKT_S2_S2_:
.LFB7:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L14
	movq	24(%rbp), %rax
	jmp	.L16
.L14:
	movq	16(%rbp), %rax
.L16:
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
