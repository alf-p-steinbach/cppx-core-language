	.file	"c-style-versus-range-based-with-Sequence.cpp"
	.intel_syntax noprefix
	.text
	.def	_ZL6printfPKcz;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZL6printfPKcz
_ZL6printfPKcz:
.LFB608:
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 56
	.seh_stackalloc	56
	.seh_endprologue
	mov	rbx, rcx
	mov	QWORD PTR 88[rsp], rdx
	mov	QWORD PTR 96[rsp], r8
	mov	QWORD PTR 104[rsp], r9
	lea	rsi, 88[rsp]
	mov	QWORD PTR 40[rsp], rsi
	mov	ecx, 1
	call	[QWORD PTR __imp___acrt_iob_func[rip]]
	mov	rcx, rax
	mov	r8, rsi
	mov	rdx, rbx
	call	__mingw_vfprintf
	add	rsp, 56
	pop	rbx
	pop	rsi
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
.LC1:
	.ascii "\12\0"
	.text
	.globl	_ZN8examples7c_styleEv
	.def	_ZN8examples7c_styleEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8examples7c_styleEv
_ZN8examples7c_styleEv:
.LFB4750:
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	mov	ebx, 100
	lea	rsi, .LC0[rip]
.L3:
	mov	edx, ebx
	mov	rcx, rsi
	call	_ZL6printfPKcz
	inc	ebx
	cmp	ebx, 110
	jne	.L3
	lea	rcx, .LC1[rip]
	call	_ZL6printfPKcz
	nop
	add	rsp, 40
	pop	rbx
	pop	rsi
	ret
	.seh_endproc
	.globl	_ZN8examples15cpp_range_basedEv
	.def	_ZN8examples15cpp_range_basedEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8examples15cpp_range_basedEv
_ZN8examples15cpp_range_basedEv:
.LFB4751:
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	mov	ebx, 200
	lea	rsi, .LC0[rip]
.L6:
	mov	edx, ebx
	mov	rcx, rsi
	call	_ZL6printfPKcz
	inc	ebx
	cmp	ebx, 210
	jne	.L6
	lea	rcx, .LC1[rip]
	call	_ZL6printfPKcz
	nop
	add	rsp, 40
	pop	rbx
	pop	rsi
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4753:
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	call	_ZN8examples7c_styleEv
	call	_ZN8examples15cpp_range_basedEv
	mov	eax, 0
	add	rsp, 40
	ret
	.seh_endproc
	.globl	_ZN4cppx9hex_stuff10hex_digitsE
	.section .rdata,"dr"
.LC2:
	.ascii "0123456789ABCDEF\0"
	.align 8
_ZN4cppx9hex_stuff10hex_digitsE:
	.quad	.LC2
	.globl	_ZN4cppx9hex_stuff20hex_digits_lowercaseE
.LC3:
	.ascii "0123456789abcdef\0"
	.align 8
_ZN4cppx9hex_stuff20hex_digits_lowercaseE:
	.quad	.LC3
	.globl	_ZN4cppx9hex_stuff20hex_digits_uppercaseE
	.align 8
_ZN4cppx9hex_stuff20hex_digits_uppercaseE:
	.quad	.LC2
	.ident	"GCC: (GNU) 9.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
