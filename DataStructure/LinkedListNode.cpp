#ifndef _LINKED_LIST_NODE_H_
#define _LINKED_LIST_NODE_H_
#include "Collection.cpp"
template <typename T> class LinkedList;
template <typename T> class LinkedListO;
template <typename T> class LinkedStack;

template <typename T> class LinkedListNode{
protected:
	LinkedListNode *next;
	T key;
	
	friend class LinkedList<T>;
	friend class LinkedListO<T>;
	friend class LinkedStack<T>;
	
public:
	#define LinkedListNullNode ((LinkedListNode*)0)
	LinkedListNode(T k){
		key = k;
		next = LinkedListNullNode;
	}
	LinkedListNode(T k, LinkedListNode* n){
		key = k;
		next = n;
	}

	inline T getKey(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedListNullNode) throw NullPointerException();
		#endif
		return key;
	}
	inline LinkedListNode *getNext(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedListNullNode) throw NullPointerException();
		#endif
		return next;
	}
	LinkedListNode *getTail(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedListNullNode) throw NullPointerException();
		#endif
		register LinkedListNode *temp = this;
		while(temp->next != LinkedListNullNode) temp = temp->next;
		return temp;
	}
}; // class LinkedListNode<T>
#undef LinkedListNullNode
#define LinkedListNullNode ((LinkedListNode<T>*)0)
#endif // _LINKED_LIST_NODE_H_
