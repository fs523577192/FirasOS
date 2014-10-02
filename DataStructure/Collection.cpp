#include "../Macro.cpp"
template <typename T> class Collection{
public:
	
	virtual ~Collection(){};
	
	/***
	 * Return: true if the collection is empty (has no element),
	 * or false if the collection is not empty.
	 */
	virtual bool isEmpty() = 0;
	
	/***
	 * Return: the number of elements the collection has (>=0).
	 */
	virtual unsigned getSize() = 0;
	
	/***
	 * Adds an element e to the collection.
	 * Return: true if it successes, or false if it fails.
	 */
	virtual bool addElement(T e) = 0;	// ?
	
	/***
	 * Return: true if the collection has the element e,
	 * or false if the collection has not.
	 */
	virtual bool hasElement(T e) = 0;
	
	/***
	 * Return: true if the collection has the element e
	 * and successfully removes e from it, or false if
	 * the collection has not e or fails to remove e.
	 */
	virtual bool removeElement(T e) = 0;
	
	virtual bool removeAllElement() = 0;
	
}; // class Collection<T>

template <typename T> class List : public Collection<T>{
public:
	
	virtual ~List(){};
	
	/***
	 * The first element in the list has index 0.
	 * Return: null if the index is equal or larger
	 * than the size of the list, or the element at
	 * the given index.
	 */
	virtual T getElementAtIndex(unsigned index) = 0;
	
	virtual bool insertElementAtIndex(T e, unsigned index) = 0;
	
	/***
	 * Return: false if the index is equal or larger
	 * than the size of the list or it fails to remove
	 * the element at the given index, or true if it
	 * successfully removes the element at the given
	 * index.
	 */
	virtual bool removeElementAtIndex(unsigned index) = 0;
	
	/***
	 * Return: null if fromIndex>=toIndex, or a list
	 * containing all the elements of this list from
	 * getElementAtIndex(fromIndex) to
	 * getElementAtIndex(toIndex-1)
	 */
	virtual List* subList(unsigned fromIndex, unsigned toIndex) = 0;
	
	/***
	 * Return: true only if the two lists has the same elements
	 * at the same indexes (in the same order)
	 */
	virtual bool isEqual(List *l) = 0;
	
}; // class IndexedCollection<T>

template <typename T> class Stack : public Collection<T>{
public:
	
	virtual ~Stack(){};
	
	/***
	 *
	 */
	virtual bool pushElement(T e) = 0;
	
	/***
	 *
	 */
	virtual T popElement() = 0;
	
}; // class Stack<T>


template <typename T> class Queue : public Collection<T>{
public:
	
	
	/***
	 *
	 */
	virtual T getHeadElement() = 0;
	
	/***
	 *
	 */
	virtual bool addElementToHead(T e) = 0;
	
	/***
	 *
	 */
	virtual bool removeHeadElement() = 0;
	
	/***
	 *
	 */
	virtual T getTailElement() = 0;
	
	/***
	 *
	 */
	virtual bool addElementToTail(T e) = 0;
	
	/***
	 *
	 */
	virtual bool removeTailElement() = 0;
	
}; // class Queue<T>

template <typename T> class SortedCollection : public Collection<T>{
public:
	
	/***
	 * Return: null if the collection is empty
	 */
	virtual T getFirstElement() = 0;
	
	/***
	 *
	 */
	virtual bool removeFirstElement() = 0;
	
	/***
	 *
	 */
	virtual T getLastElement() = 0;
	
	/***
	 *
	 */
	virtual bool removeLastElement() = 0;
	
	/***
	 *
	 */
	virtual T getFloorElement(T e, bool inclusive) = 0;
	
	/***
	 *
	 */
	virtual T getCeilingElement(T e, bool inclusive) = 0;
	
	/***
	 *
	 */
	virtual SortedCollection* headSet(T toElement, bool inclusive) = 0;
	
	/***
	 *
	 */
	virtual SortedCollection* tailSet(T fromElement, bool inclusive) = 0;
	
	/***
	 *
	 */
	virtual SortedCollection* middleSet(T fromElement, bool fromInclusive,
				T toElement, bool toInclusive) = 0;
	
}; // class SortedCollection<T>
