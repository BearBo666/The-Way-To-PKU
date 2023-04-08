; 文件头
	.file	"asm.c"
	; .text定义一个代码段，处理器开始执行代码的地方，代表后面是代码，这是GCC必须的；
	.text
	; 给代码开始地址定义个全局标记sum
	; 必须定义成全局的，以便存在于编译后的全局符合表中，供其它程序【如加载器】寻找到。
	.globl	sum
	.def	sum;	.scl	2;	.type	32;	.endef
	.seh_proc	sum
; 对这个文件来说sum的caller为函数function
sum:
	; 将caller的栈基入栈
	pushq	%rbp
	.seh_pushreg	%rbp
	; 将caller的栈顶作为sum的栈底
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	; 此刻栈顶指向caller的栈顶，由于栈是从高地址向低地址增长的
	; 所以，所以此刻拿栈底高16位、高24位数据送往ecx和edx，即取参数
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	; 执行加法过程
	addl	%edx, %eax
	; 恢复caller栈
	popq	%rbp
	; 调用返回
	ret
	.seh_endproc
	.globl	function
	.def	function;	.scl	2;	.type	32;	.endef
	.seh_proc	function
function:
	; 保存调用者栈底
	pushq	%rbp
	; seh开头：结构化异常相关，win下才有，可忽略
	.seh_pushreg	%rbp
	; 将调用者的栈顶作为自己的栈底
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	; 栈顶此刻仍为调用者的栈顶，减48，即将栈扩容48，即给函数分配栈帧
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	; 将两个立即数送入栈中，-4说明一个参数占四个栈元素单元
	; 一个int占4B，说明一个栈元素4B
	movl	$100, -4(%rbp)
	movl	$200, -8(%rbp)
	; 将栈内内容送往寄存器，为什么不能直接将立即数写寄存器？
	; 因为栈中内容是函数自己的空间，寄存器中的内容是被调用者空间，不一样
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	sum
	; 空操作，什么目的？流水线相关优化？
	nop
	; 栈顶加48，即栈大小减48，销毁栈帧
	addq	$48, %rsp
	; 调用者返回
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
