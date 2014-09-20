IF ~DEFINED _LINKED_LIST_NODE_H_
_LINKED_LIST_NODE_H_	EQU	1

LINKED_LIST_NEXT	EQU	0
LINKED_LIST_KEY		EQU	4

LinkedListNode.getTail:
	;cmp	DWORD [esp+4],	0
	; TODO: NullPointerException
@@:	mov	eax,	[esp+4]			; eax = this
	cmp	DWORD [eax+LINKED_LIST_NEXT],	0
	je	@F				; jump if eax->next == null
	mov	eax,	[eax+LINKED_LIST_NEXT]	; eax = eax->next
	jmp	@B
@@:	retn	4

END IF ; _LINKED_LIST_NODE_H_