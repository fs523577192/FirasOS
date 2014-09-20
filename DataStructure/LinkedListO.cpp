#include "LinkedListNode.cpp"
#ifndef _LINKED_LIST_O_H_
#define _LINKED_LIST_O_H_
template <typename T> class LinkedListO : public List<T>{
private:
	LinkedListNode<T> *head;
public:
	
	LinkedListO(){
		head = LinkedListNullNode;
	}
	
	LinkedListO(T e){
		head = new LinkedListNode<T>(e);
		head->next = head;
	}
	
	~LinkedListO(){
		removeAllElement();
	}
	
	inline bool isEmpty(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedListO*)0) throw NullPointerException();
		#endif
		return head == LinkedListNullNode;
	}
	
	unsigned getSize(){	// inherited from Collection
		if(isEmpty()) return 0;
		register unsigned size = 1;
		for(register LinkedListNode<T> *temp = head->next;
			temp != head;
			temp = temp->next) size++;
		return size;
	}
	
	bool addElement(T e){	// inherited from Collection
		if(isEmpty()){
			head = new LinkedListNode<T>(e);
			head->next = head;
		}else{
			register LinkedListNode<T> *temp = head;
			while(temp->next != head) temp = temp->next;
			temp->next = head = new LinkedListNode<T>(e, head);
		}
		return true;
	}
	
	bool hasElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		if(head->key == e) return true;
		for(register LinkedListNode<T> *temp = head->next;
				temp != head; temp = temp->next)
			if(temp->key == e) return true;
		return false;
	}
	
	bool removeElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		register LinkedListNode<T> *temp1 = head, *temp2 = head->next;;
		if(head->key == e){
			while(temp1->next != head) temp1 = temp1->next;
			temp1->next = temp2;
			delete head;
			head = temp2;
			return true;
		}
		while(temp2 != head){
			if(temp2->key == e){
				temp1->next = temp2->next;
				delete temp2;
				return true;
			}
			temp1 = temp2;
			temp2 = temp2->next;
		}
		return false;
	}
	
	bool removeAllElement(){	// inherited from Collection
		if(isEmpty()) return false;
		LinkedListNode<T> *temp = head->next;
		while(temp != head){
			head->next = temp->next;
			delete temp;
			temp = head->next;
		}
		delete head;
		head = LinkedListNullNode;
		return true;
	}

	T getElementAtIndex(unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedListO*)0 || head == LinkedListNullNode)
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
		if(this == (LinkedListO*)0) throw NullPointerException();
		if(fromIndex >= getSize() || toIndex > getSize())
			throw IndexOutOfBoundsException();
		#endif
		LinkedListO *list = new LinkedListO();
		
		return list;
	}
	
}; // class LinkedListO<T>
#endif // _LINKED_LIST_O_H_
