#include "Collection.cpp"

#ifndef _LINKED_LIST_2_NODE_H_
#define _LINKED_LIST_2_NODE_H_
template <typename T> class LinkedList2;
template <typename T> class LinkedListO2;
template <typename T> class LinkedQueue;

template <typename T> class LinkedList2Node{
protected:
	
	LinkedList2Node *next, *prev;
	
	T key;
	
	#define LinkedList2NullNode ((LinkedList2Node*)0)
	friend class LinkedList2<T>;
	friend class LinkedQueue<T>;
	
public:
	
	LinkedList2Node(T e){
		key = e;
		prev = next = LinkedList2NullNode;
	}
	
	LinkedList2Node(T e, LinkedList2Node *n, LinkedList2Node *p){
		key = e;
		next = n; prev = p;
		if(n != LinkedList2NullNode) n->prev = this;
		if(p != LinkedList2NullNode) p->next = this;
	}
	
	~LinkedList2Node(){
		if(getPrev() != LinkedList2NullNode) prev->next = next;
		if(getNext() != LinkedList2NullNode) next->prev = prev;
	}
	
	inline T getKey(){
		return key;
	}
	
	inline LinkedList2Node *getNext(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedList2NullNode) throw NullPointerException();
		#endif
		return next;
	}
	
	inline LinkedList2Node *getPrev(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedList2NullNode) throw NullPointerException();
		#endif
		return prev;
	}
	
	LinkedList2Node *getTail(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedList2NullNode) throw NullPointerException();
		#endif
		register LinkedList2Node *temp = this;
		while(temp->next != LinkedList2NullNode) temp = temp->next;
		return temp;
	}
	
	LinkedList2Node *getHead(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedList2NullNode) throw NullPointerException();
		#endif
		register LinkedList2Node *temp = this;
		while(temp->prev != LinkedList2NullNode) temp = temp->prev;
		return temp;
	}
	
}; // class LinkedList2Node<T>
#undef LinkedList2NullNode
#define LinkedList2NullNode ((LinkedList2Node<T>*)0)
#endif // _LINKED_LIST_2_NODE_H_
