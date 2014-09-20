_LINKED_LIST_2_NODE_H_	EQU	1

LinkedList2Node.getTail:
	;cmp	DWORD [esp+4],	0
	; TODO: NullPointerException
@@:	mov	eax,	[esp+4]			; eax = this
	cmp	DWORD [eax+LINKED_LIST_NEXT],	0
	je	@F				; jump if eax->next == null
	mov	eax,	[eax+LINKED_LIST_NEXT]	; eax = eax->next
	jmp	@B
@@:	retn	4

LinkedList2Node.getHead:
	;cmp	DWORD [esp+4],	0
	; TODO: NullPointerException
@@:	mov	eax,	[esp+4]			; eax = this
	cmp	DWORD [eax+LINKED_LIST_PREV],	0
	je	@F				; jump if eax->prev == null
	mov	eax,	[eax+LINKED_LIST_PREV]	; eax = eax->prev
	jmp	@B
@@:	retn	4

END IF ; _LINKED_LIST_2_NODE_H_