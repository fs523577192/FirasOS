#ifndef _LINKED_LIST_O2_H_
#define _LINKED_LIST_O2_H_
#include "LinkedList2Node.cpp"
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
		if(this == (LinkedListO2*)0) throw NullPointerException();
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
			temp = temp->next;
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
		if(this == (LinkedListO2*)0 || head == LinkedList2NullNode)
			throw NullPointerException();
		#endif
		if(index == 0) return head->key;
		register LinkedList2Node<T> *temp = head->next;
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
		if(this == (LinkedListO2*)0) throw NullPointerException();
		#endif
		register LinkedList2Node<T> *temp = head;
		if(index == 0){
			head = new LinkedList2Node<T>(e, head, head->prev);
			if(head->next == LinkedList2NullNode){
				head->prev = head->next = head;
			}
			return true;
		}
		if(index == 1){
			if(head == LinkedList2NullNode) return false;
			new LinkedList2Node<T>(e, head->next, head);
			return true;
		}
		temp = head->next;
		while(index > 2 && temp != head){
			temp = temp->next;
			index--;
		}
		if(temp == head) return false;	// index >= getSize()
		new LinkedList2Node<T>(e, temp->next, temp);
		return true;
	}

	bool removeElementAtIndex(unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedListO2*)0) throw NullPointerException();
		#endif
		LinkedList2Node<T> *temp = head->next;
		if(index == 0){
			delete head;
			head = temp;
			return true;
		}
		while(index > 1 && temp != head){
			temp = temp->next;
			index--;
		}
		if(temp == head) return false;	// index >= getSize()
		delete temp;
		return true;
	}

	bool isEqual(List<T> *l){	// inherited from List
		if(getSize() != l->getSize()) return false;
		if(isEmpty()) return true;
		if(head->key != l->getElementAtIndex(0)) return false;
		LinkedList2Node<T> *temp = head->next;
		for(unsigned i = 1; temp != head; i++, temp = temp->next){
			if(temp->key != l->getElementAtIndex(i)) return false;
		}
		return true;
	}

	List<T>* subList(unsigned fromIndex, unsigned toIndex){
		// inherited from List
		register unsigned size = getSize();
		if(fromIndex >= size || toIndex > size)
		#ifdef _EXCEPTION_H_
			throw IndexOutOfBoundsException();
		#else
			return new LinkedListO2();
		#endif
		LinkedListO2 *list = new LinkedListO2();
		if(fromIndex >= toIndex) return list;
		LinkedList2Node<T> *temp1 = head;
		while(fromIndex > 0){
			temp1 = temp1->next;
			fromIndex--;
			toIndex--;
		}
		list->head = new LinkedList2Node<T>(temp1->key);
		LinkedList2Node<T> *temp2 = list->head;
		while(toIndex > 1){
			temp1 = temp1->next;
			temp2 = new LinkedList2Node<T>(temp1->key,
				LinkedList2NullNode, temp2);
			toIndex--;
		}
		temp2->next = list->head;
		list->head->prev = temp2;
		return list;
	}
	
}; // class LinkedListO2<T>
#endif // _LINKED_LIST_O2_H_
