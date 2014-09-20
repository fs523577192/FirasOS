IF ~DEFINED _LINKED_LIST_2_NODE_H_
_LINKED_LIST_2_NODE_H_	EQU	1

LINKED_LIST_NEXT	EQU	8
LINKED_LIST_PREV	EQU	16
LINKED_LIST_KEY		EQU	24

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

LinkedList2Node.getHead:
	;test	rcx,	rcx
	; TODO: NullPointerException
	xor	rax,	rax			; rax = null
@@:	cmp	rax,	[rcx+LINKED_LIST_PREV]
	je	@F				; jump if rcx->prev == null
	mov	rcx,	[rcx+LINKED_LIST_PREV]	; rcx = rcx->prev
	jmp	@B
@@:	mov	rax,	rcx
	ret

END IF ; _LINKED_LIST_2_NODE_H_