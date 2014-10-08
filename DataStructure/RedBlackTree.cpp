#ifndef _RED_BLACK_H_
#define _RED_BLACK_H_	1
#include "SortedBinaryTree.cpp"
#include "RedBlackNode.cpp"

template <typename T> class RedBlack : public SortedBinaryTree<T>{
protected:
	
	RedBlackNode<T> *root;
	#define	RedBlackNull	((RedBlack*)0)
	
public:
	
	RedBlack(){
		root = RedBlackNullNode;
	}
	
	RedBlack(T firstElement){
		root = new RedBlackNode<T>(firstElement);
	}
	
	bool isEmpty(){	// inherited from Collection
		if(this == RedBlackNull)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return true;
		#endif
		return (root == RedBlackNullNode);
	}
	
	unsigned getSize(){	// inherited from Collection
		if(this == RedBlackNull)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return 0;
		#endif
		return root->getWeight();
	}
	
	bool addElement(T e){	// inherited from Collection
	
	}
	
	bool hasElement(T e){	// inherited from Collection
		if(isEmpty()) return false;
		register RedBlackNode<T> *temp = root;
		while(temp != RedBlackNullNode){
			if(temp->key == e) return true;
			if(temp->key > e) temp = temp->getRightUnsafe();
			else temp = temp->getLeftUnsafe();
		}
		return false;
	}
	
	bool removeElement(T e){	// inherited from Collection
		
	}
	
	bool removeAllElement(){	// inherited from Collection
		if(isEmpty()) return false;
		root->removeSubTree();
		root = RedBlackNullNode;
		return true;
	}
	
	T getFirstElement(){	// inherited from SortedCollection
		
	}
	
	bool removeFirstElement(){	// inherited from SortedCollection
		
	}
	
	T getLastElement(){		// inherited from SortedCollection
		
	}
	
	bool removeLastElement(){	// inherited from SortedCollection
		
	}
	
	T getFloorElement(T e, bool inclusive){
	// inherited from SortedCollection
		
	}
	
	T getCeilingElement(T e, bool inclusive){
	// inherited from SortedCollection
		
	}
	
	SortedCollection<T>* headSet(T toElement, bool inclusive){
	// inherited from SortedCollection
			
	}
	
	SortedCollection<T>* tailSet(T fromElement, bool inclusive){
	// inherited from SortedCollection
		
	}
	
	SortedCollection<T>* middleSet(T fromElement, bool fromInclusive,
				T toElement, bool toInclusive){
	// inherited from SortedCollection
		
	}
	
}; // class RedBlack<T>
#endif // _RED_BLACK_H_
