#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_
#include "LinkedList2Node.cpp"

template <typename T> class LinkedQueue : public Queue<T> {
private:
	LinkedList2Node<T> *head;

public:
	
	LinkedQueue(){
		head = (LinkedList2Node<T>*)0;
	}
	
	LinkedQueue(T k){
		head = new LinkedList2Node<T>(k);
		head->next = head->prev = head;
	}
	
	~LinkedQueue(){
		removeAllElement();
	}
	
	inline bool isEmpty(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedQueue*)0) throw NullPointerException();
		#endif
		return head == (LinkedList2Node<T>*)0;
	}
	
	unsigned getSize(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedQueue*)0) throw NullPointerException();
		#endif
		if(isEmpty()) return 0;
		register unsigned size = 1;
		register LinkedList2Node<T> *temp = head;
		while(temp->getNext() != head){
			size++;
			temp = static_cast<LinkedList2Node<T>*>(temp->getNext());
		}
		return size;
	}
	
	bool addElement(T e){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedQueue*)0) throw NullPointerException();
		#endif
		if(head == (LinkedList2Node<T>*)0){
			head = new LinkedList2Node<T>(e);
			head->next = head->prev = head;
		}else{
			head = new LinkedList2Node<T>(e, head, head->getPrev());
		}
		return true;
	}
	
	bool hasElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		if(head->getKey() == e) return true;
		for(register LinkedList2Node<T> *temp = head->getNext();
				temp != head; temp = temp->getNext()){
			if(temp->getKey() == e) return true;
		}
		return false;
	}
	
	bool removeElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		if(head->getKey() == e){
			if(head->getNext() == head){
				delete head;
				head = (LinkedList2Node<T>*)0;
			}else{
				head = head->getNext();
				delete head->getPrev();
			}
			return true;
		}
		for(register LinkedList2Node<T> *temp = head->getNext();
				temp != head; temp = temp->getNext()){
			if(temp->getKey() == e){
				delete temp;
				return true;
			}
		}
		return false;
	}
	
	bool removeAllElement(){	// inherited from Collection
		if(isEmpty()) return false;
		while(head->getPrev() != head){
			delete head->getPrev();
		}
		delete head;
		head = (LinkedList2Node<T>*)0;
		return true;
	}
	
	T getHeadElement(){	// inherited from Queue
		#ifdef _EXCEPTION_H_
		if(this == (LinkedQueue*)0 || head == (LinkedList2Node<T>*)0)
			throw NullPointerException();
		#endif
		return head->getKey();
	}
	
	bool addElementToHead(T e){	// inherited from Queue
		return addElement(e);
	}
	
	bool removeHeadElement(){	// inherited from Queue
		if(isEmpty()) return false;
		if(head == head->getPrev()){
			delete head;
			head = (LinkedList2Node<T>*)0;
		}else{
			head = head->getNext();
			delete head->getPrev();
		}
		return true;
	}
	
	T getTailElement(){	// inherited from Queue
		#ifdef _EXCEPTION_H_
		if(this == (LinkedQueue*)0 || head == (LinkedList2Node<T>*)0)
			throw NullPointerException();
		#endif
		return head->getPrev()->getKey();
	}

	bool addElementToTail(T e){
		#ifdef _EXCEPTION_H_
		if(this == (LinkedQueue*)0) throw NullPointerException();
		#endif
		if(head == (LinkedList2Node<T>*)0){
			head = new LinkedList2Node<T>(e);
			head->next = head->prev = head;
		}else{
			new LinkedList2Node<T>(e, head, head->getPrev());
		}
		return true;
	}

	bool removeTailElement(){	// inherited from Queue
		if(isEmpty()) return false;
		if(head == head->getPrev()){
			delete head;
			head = (LinkedList2Node<T>*)0;
		}else{
			delete head->getPrev();
		}
		return true;
	}
	
}; // class LinkedQueue<T>
#endif // _LINKED_QUEUE_H_