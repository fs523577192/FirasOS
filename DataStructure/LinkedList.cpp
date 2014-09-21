#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "LinkedListNode.cpp"
template <typename T> class LinkedList : public List<T>{
private:
	LinkedListNode<T> *head;
public:
	
	LinkedList(){
		head = LinkedListNullNode;
	}
	
	LinkedList(T k){
		head = new LinkedListNode<T>(k);
	}
	
	~LinkedList(){
		removeAllElement();
	}
	
	inline bool isEmpty(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		#endif
		return head == LinkedListNullNode;
	}
	
	unsigned getSize(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		#endif
		register unsigned size = 0;
		for(register LinkedListNode<T> *temp = head;
			temp != LinkedListNullNode;
			temp = temp->next) size++;
		return size;
	}
	
	bool addElement(T e){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		#endif
		head = new LinkedListNode<T>(e, head);
		return true;
	}
	
	bool hasElement(T e){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		#endif
		for(register LinkedListNode<T> *temp = head;
				temp != LinkedListNullNode;
				temp = temp->next)
			if(temp->key == e) return true;
		return false;
	}
	
	bool removeElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		LinkedListNode<T> *temp1 = head, *temp2 = head->next;
		if(head->key == e){
			head = temp2;
			delete temp1;
			return true;
		}
		while(temp2 != (LinkedListNode<T>*)0){
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
		while(head != LinkedListNullNode){
			register LinkedListNode<T> *temp = head;
			head = head->next;
			delete temp;
		}
		return true;
	}
	
	T getElementAtIndex(unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0 || head == LinkedListNullNode)
			throw NullPointerException();
		#endif
		LinkedListNode<T> *temp = head;
		while(index > 0 && temp != LinkedListNullNode){
			temp = temp->next;
			index--;
		}
		if(temp != LinkedListNullNode) return temp->key;
		#ifdef _EXCEPTION_H_
		throw IndexOutOfBoundsException();
		#endif
	}
	
	bool insertElementAtIndex(T e, unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		#endif
		if(index == 0){
			head = new LinkedListNode<T>(e, head);
			return true;
		}
		LinkedListNode<T> *temp = head;
		while(index > 1 && temp != LinkedListNullNode){
			temp = temp->next;
			index--;
		}
		if(temp == LinkedListNullNode) return false;
		temp->next = new LinkedListNode<T>(e, temp->next);
		return true;
	}
	
	bool removeElementAtIndex(unsigned index){	// inherited from List
		if(isEmpty()) return false;
		LinkedListNode<T> *temp1 = head, *temp2 = head->next;
		if(index == 0){
			head = temp2;
			delete temp1;
			return true;
		}
		while(index > 1 && temp2 != LinkedListNullNode){
			temp1 = temp2;
			temp2 = temp2->next;
			index--;
		}
		if(temp2 == LinkedListNullNode) return false;
		temp1->next = temp2->next;
		delete temp2;
		return true;
	}
	
	List<T>* subList(unsigned fromIndex, unsigned toIndex){
	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList*)0) throw NullPointerException();
		register unsigned size = getSize();
		if(fromIndex >= size || toIndex > size)
			throw IndexOutOfBoundsException();
		#endif
		LinkedList *list = new LinkedList();
		if(fromIndex >= toIndex) return list;
		LinkedListNode<T> *temp1 = head;
		while(fromIndex > 0){
			temp1 = temp1->next;
			fromIndex--;
			toIndex--;
		}
		list->head = new LinkedListNode<T>(temp1->key);
		LinkedListNode<T> *temp2 = list->head;
		while(toIndex > 1){
			temp1 = temp1->next;
			temp2->next = new LinkedListNode<T>(temp1->key);
			temp2 = temp2->next;
			toIndex--;
		}
		return list;
	}
	
	bool isEqual(List<T> *l){	// inherited from List
		if(getSize() != l->getSize()) return false;
		LinkedListNode<T> *temp = head;
		for(unsigned i = 0;
				temp != LinkedListNullNode;
				i++, temp = temp->next)
			if(temp->key != l->getElementAtIndex(i)) return false;
		return true;
	}
}; // class LinkedList<T>
#endif // _LINKED_LIST_H_
