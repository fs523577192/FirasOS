IF ~DEFINED _LINKED_LIST_NODE_H_
_LINKED_LIST_NODE_H_	EQU	1

LINKED_LIST_NEXT	EQU	0
LINKED_LIST_KEY		EQU	8

LinkedListNode.getTail:
	;test	rcx,	rcx
	; TODO: NullPointerException
	xor	rax,	rax			; rax = null
@@:	cmp	rax,	[rcx+LINKED_LIST_NEXT]
	je	@F				; jump if rcx->next == null
	mov	rcx,	[rcx+LINKED_LIST_NEXT]	; rcx = rcx->next
	jmp	@B
@@:	mov	rax,	rcx
	ret

END IF ; _LINKED_LIST_NODE_H_
