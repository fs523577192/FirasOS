#ifndef _LINKED_LIST_2_H_
#define _LINKED_LIST_2_H_
#include "LinkedList2Node.cpp"
template <typename T> class LinkedList2 : public List<T>{
private:
	LinkedList2Node<T> *head;
	
public:
	
	LinkedList2(){
		head = (LinkedList2Node<T>*)0;
	}
	
	LinkedList2(T e){
		head = new LinkedList2Node<T>(e);
	}
	
	~LinkedList2(){
		removeAllElement();
	}
	
	inline bool isEmpty(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList2*)0) throw NullPointerException();
		#endif
		return head == (LinkedList2Node<T>*)0;
	}
	
	unsigned getSize(){	// inherited from Collection
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList2*)0) throw NullPointerException();
		#endif
		register unsigned size = 0;
		for(register LinkedList2Node<T> *temp = head;
			temp != (LinkedList2Node<T>*)0;
			temp = temp->next) size++;
		return size;
	}
	
	bool addElement(T e){	// inherited from Collection
		if(isEmpty()) head = new LinkedList2Node<T>(e);
		else head = new LinkedList2Node<T>(e, head, LinkedList2NullNode);
		return true;
	}
	
	bool hasElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		for(LinkedList2Node<T> *temp = head;
				temp != LinkedList2NullNode;
				temp = temp->next)
			if(temp->key == e) return true;
		return false;
	}
	
	bool removeElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		register LinkedList2Node<T> *temp = head;
		if(head->key == e){
			head = head->next;
			delete temp;
			return true;
		}
		temp = head->next;
		while(temp != LinkedList2NullNode){
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
		while(head != LinkedList2NullNode){
			LinkedList2Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
		return true;
	}
	
	T getElementAtIndex(unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList2*)0 || head == LinkedList2NullNode)
			throw NullPointerException();
		#endif
		register LinkedList2Node<T> *temp = head;
		while(index > 0 && temp != LinkedList2NullNode){
			temp = temp->next;
			index--;
		}
		if(temp != LinkedList2NullNode) return temp->key;
		#ifdef _EXCEPTION_H_
		throw IndexOutOfBoundsException();
		#endif
	}
	
	bool insertElementAtIndex(T e, unsigned index){	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList2*)0) throw NullPointerException();
		#endif
		if(index == 0){
			head = new LinkedList2Node<T>(e, head,
				LinkedList2NullNode);
			return true;
		}
		register LinkedList2Node<T> *temp = head;
		while(index > 1 && temp != LinkedList2NullNode){
			temp = temp->next;
			index--;
		}
		if(temp == LinkedList2NullNode) return false;
		new LinkedList2Node<T>(e, temp->next, temp);
		return true;
	}
	
	bool removeElementAtIndex(unsigned index){	// inherited from List
		if(isEmpty()) return false;
		LinkedList2Node<T> *temp = head->next;
		if(index == 0){
			delete head;
			head = temp;
			return true;
		}
		while(index > 1 && temp != LinkedList2NullNode){
			temp = temp->next;
			index--;
		}
		if(temp == LinkedList2NullNode) return false;
		delete temp;
		return true;
	}
	
	List<T>* subList(unsigned fromIndex, unsigned toIndex){
	// inherited from List
		#ifdef _EXCEPTION_H_
		if(this == (LinkedList2*)0) throw NullPointerException();
		register unsigned size = getSize();
		if(fromIndex >= size || toIndex > size)
			throw IndexOutOfBoundsException();
		#endif
		LinkedList2 *list = new LinkedList2();
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
			new LinkedList2Node<T>(temp1->key, LinkedList2NullNode, temp2);
			temp2 = temp2->next;
			toIndex--;
		}
		return list;
	}
	
	bool isEqual(List<T> *l){	// inherited from List
		if(getSize() != l->getSize()) return false;
		LinkedList2Node<T> *temp = head;
		for(unsigned i = 0;
				temp != LinkedList2NullNode;
				i++, temp = temp->next)
			if(temp->key != l->getElementAtIndex(i)) return false;
		return true;
	}
	
}; // class LinkedList2<T>
#endif // _LINKED_LIST_2_H_
