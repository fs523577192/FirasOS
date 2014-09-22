#ifndef _BINARY_TREE_NODE_H_
#define _BINARY_TREE_NODE_H_
template <typename T> class BinaryTreeSmallNode{
protected:
	
	BinaryTreeSmallNode *left, *right;
	
	T key;
	
	#define BinaryTreeSmallNullNode ((BinaryTreeSmallNode*)0)
public:
	
	BinaryTreeSmallNode(T k){
		key = k;
	}
	
	BinaryTreeSmallNode(T k,
			BinaryTreeSmallNode *l, BinaryTreeSmallNode *r){
		key = k;
		left = l; right = r;
	}
	
	~BinaryTreeSmallNode(){}
	
	virtual T getKey(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeSmallNullNode)
			throw NullPointerException();
		#endif
		return key;
	}
	
	virtual BinaryTreeSmallNode *getLeft(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeSmallNullNode)
			throw NullPointerException();
		#endif
		return left;
	}
	
	virtual BinaryTreeSmallNode *getRight(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeSmallNullNode)
			throw NullPointerException();
		#endif
		return right;
	}
	
	virtual BinaryTreeSmallNode *getLeftMost(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeSmallNullNode)
			throw NullPointerException();
		#endif
		BinaryTreeSmallNode *temp = this;
		while(temp->left != BinaryTreeSmallNullNode)
			temp = temp->left;
		return temp;
	}
	
	virtual BinaryTreeSmallNode *getRightMost(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeSmallNullNode)
			throw NullPointerException();
		#endif
		BinaryTreeSmallNode *temp = this;
		while(temp->right != BinaryTreeSmallNullNode)
			temp = temp->right;
		return temp;
	}
	
	virtual rotateLeft(){
		
	}
	
	virtual rotateRight(){
		
	}
	
}; // class BinaryTreeSmallNode<T>

template <typename T> class BinaryTreeNode{
protected:
	
	BinaryTreeNode *left, *right, *parent;
	
	T key;
	
	#define BinaryTreeNullNode ((BinaryTreeNode*)0)
public:
	
	BinaryTreeNode(T k){
		key = k;
		left = right = parent = BinaryTreeNullNode;
	}
	
	BinaryTreeNode(T k, BinaryTreeNode *l, BinaryTreeNode *r,
			BinaryTreeNode *p){
		key = k;
		left = l; right = r; parent = p;
	}
	
	~BinaryTreeNode(){}
	
	virtual inline T getKey(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		return key;
	}
	
	virtual inline BinaryTreeNode *getLeft(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		return left;
	}
	
	virtual inline BinaryTreeNode *getRight(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		return right;
	}
	
	virtual inline BinaryTreeNode *getParent(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		return parent;
	}
	
	virtual BinaryTreeNode *getLeftMost(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		BinaryTreeNode *temp = this;
		while(temp->left != BinaryTreeNullNode)
			temp = temp->left;
		return temp;
	}
	
	virtual BinaryTreeNode *getRightMost(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		BinaryTreeNode *temp = this;
		while(temp->right != BinaryTreeNullNode)
			temp = temp->right;
		return temp;
	}
	
	virtual BinaryTreeNode *getRoot(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		BinaryTreeNode *temp = this;
		while(temp->parent != BinaryTreeNullNode)
			temp = temp->parent;
		return temp;
	}
	
	virtual BinaryTreeNode *getSibling(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		if(parent == BinaryTreeNullNode) return BinaryTreeNullNode;
		if(this == parent->left) return parent->right;
		return parent->left;
	}
	
	virtual bool isLeft(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		if(parent == BinaryTreeNullNode) return false;
		if(this == parent->left) return true;
		return false;
	}
	
	virtual bool isRight(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		if(parent == BinaryTreeNullNode) return false;
		if(this == parent->right) return true;
		return false;
	}
	
	virtual inline bool isRoot(){
		#ifdef _EXCEPTION_H_
		if(this == BinaryTreeNullNode)
			throw NullPointerException();
		#endif
		if(parent == BinaryTreeNullNode) return true;
		return false;
	}
	
	virtual rotateLeft(){
		
	}
	
	virtual rotateRight(){
		
	}
	
}; // class BinaryTreeNode<T>
#endif // _BINARY_TREE_NODE_H_
