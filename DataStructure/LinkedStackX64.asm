IF ~DEFINED _LINKED_STACK_H_
_LINKED_STACK_H_	EQU	1

LinkedStack.isEmpty:
	;test	rcx,	rcx
	; TODO: NullPointerException
	mov	rax,	[rcx]		; rax = this->top
	test	rax,	rax
	jz	@F
	mov	rax,	1
@@:	ret

LinkedStack.getSize:
	;test	rcx,	rcx
	; TODO: NullPointerException
	xor	rax,	rax		; rax = 0
@@:	mov	rcx,	[rcx]		; first loop: rcx = top
					; other loop: rcx = rcx->next
	test	rcx,	rcx
	jz	@F
	inc	rax
	jmp	@B
@@:	ret

END IF ; _LINKED_STACK_H_