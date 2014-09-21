IF ~DEFINED _LINKED_QUEUE_H_
_LINKED_QUEUE_H_	EQU	1

LinkedQueue.isEmpty:
	;test	rcx,	rcx
	; TODO: NullPointerException
	mov	rax,	[rcx]
	test	rax,	rax
	jz	@F
	mov	rax,	1
@@:	ret

LinkedQueue.getSize:
	;test	rcx,	rcx
	; TODO: NullPointerException
	xor	rax,	rax	; rax = 0
	mov	rcx,	[rcx]	; rcx = head
	test	rcx,	rcx
	jz	.return		; jump if head == null
	push	rbx		; ##
	mov	rbx,	rcx	; rbx = head
@@:	cmp	rbx,	[rcx]
	je	@F		; jump if rcx->next == head
	inc	rax
	mov	rcx,	[rcx]
	jmp	@B
@@:	pop	rbx		; ##
.return:
	ret

END IF ; _LINKED_QUEUE_H_