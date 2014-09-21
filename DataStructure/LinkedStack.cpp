#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_
#include "LinkedListNode.cpp"

template <typename T> class LinkedStack : public Stack<T>{
private:
	LinkedListNode<T> *top;
public:
	
	LinkedStack(){
		top = (LinkedListNode<T>*)0;
	}
	
	LinkedStack(T e){
		top = new LinkedListNode<T>(e);
	}
	
	~LinkedStack(){
		removeAllElement();
	}
	
	bool isEmpty(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedStack*)0) throw NullPointerException();
		#endif
		return top == (LinkedListNode<T>*)0;
	}
	
	unsigned getSize(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedStack*)0) throw NullPointerException();
		#endif
		if(isEmpty()) return 0;
		register unsigned size = 1;
		register LinkedListNode<T> *temp = top;
		while(temp->getNext() != (LinkedListNode<T>*)0){
			size++;
			temp = temp->getNext();
		}
		return size;
	}
	
	bool addElement(T e){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedStack*)0) throw NullPointerException();
		#endif
		top = new LinkedListNode<T>(e, top);
		return true;
	}
	
	bool removeElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		if(top->getKey()==e){
			popElement();
			return true;
		}
		LinkedListNode<T> *temp1 = top, *temp2 = top->getNext();
		while(temp2 != (LinkedListNode<T>*)0){
			if(temp2->getKey()==e){
				temp1->next = temp2->getNext();
				delete temp2;
				return true;
			}
			temp1 = temp2;
			temp2 = temp2->getNext();
		}
		return false;
	}
	
	bool removeAllElement(){	// inherited from Collection
		if(isEmpty()) return false;
		while(top != (LinkedListNode<T>*)0){
			LinkedListNode<T> *temp = top;
			top = top->getNext();
			delete temp;
		}
		return true;
	}
	
	bool hasElement(T e){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedStack*)0) throw NullPointerException();
		#endif
		for(register LinkedListNode<T> *temp = top; temp != (LinkedListNode<T>*)0;
			temp = temp->getNext()) if(temp->getKey()==e) return true;
		return false;
	}
	
	bool pushElement(T e){	// inherited from Stack
		return addElement(e);
	}
	
	T popElement(){	// inherited from Stack
	#ifdef _EXCEPTION_H_
		if(this == (LinkedStack*)0 || top == (LinkedListNode<T>*)0)
			throw NullPointerException();
	#endif
		T k = top->getKey();
		LinkedListNode<T> *temp = top;
		top = top->getNext();
		delete temp;
		return k;
	}
	
}; // class LinkedStack<T>
#endif // _LINKED_STACK_H_