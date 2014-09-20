IF ~DEFINED _LINKED_STACK_H_
_LINKED_STACK_H_	EQU	1

LinkedStack.isEmpty:
	;cmp	DWORD [esp+4],	0
	; TODO: NullPointerException
	mov	eax,	DWORD [esp+4]
	mov	eax,	[eax]		; eax = this->top
	test	eax,	eax
	jz	@F
	mov	eax,	1
@@:	retn	4

LinkedStack.getSize:
	;cmp	DWORD [esp+4],	0
	; TODO: NullPointerException
	push	ebx			; ##
; stack: |ebx |ret |this|
	mov	ebx,	[esp+8]		; ebx = this
	xor	eax,	eax		; eax = 0
@@:	mov	ebx,	[ebx]		; first loop: ebx = top
					; other loop: ebx = ebx->next
	test	ebx,	ebx
	jz	@F
	inc	eax
	jmp	@B
@@:	pop	ebx			; ##
	retn	4

END IF ; _LINKED_STACK_H_