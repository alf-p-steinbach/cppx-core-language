; Listing generated by Microsoft (R) Optimizing Compiler Version 19.24.28314.0 

include listing.inc

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	??_C@_0BB@JGGOGLEG@0123456789ABCDEF@		; `string'
PUBLIC	??_C@_0BB@JCEFLFJE@0123456789abcdef@		; `string'
;	COMDAT ??_C@_0BB@JCEFLFJE@0123456789abcdef@
CONST	SEGMENT
??_C@_0BB@JCEFLFJE@0123456789abcdef@ DB '0123456789abcdef', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@JGGOGLEG@0123456789ABCDEF@
CONST	SEGMENT
??_C@_0BB@JGGOGLEG@0123456789ABCDEF@ DB '0123456789ABCDEF', 00H ; `string'
CONST	ENDS
PUBLIC	__local_stdio_printf_options
PUBLIC	_vfprintf_l
PUBLIC	printf
PUBLIC	??0id@locale@std@@QEAA@_K@Z			; std::locale::id::id
PUBLIC	??$?B_NX@Truth@cppx@@QEBA_NXZ			; cppx::Truth::operator<bool,void> bool
PUBLIC	??$?0_NX@Truth@cppx@@QEAA@_N@Z			; cppx::Truth::Truth<bool,void>
PUBLIC	?begin@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ ; cppx::_::Sequence_<int,void>::begin
PUBLIC	?end@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ ; cppx::_::Sequence_<int,void>::end
PUBLIC	??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z		; cppx::_::Sequence_<int,void>::Sequence_<int,void>
PUBLIC	?c_style@examples@@YAXXZ			; examples::c_style
PUBLIC	?cpp_range_based@examples@@YAXXZ		; examples::cpp_range_based
PUBLIC	??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z	; cppx::_::zero_to<int>
PUBLIC	?self@?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@AEAAAEAVIterator@?$Sequence_@HX@23@XZ ; cppx::_::Adapt_as_forward_iterator_<cppx::_::Sequence_<int,void>::Iterator,int>::self
PUBLIC	??E?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@QEAAAEBVIterator@?$Sequence_@HX@12@XZ ; cppx::_::Adapt_as_forward_iterator_<cppx::_::Sequence_<int,void>::Iterator,int>::operator++
PUBLIC	??9_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z ; cppx::_::operator!=
PUBLIC	?advance@Iterator@?$Sequence_@HX@_@cppx@@QEAAXXZ ; cppx::_::Sequence_<int,void>::Iterator::advance
PUBLIC	??DIterator@?$Sequence_@HX@_@cppx@@QEBAHXZ	; cppx::_::Sequence_<int,void>::Iterator::operator*
PUBLIC	??8_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z ; cppx::_::operator==
PUBLIC	??0Iterator@?$Sequence_@HX@_@cppx@@QEAA@H@Z	; cppx::_::Sequence_<int,void>::Iterator::Iterator
PUBLIC	main
PUBLIC	?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA ; `__local_stdio_printf_options'::`2'::_OptionsStorage
PUBLIC	??_C@_03JDANDILB@?$CFd?5@			; `string'
PUBLIC	??_C@_01EEMJAFIK@?6@				; `string'
PUBLIC	??_C@_1IA@HMBNHAID@?$AAc?$AA?3?$AA?2?$AAm?$AAy?$AA?2?$AAd?$AAe?$AAv?$AA?2?$AAi?$AAn?$AAc?$AAl?$AAu@ ; `string'
PUBLIC	??_C@_1KK@HNBJPIME@?$AAf?$AAi?$AAr?$AAs?$AAt?$AA?5?$AA?$DM?$AA?$DN?$AA?5?$AAl?$AAa?$AAs?$AAt?$AA?5?$AAo@ ; `string'
PUBLIC	?id@?$num_put@DV?$ostreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@2V0locale@2@A ; std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char> > >::id
PUBLIC	?id@?$numpunct@D@std@@2V0locale@2@A		; std::numpunct<char>::id
EXTRN	__acrt_iob_func:PROC
EXTRN	__stdio_common_vfprintf:PROC
EXTRN	_wassert:PROC
;	COMDAT ?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA
_BSS	SEGMENT
?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA DQ 01H DUP (?) ; `__local_stdio_printf_options'::`2'::_OptionsStorage
_BSS	ENDS
;	COMDAT ?id@?$num_put@DV?$ostreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@2V0locale@2@A
_BSS	SEGMENT
?id@?$num_put@DV?$ostreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@2V0locale@2@A DQ 01H DUP (?) ; std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char> > >::id
_BSS	ENDS
;	COMDAT ?id@?$numpunct@D@std@@2V0locale@2@A
_BSS	SEGMENT
?id@?$numpunct@D@std@@2V0locale@2@A DQ 01H DUP (?)	; std::numpunct<char>::id
_BSS	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$_vfprintf_l DD imagerel $LN4
	DD	imagerel $LN4+80
	DD	imagerel $unwind$_vfprintf_l
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$printf DD imagerel $LN6
	DD	imagerel $LN6+78
	DD	imagerel $unwind$printf
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z DD imagerel $LN6
	DD	imagerel $LN6+62
	DD	imagerel $unwind$??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?c_style@examples@@YAXXZ DD imagerel $LN11
	DD	imagerel $LN11+47
	DD	imagerel $unwind$?c_style@examples@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?cpp_range_based@examples@@YAXXZ DD imagerel $LN37
	DD	imagerel $LN37+50
	DD	imagerel $unwind$?cpp_range_based@examples@@YAXXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z DD imagerel $LN8
	DD	imagerel $LN8+60
	DD	imagerel $unwind$??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$main DD	imagerel $LN4
	DD	imagerel $LN4+21
	DD	imagerel $unwind$main
pdata	ENDS
;	COMDAT ??_C@_1KK@HNBJPIME@?$AAf?$AAi?$AAr?$AAs?$AAt?$AA?5?$AA?$DM?$AA?$DN?$AA?5?$AAl?$AAa?$AAs?$AAt?$AA?5?$AAo@
CONST	SEGMENT
??_C@_1KK@HNBJPIME@?$AAf?$AAi?$AAr?$AAs?$AAt?$AA?5?$AA?$DM?$AA?$DN?$AA?5?$AAl?$AAa?$AAs?$AAt?$AA?5?$AAo@ DB 'f'
	DB	00H, 'i', 00H, 'r', 00H, 's', 00H, 't', 00H, ' ', 00H, '<', 00H
	DB	'=', 00H, ' ', 00H, 'l', 00H, 'a', 00H, 's', 00H, 't', 00H, ' '
	DB	00H, 'o', 00H, 'r', 00H, ' ', 00H, 's', 00H, 't', 00H, 'a', 00H
	DB	't', 00H, 'i', 00H, 'c', 00H, '_', 00H, 'c', 00H, 'a', 00H, 's'
	DB	00H, 't', 00H, '<', 00H, 'U', 00H, 'n', 00H, 's', 00H, 'i', 00H
	DB	'g', 00H, 'n', 00H, 'e', 00H, 'd', 00H, '>', 00H, '(', 00H, ' '
	DB	00H, 'f', 00H, 'i', 00H, 'r', 00H, 's', 00H, 't', 00H, ' ', 00H
	DB	')', 00H, ' ', 00H, '=', 00H, '=', 00H, ' ', 00H, 's', 00H, 't'
	DB	00H, 'a', 00H, 't', 00H, 'i', 00H, 'c', 00H, '_', 00H, 'c', 00H
	DB	'a', 00H, 's', 00H, 't', 00H, '<', 00H, 'U', 00H, 'n', 00H, 's'
	DB	00H, 'i', 00H, 'g', 00H, 'n', 00H, 'e', 00H, 'd', 00H, '>', 00H
	DB	'(', 00H, ' ', 00H, 'l', 00H, 'a', 00H, 's', 00H, 't', 00H, ' '
	DB	00H, ')', 00H, ' ', 00H, '+', 00H, ' ', 00H, '1', 00H, 00H, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_1IA@HMBNHAID@?$AAc?$AA?3?$AA?2?$AAm?$AAy?$AA?2?$AAd?$AAe?$AAv?$AA?2?$AAi?$AAn?$AAc?$AAl?$AAu@
CONST	SEGMENT
??_C@_1IA@HMBNHAID@?$AAc?$AA?3?$AA?2?$AAm?$AAy?$AA?2?$AAd?$AAe?$AAv?$AA?2?$AAi?$AAn?$AAc?$AAl?$AAu@ DB 'c'
	DB	00H, ':', 00H, '\', 00H, 'm', 00H, 'y', 00H, '\', 00H, 'd', 00H
	DB	'e', 00H, 'v', 00H, '\', 00H, 'i', 00H, 'n', 00H, 'c', 00H, 'l'
	DB	00H, 'u', 00H, 'd', 00H, 'e', 00H, '\', 00H, 'c', 00H, 'p', 00H
	DB	'p', 00H, 'x', 00H, '-', 00H, 'c', 00H, 'o', 00H, 'r', 00H, 'e'
	DB	00H, '-', 00H, 'l', 00H, 'a', 00H, 'n', 00H, 'g', 00H, 'u', 00H
	DB	'a', 00H, 'g', 00H, 'e', 00H, '/', 00H, 's', 00H, 'y', 00H, 'n'
	DB	00H, 't', 00H, 'a', 00H, 'x', 00H, '/', 00H, 't', 00H, 'y', 00H
	DB	'p', 00H, 'e', 00H, 's', 00H, '/', 00H, 'S', 00H, 'e', 00H, 'q'
	DB	00H, 'u', 00H, 'e', 00H, 'n', 00H, 'c', 00H, 'e', 00H, '_', 00H
	DB	'.', 00H, 'h', 00H, 'p', 00H, 'p', 00H, 00H, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_01EEMJAFIK@?6@
CONST	SEGMENT
??_C@_01EEMJAFIK@?6@ DB 0aH, 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_03JDANDILB@?$CFd?5@
CONST	SEGMENT
??_C@_03JDANDILB@?$CFd?5@ DB '%d ', 00H			; `string'
CONST	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$main DD	010401H
	DD	04204H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z DD 020601H
	DD	030023206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?cpp_range_based@examples@@YAXXZ DD 020601H
	DD	030023206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?c_style@examples@@YAXXZ DD 020601H
	DD	030023206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z DD 020601H
	DD	030023206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$printf DD 031901H
	DD	070156219H
	DD	03014H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$_vfprintf_l DD 081401H
	DD	0a6414H
	DD	095414H
	DD	083414H
	DD	070105214H
xdata	ENDS
; Function compile flags: /Ogspy
;	COMDAT main
_TEXT	SEGMENT
main	PROC						; COMDAT
; File C:\my\dev\libraries\cppx-core-language\examples\syntax\c-style-versus-range-based-with-Sequence.cpp
; Line 26
$LN4:
	sub	rsp, 40					; 00000028H
; Line 27
	call	?c_style@examples@@YAXXZ		; examples::c_style
; Line 28
	call	?cpp_range_based@examples@@YAXXZ	; examples::cpp_range_based
; Line 29
	xor	eax, eax
	add	rsp, 40					; 00000028H
	ret	0
main	ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??0Iterator@?$Sequence_@HX@_@cppx@@QEAA@H@Z
_TEXT	SEGMENT
this$ = 8
value$ = 16
??0Iterator@?$Sequence_@HX@_@cppx@@QEAA@H@Z PROC	; cppx::_::Sequence_<int,void>::Iterator::Iterator, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 41
	mov	DWORD PTR [rcx], edx
; Line 42
	mov	rax, rcx
	ret	0
??0Iterator@?$Sequence_@HX@_@cppx@@QEAA@H@Z ENDP	; cppx::_::Sequence_<int,void>::Iterator::Iterator
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??8_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z
_TEXT	SEGMENT
__$ReturnUdt$ = 8
a$ = 16
b$ = 24
??8_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z PROC ; cppx::_::operator==, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 38
	mov	eax, DWORD PTR [r8]
	cmp	DWORD PTR [rdx], eax
	sete	al
; File c:\my\dev\include\cppx-core-language\types\Truth.hpp
; Line 68
	mov	BYTE PTR [rcx], al
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 38
	mov	rax, rcx
	ret	0
??8_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z ENDP ; cppx::_::operator==
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??DIterator@?$Sequence_@HX@_@cppx@@QEBAHXZ
_TEXT	SEGMENT
this$ = 8
??DIterator@?$Sequence_@HX@_@cppx@@QEBAHXZ PROC		; cppx::_::Sequence_<int,void>::Iterator::operator*, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 34
	mov	eax, DWORD PTR [rcx]
	ret	0
??DIterator@?$Sequence_@HX@_@cppx@@QEBAHXZ ENDP		; cppx::_::Sequence_<int,void>::Iterator::operator*
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ?advance@Iterator@?$Sequence_@HX@_@cppx@@QEAAXXZ
_TEXT	SEGMENT
this$ = 8
?advance@Iterator@?$Sequence_@HX@_@cppx@@QEAAXXZ PROC	; cppx::_::Sequence_<int,void>::Iterator::advance, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 30
	inc	DWORD PTR [rcx]
	ret	0
?advance@Iterator@?$Sequence_@HX@_@cppx@@QEAAXXZ ENDP	; cppx::_::Sequence_<int,void>::Iterator::advance
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??9_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z
_TEXT	SEGMENT
__$ReturnUdt$ = 8
a$ = 16
b$ = 24
??9_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z PROC ; cppx::_::operator!=, COMDAT
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; File c:\my\dev\include\cppx-core-language\types\Truth.hpp
; Line 68
	mov	eax, DWORD PTR [r8]
	cmp	DWORD PTR [rdx], eax
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; Line 70
	setne	al
; File c:\my\dev\include\cppx-core-language\types\Truth.hpp
; Line 68
	mov	BYTE PTR [rcx], al
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; Line 70
	mov	rax, rcx
	ret	0
??9_@cppx@@YA?AVTruth@1@AEBVIterator@?$Sequence_@HX@01@0@Z ENDP ; cppx::_::operator!=
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??E?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@QEAAAEBVIterator@?$Sequence_@HX@12@XZ
_TEXT	SEGMENT
this$ = 8
??E?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@QEAAAEBVIterator@?$Sequence_@HX@12@XZ PROC ; cppx::_::Adapt_as_forward_iterator_<cppx::_::Sequence_<int,void>::Iterator,int>::operator++, COMDAT
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 30
	inc	DWORD PTR [rcx]
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; Line 57
	mov	rax, rcx
; Line 58
	ret	0
??E?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@QEAAAEBVIterator@?$Sequence_@HX@12@XZ ENDP ; cppx::_::Adapt_as_forward_iterator_<cppx::_::Sequence_<int,void>::Iterator,int>::operator++
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ?self@?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@AEAAAEAVIterator@?$Sequence_@HX@23@XZ
_TEXT	SEGMENT
this$ = 8
?self@?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@AEAAAEAVIterator@?$Sequence_@HX@23@XZ PROC ; cppx::_::Adapt_as_forward_iterator_<cppx::_::Sequence_<int,void>::Iterator,int>::self, COMDAT
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; Line 41
	mov	rax, rcx
	ret	0
?self@?$Adapt_as_forward_iterator_@VIterator@?$Sequence_@HX@_@cppx@@H@_@cppx@@AEAAAEAVIterator@?$Sequence_@HX@23@XZ ENDP ; cppx::_::Adapt_as_forward_iterator_<cppx::_::Sequence_<int,void>::Iterator,int>::self
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z
_TEXT	SEGMENT
__$ReturnUdt$ = 48
n$ = 56
??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z PROC	; cppx::_::zero_to<int>, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 101
$LN8:
	push	rbx
	sub	rsp, 32					; 00000020H
; Line 86
	and	DWORD PTR [rcx], 0
; Line 101
	lea	eax, DWORD PTR [rdx-1]
; Line 87
	mov	DWORD PTR [rcx+4], eax
; Line 101
	mov	rbx, rcx
; Line 89
	test	eax, eax
	jns	SHORT $LN5@zero_to
	test	edx, edx
	je	SHORT $LN5@zero_to
	mov	r8d, 92					; 0000005cH
	lea	rdx, OFFSET FLAT:??_C@_1IA@HMBNHAID@?$AAc?$AA?3?$AA?2?$AAm?$AAy?$AA?2?$AAd?$AAe?$AAv?$AA?2?$AAi?$AAn?$AAc?$AAl?$AAu@
	lea	rcx, OFFSET FLAT:??_C@_1KK@HNBJPIME@?$AAf?$AAi?$AAr?$AAs?$AAt?$AA?5?$AA?$DM?$AA?$DN?$AA?5?$AAl?$AAa?$AAs?$AAt?$AA?5?$AAo@
	call	_wassert
$LN5@zero_to:
; Line 101
	mov	rax, rbx
	add	rsp, 32					; 00000020H
	pop	rbx
	ret	0
??$zero_to@H@_@cppx@@YA?AV?$Sequence_@HX@01@H@Z ENDP	; cppx::_::zero_to<int>
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ?cpp_range_based@examples@@YAXXZ
_TEXT	SEGMENT
?cpp_range_based@examples@@YAXXZ PROC			; examples::cpp_range_based, COMDAT
; File C:\my\dev\libraries\cppx-core-language\examples\syntax\c-style-versus-range-based-with-Sequence.cpp
; Line 16
$LN37:
	push	rbx
	sub	rsp, 32					; 00000020H
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 41
	xor	ebx, ebx
$LL4@cpp_range_:
; File C:\my\dev\libraries\cppx-core-language\examples\syntax\c-style-versus-range-based-with-Sequence.cpp
; Line 18
	lea	edx, DWORD PTR [rbx+200]
	lea	rcx, OFFSET FLAT:??_C@_03JDANDILB@?$CFd?5@
	call	printf
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 30
	inc	ebx
; File c:\my\dev\include\cppx-core-language\mix-in\Adapt_as_forward_iterator_.hpp
; Line 70
	cmp	ebx, 10
; File C:\my\dev\libraries\cppx-core-language\examples\syntax\c-style-versus-range-based-with-Sequence.cpp
; Line 17
	jne	SHORT $LL4@cpp_range_
; Line 20
	lea	rcx, OFFSET FLAT:??_C@_01EEMJAFIK@?6@
; Line 21
	add	rsp, 32					; 00000020H
	pop	rbx
; Line 20
	jmp	printf
?cpp_range_based@examples@@YAXXZ ENDP			; examples::cpp_range_based
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ?c_style@examples@@YAXXZ
_TEXT	SEGMENT
?c_style@examples@@YAXXZ PROC				; examples::c_style, COMDAT
; File C:\my\dev\libraries\cppx-core-language\examples\syntax\c-style-versus-range-based-with-Sequence.cpp
; Line 8
$LN11:
	push	rbx
	sub	rsp, 32					; 00000020H
; Line 9
	xor	ebx, ebx
$LL4@c_style:
; Line 10
	lea	edx, DWORD PTR [rbx+100]
	lea	rcx, OFFSET FLAT:??_C@_03JDANDILB@?$CFd?5@
	call	printf
	inc	ebx
	cmp	ebx, 10
	jl	SHORT $LL4@c_style
; Line 12
	lea	rcx, OFFSET FLAT:??_C@_01EEMJAFIK@?6@
; Line 13
	add	rsp, 32					; 00000020H
	pop	rbx
; Line 12
	jmp	printf
?c_style@examples@@YAXXZ ENDP				; examples::c_style
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z
_TEXT	SEGMENT
this$ = 48
first$ = 56
last$ = 64
??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z PROC		; cppx::_::Sequence_<int,void>::Sequence_<int,void>, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 88
$LN6:
	push	rbx
	sub	rsp, 32					; 00000020H
; Line 86
	mov	DWORD PTR [rcx], edx
	mov	rbx, rcx
; Line 87
	mov	DWORD PTR [rcx+4], r8d
; Line 89
	cmp	edx, r8d
	jle	SHORT $LN3@Sequence_
	lea	eax, DWORD PTR [r8+1]
	cmp	edx, eax
	je	SHORT $LN3@Sequence_
	mov	r8d, 92					; 0000005cH
	lea	rdx, OFFSET FLAT:??_C@_1IA@HMBNHAID@?$AAc?$AA?3?$AA?2?$AAm?$AAy?$AA?2?$AAd?$AAe?$AAv?$AA?2?$AAi?$AAn?$AAc?$AAl?$AAu@
	lea	rcx, OFFSET FLAT:??_C@_1KK@HNBJPIME@?$AAf?$AAi?$AAr?$AAs?$AAt?$AA?5?$AA?$DM?$AA?$DN?$AA?5?$AAl?$AAa?$AAs?$AAt?$AA?5?$AAo@
	call	_wassert
$LN3@Sequence_:
; Line 93
	mov	rax, rbx
	add	rsp, 32					; 00000020H
	pop	rbx
	ret	0
??0?$Sequence_@HX@_@cppx@@QEAA@HH@Z ENDP		; cppx::_::Sequence_<int,void>::Sequence_<int,void>
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ?end@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ
_TEXT	SEGMENT
this$ = 8
__$ReturnUdt$ = 16
?end@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ PROC	; cppx::_::Sequence_<int,void>::end, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 83
	mov	eax, DWORD PTR [rcx+4]
	inc	eax
; Line 41
	mov	DWORD PTR [rdx], eax
; Line 83
	mov	rax, rdx
	ret	0
?end@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ ENDP	; cppx::_::Sequence_<int,void>::end
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ?begin@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ
_TEXT	SEGMENT
this$ = 8
__$ReturnUdt$ = 16
?begin@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ PROC ; cppx::_::Sequence_<int,void>::begin, COMDAT
; File c:\my\dev\include\cppx-core-language\syntax\types\Sequence_.hpp
; Line 41
	mov	eax, DWORD PTR [rcx]
	mov	DWORD PTR [rdx], eax
; Line 82
	mov	rax, rdx
	ret	0
?begin@?$Sequence_@HX@_@cppx@@QEBA?AVIterator@123@XZ ENDP ; cppx::_::Sequence_<int,void>::begin
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??$?0_NX@Truth@cppx@@QEAA@_N@Z
_TEXT	SEGMENT
this$ = 8
value$ = 16
??$?0_NX@Truth@cppx@@QEAA@_N@Z PROC			; cppx::Truth::Truth<bool,void>, COMDAT
; File c:\my\dev\include\cppx-core-language\types\Truth.hpp
; Line 68
	mov	BYTE PTR [rcx], dl
	mov	rax, rcx
	ret	0
??$?0_NX@Truth@cppx@@QEAA@_N@Z ENDP			; cppx::Truth::Truth<bool,void>
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??$?B_NX@Truth@cppx@@QEBA_NXZ
_TEXT	SEGMENT
this$ = 8
??$?B_NX@Truth@cppx@@QEBA_NXZ PROC			; cppx::Truth::operator<bool,void> bool, COMDAT
; File c:\my\dev\include\cppx-core-language\types\Truth.hpp
; Line 59
	mov	al, BYTE PTR [rcx]
	ret	0
??$?B_NX@Truth@cppx@@QEBA_NXZ ENDP			; cppx::Truth::operator<bool,void> bool
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT ??0id@locale@std@@QEAA@_K@Z
_TEXT	SEGMENT
this$ = 8
_Val$ = 16
??0id@locale@std@@QEAA@_K@Z PROC			; std::locale::id::id, COMDAT
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\include\xlocale
; Line 100
	mov	QWORD PTR [rcx], rdx
	mov	rax, rcx
	ret	0
??0id@locale@std@@QEAA@_K@Z ENDP			; std::locale::id::id
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT printf
_TEXT	SEGMENT
_Format$ = 80
printf	PROC						; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.17763.0\ucrt\stdio.h
; Line 954
$LN6:
	mov	rax, rsp
	mov	QWORD PTR [rax+8], rcx
	mov	QWORD PTR [rax+16], rdx
	mov	QWORD PTR [rax+24], r8
	mov	QWORD PTR [rax+32], r9
	push	rbx
	push	rdi
	sub	rsp, 56					; 00000038H
; Line 958
	mov	ecx, 1
	lea	rdi, QWORD PTR [rax+16]
	call	__acrt_iob_func
	mov	rbx, rax
; Line 643
	call	__local_stdio_printf_options
	mov	r8, QWORD PTR _Format$[rsp]
	xor	r9d, r9d
	mov	rdx, rbx
	mov	QWORD PTR [rsp+32], rdi
	mov	rcx, QWORD PTR [rax]
	call	__stdio_common_vfprintf
; Line 961
	add	rsp, 56					; 00000038H
	pop	rdi
	pop	rbx
	ret	0
printf	ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT _vfprintf_l
_TEXT	SEGMENT
_Stream$ = 64
_Format$ = 72
_Locale$ = 80
_ArgList$ = 88
_vfprintf_l PROC					; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.17763.0\ucrt\stdio.h
; Line 642
$LN4:
	mov	QWORD PTR [rsp+8], rbx
	mov	QWORD PTR [rsp+16], rbp
	mov	QWORD PTR [rsp+24], rsi
	push	rdi
	sub	rsp, 48					; 00000030H
	mov	rbx, r9
	mov	rdi, r8
	mov	rsi, rdx
	mov	rbp, rcx
; Line 643
	call	__local_stdio_printf_options
	mov	r9, rdi
	mov	QWORD PTR [rsp+32], rbx
	mov	r8, rsi
	mov	rdx, rbp
	mov	rcx, QWORD PTR [rax]
	call	__stdio_common_vfprintf
; Line 644
	mov	rbx, QWORD PTR [rsp+64]
	mov	rbp, QWORD PTR [rsp+72]
	mov	rsi, QWORD PTR [rsp+80]
	add	rsp, 48					; 00000030H
	pop	rdi
	ret	0
_vfprintf_l ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
;	COMDAT __local_stdio_printf_options
_TEXT	SEGMENT
__local_stdio_printf_options PROC			; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.17763.0\ucrt\corecrt_stdio_config.h
; Line 88
	lea	rax, OFFSET FLAT:?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA ; `__local_stdio_printf_options'::`2'::_OptionsStorage
; Line 89
	ret	0
__local_stdio_printf_options ENDP
_TEXT	ENDS
END
