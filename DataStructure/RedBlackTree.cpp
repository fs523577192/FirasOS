#ifndef _RED_BLACK_H_
#define _RED_BLACK_H_	1
#include "SortedBinaryTree.cpp"
template <typename T> class RedBlack;
template <typename T> class RedBlackNode{
protected:
	
	RedBlackNode *left, *right, *parent;
	
	T key;
	
	static const int ADDR_MASK = -2;	// ~1
	// -2 = 0FFFFFFFEh	2 bytes (16 bits) align  2字节（16位）对齐
	// -4 = 0FFFFFFFCh	4 bytes (32 bits) align  4字节（32位）对齐
	// -8 = 0FFFFFFF8h	8 bytes (64 bits) align  8字节（64位）对齐
	#define	RedBlackNullNode	((RedBlackNode*)0)
	friend class RedBlack<T>;
public:
	
	RedBlackNode(T k){
		key = k;
		left = right = parent = RedBlackNullNode;
	}
	
	RedBlackNode(T k, RedBlackNode *l, RedBlackNode *r, RedBlackNode *p){
		key = k;
		left = l; right = r; parent = p;
	}
protected:
	
	inline RedBlackNode *getLeftUnsafe(){
		return reinterpret_cast<RedBlackNode*>(
			reinterpret_cast<unsigned>(left) & ADDR_MASK);
	}
	inline RedBlackNode *getRightUnsafe(){
		return reinterpret_cast<RedBlackNode*>(
			reinterpret_cast<unsigned>(right) & ADDR_MASK);
	}
	inline RedBlackNode *getParentUnsafe(){
		return reinterpret_cast<RedBlackNode*>(
			reinterpret_cast<unsigned>(parent) & ADDR_MASK);
	}
	inline unsigned isLeftUnsafe(){
		return (reinterpret_cast<unsigned>(left) & 1);
	}
	inline unsigned isRightUnsafe(){
		return (reinterpret_cast<unsigned>(right) & 1);
	}
public:
	
	unsigned getWeight(){
		if(this == RedBlackNullNode) return 0;
		return (getLeftUnsafe()->getWeight() +
			getRightUnsafe()->getWeight());
	}
	
	void removeSubTree(){
		RedBlackNode *temp = getLeft();
		if(temp != RedBlackNullNode)
			temp->removeSubTree();
		temp = getRightUnsafe();
		if(temp != RedBlackNullNode)
			temp->removeSubTree();
		delete this;
	}
	
	inline RedBlackNode *getLeft(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return RedBlackNullNode;
		#endif
		return reinterpret_cast<RedBlackNode*>(
			reinterpret_cast<unsigned>(left) & ADDR_MASK);
	}
	inline RedBlackNode *getRight(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return RedBlackNullNode;
		#endif
		return reinterpret_cast<RedBlackNode*>(
			reinterpret_cast<unsigned>(right) & ADDR_MASK);
	}
	inline RedBlackNode *getParent(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return RedBlackNullNode;
		#endif
		return reinterpret_cast<RedBlackNode*>(
			reinterpret_cast<unsigned>(parent) & ADDR_MASK);
	}

	RedBlackNode *getRoot(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return RedBlackNullNode;
		#endif
		register RedBlackNode *temp;
		for(temp = this; temp->getParentUnsafe() != RedBlackNullNode;
			temp = temp->getParentUnsafe());
		return temp;
	}
	
	RedBlackNode *getLeftMost(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return RedBlackNullNode;
		#endif
		register RedBlackNode *temp;
		for(temp = this; temp->getLeftUnsafe() != RedBlackNullNode;
			temp = temp->getLeftUnsafe());
		return temp;
	}
	
	RedBlackNode *getRightMost(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return RedBlackNullNode;
		#endif
		register RedBlackNode *temp;
		for(temp = this; temp->getRightUnsafe() != RedBlackNullNode;
			temp = temp->getRightUnsafe());
		return temp;
	}
	
	RedBlackNode *getSibling(){
		if(isLeft())
			return getParentUnsafe()->getRight();
		if(isRight())
			return getParentUnsafe()->getLeft();
		return RedBlackNullNode;
	}
	
	inline bool isLeft(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return false;
		#endif
		return (reinterpret_cast<unsigned>(left) & 1) != 0;
	}
	inline bool isRight(){
		if(this==RedBlackNullNode)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return false;
		#endif
		return (reinterpret_cast<unsigned>(right) & 1) != 0;
	}
	inline bool isRed(){
		// no need to check whether this == null
		return (this != RedBlackNullNode) &&
			((reinterpret_cast<unsigned>(parent) & 1) != 0);
	}
	inline bool isBlack(){
		// no need to check whether this == null
		return (this == RedBlackNullNode) ||
			((reinterpret_cast<unsigned>(parent) & 1) == 0);
	}
	
	RedBlackNode *getPrevNode(){
		register RedBlackNode *temp = getLeft();
		if(temp != RedBlackNullNode)
			return temp->getRightMost();
		for(temp = this; temp->getParentUnsafe() != RedBlackNullNode;
				temp = temp->getParentUnsafe()){
			if(temp->isRightUnsafe())
				return temp->getParentUnsafe();
		}
		return RedBlackNullNode;
	}
	
	RedBlackNode *getNextNode(){
		register RedBlackNode *temp = getRight();
		if(temp != RedBlackNullNode)
			return temp->getLeftMost();
		for(temp = this; temp->getParentUnsafe() != RedBlackNullNode;
				temp = temp->getParentUnsafe()){
			if(temp->isLeftUnsafe())
				return temp->getParentUnsafe();
		}
		return RedBlackNullNode;
	}
protected:
	
	RedBlackNode *rotateLeft(){
		register RedBlackNode *rightChild = getRight();
		#ifdef _EXCEPTION_H_
		if(rightChild==RedBlackNullNode) throw NullPointerException();
		#endif
		if(isLeftUnsafe()){
			register RedBlackNode *parentNode = getParentUnsafe();
			parentNode->left = reinterpret_cast<RedBlackNode*>((
				reinterpret_cast<unsigned>(parentNode->left) &
				1) | reinterpret_cast<unsigned>(rightChild));
			// getParent()->setLeft(right)	(a)
		}else if(isRightUnsafe()){
			register RedBlackNode *parentNode =
				reinterpret_cast<RedBlackNode*>(ADDR_MASK &
				reinterpret_cast<unsigned>(parent));
			parentNode->right = reinterpret_cast<RedBlackNode*>((
				reinterpret_cast<unsigned>(parentNode->right) &
				1) | reinterpret_cast<unsigned>(rightChild));
			// getParent()->setRight(right)	(a)
		}
		register RedBlackNode *rightLeft = rightChild->getLeftUnsafe();
		if(rightLeft != RedBlackNullNode){
			rightLeft->parent = reinterpret_cast<RedBlackNode*>((
				1 & reinterpret_cast<unsigned>(
				rightLeft->parent)) |
				reinterpret_cast<unsigned>(this));
			// (l)
			rightLeft->left = rightLeft->getLeftUnsafe();
			// (m)
			rightLeft->right = reinterpret_cast<RedBlackNode*>(1 |
				reinterpret_cast<unsigned>(rightLeft->right));
			// (n)
		}
		register unsigned temp = reinterpret_cast<unsigned>(
						rightChild->parent) & 1;
		rightChild->parent = parent;			// (g)(h)
		parent = reinterpret_cast<RedBlackNode*>(temp |
			reinterpret_cast<unsigned>(rightChild));// (b)(c)
		
		rightChild->left = reinterpret_cast<RedBlackNode*>((
			reinterpret_cast<unsigned>(left) & 1) |
			reinterpret_cast<unsigned>(this));	// (i)(j)
		rightChild->right = reinterpret_cast<RedBlackNode*>((
			reinterpret_cast<unsigned>(right) & 1) | ( ADDR_MASK &
			reinterpret_cast<unsigned>(rightChild->right)));// (k)
		
		left = reinterpret_cast<RedBlackNode*>(1 |
				reinterpret_cast<unsigned>(left));	// (d)
		right = rightLeft;	// (e)(f)
	}
	
	RedBlackNode *rotateRight(){
		register RedBlackNode *leftChild = getLeft();
		#ifdef _EXCEPTION_H_
		if(leftChild==RedBlackNullNode) throw NullPointerException();
		#endif
		if(isLeft()){
			register RedBlackNode *parentNode = getParentUnsafe();
			parentNode->left = reinterpret_cast<RedBlackNode*>((
				reinterpret_cast<unsigned>(parentNode->left) &
				1) | reinterpret_cast<unsigned>(leftChild));
			// getParent()->setLeft(left)	(a)
		}else if(isRight()){
			register RedBlackNode *parentNode = getParentUnsafe();
			parentNode->right = reinterpret_cast<RedBlackNode*>((
				reinterpret_cast<unsigned>(parentNode->right) &
				1) | reinterpret_cast<unsigned>(leftChild));
			// getParent()->setRight(left)	(a)
		}
		register RedBlackNode *leftRight = leftChild->getRightUnsafe();
		if(leftRight != RedBlackNullNode){
			leftRight->parent = reinterpret_cast<RedBlackNode*>((
				1 & reinterpret_cast<unsigned>(
				leftRight->parent)) |
				reinterpret_cast<unsigned>(this));
			// (l)
			leftRight->right = leftRight->getRightUnsafe();
			// (m)
			leftRight->left = reinterpret_cast<RedBlackNode*>(1 |
				reinterpret_cast<unsigned>(leftRight->left));
			// (n)
		}
		register unsigned temp = reinterpret_cast<unsigned>(
						leftChild->parent) & 1;
		leftChild->parent = parent;			// (g)(h)
		parent = reinterpret_cast<RedBlackNode*>(temp |
			reinterpret_cast<unsigned>(leftChild));// (b)(c)
		
		leftChild->right = reinterpret_cast<RedBlackNode*>((
			reinterpret_cast<unsigned>(right) & 1) |
			reinterpret_cast<unsigned>(this));	// (i)(j)
		leftChild->left = reinterpret_cast<RedBlackNode*>((
			reinterpret_cast<unsigned>(left) & 1) | ( ADDR_MASK &
			reinterpret_cast<unsigned>(leftChild->left)));	// (k)
		
		right = reinterpret_cast<RedBlackNode*>(1 |
				reinterpret_cast<unsigned>(right));	// (d)
		left = leftRight;	// (e)(f)
	}
	
	
}; // class RedBlackNode<T>
#undef RedBlackNullNode
#define RedBlackNullNode	((RedBlackNode<T>*)0)
	
template <typename T> class RedBlack : public SortedBinaryTree<T>{
protected:
	
	RedBlackNode<T> *root;
	static int (*compareKey)(T *k1, T *k2);
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
