#include "LinkedList2Node.cpp"
#ifndef _LINKED_LIST_O2_H_
#define _LINKED_LIST_O2_H_
template <typename T> class LinkedListO2 : public List<T>{
private:
	LinkedList2Node<T> *head;
public:
	
	LinkedListO2(){
		head = (LinkedList2Node<T>*)0;
	}
	
	LinkedListO2(T e){
		head = new LinkedList2Node<T>(e);
		head->next = head->prev = head;
	}
	
	~LinkedListO2(){
		removeAllElement();
	}
	
	inline bool isEmpty(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList2*)0) throw NullPointerException();
		#endif
		return head == (LinkedList2Node<T>*)0;
	}
	
	unsigned getSize(){	// inherited from Collection
		if(isEmpty()) return 0;
		register unsigned size = 1;
		for(register LinkedList2Node<T> *temp = head->next;
			temp != head;
			temp = temp->next) size++;
		return size;
	}
	
	bool addElement(T e){	// inherited from Collection
		if(isEmpty()){
			head = new LinkedList2Node<T>(e);
			head->next = head->prev = head;
		}else head = new LinkedList2Node<T>(e, head, head->prev);
		return true;
	}
	
	bool hasElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		if(head->key == e) return true;
		for(register LinkedList2Node<T> *temp = head->next;
				temp != head; temp = temp->next)
			if(temp->key == e) return true;
		return false;
	}
	
	bool removeElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		register LinkedList2Node<T> *temp = head->next;
		if(head->key == e){
			delete head;
			head = temp;
			return true;
		}
		while(temp != head){
			if(temp->key == e){
				delete temp;
				return true;
			}
		}
		return false;
	}
	
	bool removeAllElement(){	// inherited from Collection
		if(isEmpty()) return false;
		while(head->next != head) delete head->next;
		delete head;
		head = LinkedList2NullNode;
		return true;
	}

	T getElementAtIndex(unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0 || head == LinkedListNullNode)
			throw NullPointerException();
		#endif
		if(index == 0) return head->key;
		register LinkedListNode<T> *temp = head->next;
		while(index > 1 && temp != head){
			temp = temp->next;
			index--;
		}
		#ifdef _EXCEPTION_H_
		if(temp == head)
			throw IndexOutOfBoundsException();
		#endif
		return temp->key;
	}
	
	bool insertElementAtIndex(T e, unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedListO*)0) throw NullPointerException();
		#endif
		register LinkedListNode<T> *temp = head;
		if(index == 0){
			head = new LinkedListNode<T>(e, head);
			if(head->next == LinkedListNullNode) head->next = head;
			else{
				while(temp->next != head->next) temp = temp->next;
				temp->next = head;
			}
			return true;
		}
		if(index == 1){
			if(head == LinkedListNullNode) return false;
			head->next = new LinkedListNode<T>(e, head->next);
			return true;
		}
		temp = head->next;
		while(index > 2 && temp != head){
			temp = temp->next;
			index--;
		}
		if(temp == head) return false;
		temp->next = new LinkedListNode<T>(e, temp->next);
		return true;
	}
	
	bool removeElementAtIndex(unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedListO*)0) throw NullPointerException();
		#endif
		LinkedListNode<T> *temp1;
		if(index == 0){
			for(temp1 = head; temp1->next != head;
				temp1 = temp1->next);
			if(temp1 != head) temp1->next = head->next;
			delete head;
			head = temp1->next;
			return true;
		}
		temp1 = head;
		LinkedListNode<T> *temp2 = head->next;
		while(index > 1 && temp2 != head){
			temp1 = temp2;
			temp2 = temp2->next;
			index--;
		}
		if(temp2 == head) return false;
		temp1->next = temp2->next;
		delete temp2;
		return true;
	}
	
	bool isEqual(List<T> *l){	// inherited from List
		if(getSize() != l->getSize()) return false;
		if(isEmpty()) return true;
		
		return true;
	}
	
	List<T>* subList(unsigned fromIndex, unsigned toIndex){
	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		if(fromIndex >= getSize() || toIndex > getSize())
			throw IndexOutOfBoundsException();
		#endif
		LinkedListO *list = new LinkedListO();
		
		return list;
	}
	
}; // class LinkedListO2<T>
#endif // _LINKED_LIST_O2_H_
