IF ~DEFINED _LINKED_QUEUE_H_
_LINKED_QUEUE_H_	EQU	1

LinkedQueue.isEmpty:
	mov	eax,	[esp+4]		; eax = this
	;test	eax,	eax
	; TODO: NullPointerException
	mov	eax,	[eax]		; eax = this->head
	test	eax,	eax
	jz	@F
	mov	eax,	1
@@:	retn	4

LinkedQueue.getSize:
	push	ebx		; ##
	push	ecx		; @@
; stack: |ecx |ebx |ret |this|
	mov	ecx,	[esp+12]	; ecx = this
	;test	ecx,	ecx
	; TODO: NullPointerException
	xor	eax,	eax	; eax = 0
	mov	ecx,	[ecx]	; ecx = this->head
	test	ecx,	ecx
	jz	.return		; jump if this == null
	mov	ebx,	ecx	; ebx = this->head
@@:	cmp	ebx,	[ecx]
	je	.return		; jump if ecx->next == head
	inc	eax
	mov	ecx,	[ecx]
	jmp	@B
.return:
	pop	ecx		; @@
	pop	ebx		; ##
	retn	4

END IF ; _LINKED_QUEUE_H_