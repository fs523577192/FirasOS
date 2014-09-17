#include "LinkedListNode.cpp"

#ifndef _LINKED_LIST_2_NODE_H_
#define _LINKED_LIST_2_NODE_H_
template <typename T> class LinkedList2;
template <typename T> class LinkedListO2;
template <typename T> class LinkedQueue;

template <typename T> class LinkedList2Node : public LinkedListNode<T>{
protected:
	LinkedList2Node *prev;
	#define LinkedList2NullNode ((LinkedList2Node*)0)
	friend class LinkedList2<T>;
	friend class LinkedListO2<T>;
	friend class LinkedQueue<T>;
	
public:
	
	LinkedList2Node(T e) : LinkedListNode<T>(e){
		prev = LinkedList2NullNode;
	}
	
	LinkedList2Node(T e, LinkedList2Node *n, LinkedList2Node *p) :
			LinkedListNode<T>(e, n){
		prev = n;
		if(n != LinkedList2NullNode) n->prev = this;
		if(p != LinkedList2NullNode) p->next = this;
	}
	
	~LinkedList2Node(){
		if(getPrev() != LinkedList2NullNode) getPrev()->next = getNext();
		if(getNext() != LinkedList2NullNode) getNext()->prev = getPrev();
	}
	
	inline LinkedList2Node *getNext(){
		return dynamic_cast<LinkedList2Node*>(this->next);
	}
	
	inline LinkedList2Node *getPrev(){
		#ifdef _EXCEPTION_H_
		if(this == LinkedList2NullNode) throw NullPointerException();
		#endif
		return prev;
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
