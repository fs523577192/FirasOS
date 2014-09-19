#include <iostream>
#include "Exception.cpp"
#include "LinkedListO.cpp"
int main(){
	LinkedListO<float> *list = new LinkedListO<float>();
	printf("%d %d\n", list->isEmpty(), list->getSize());
	// 1 0
	printf("%d ", list->addElement(2.5f));
	printf("%d ", list->addElement(0.5f));
	printf("%d\n", list->addElement(0.25f));
	// 1 1 1
	printf("%d %d\n", list->isEmpty(), list->getSize());
	// 0 3
	printf("%d %d\n", list->hasElement(0.5f),
		list->hasElement(1.0f));
	// 1 0
	printf("%d %d\n", list->removeElement(0.5f),
		list->removeElement(1.0f));
	// 1 0
	printf("%d %d\n", list->isEmpty(), list->getSize());
	// 0 2
	printf("%d ", list->addElement(0.125f));
	printf("%d ", list->addElement(3.5f));
	printf("%d ", list->removeElement(3.5f));
	printf("%d\n\n", list->removeAllElement());
	// 1 1 1 1
	delete list;
	
	list = new LinkedListO<float>(1.5f);
	printf("%d %d\n", list->isEmpty(), list->getSize());
	// 0 1
	printf("%d ", list->insertElementAtIndex(0.5f, 0));
	printf("%d ", list->insertElementAtIndex(2.5f, 1));
	printf("%d ", list->insertElementAtIndex(0.25f, 3));
	printf("%d\n", list->insertElementAtIndex(2.0f, 5));
	// 1 1 1 0
	printf("%d %d\n", list->isEmpty(), list->getSize());
	// 0 4
	printf("%d %d\n", list->hasElement(0.5f),
		list->hasElement(2.0f));
	// 1 0
	printf("%f %f %f\n", list->getElementAtIndex(0),
		list->getElementAtIndex(1),
		list->getElementAtIndex(2));
	// 0.5000 2.5000 1.5000
	List<float> *list2 = list->subList(0, 2);
	List<float> *list3 = list->subList(1, 4);
	printf("%d %d\n", list2->getSize(), list3->getSize());
	// 2 3
	printf("%d ", list->removeElementAtIndex(0));
	printf("%d ", list->removeElementAtIndex(1));
	printf("%d\n", list->removeElementAtIndex(3));
	// 1 1 0
	printf("%d %d\n", list->isEmpty(), list->getSize());
	// 0 2
	printf("%f %f\n", list->getElementAtIndex(0),
		list->getElementAtIndex(1));
	// 2.5000 0.2500
	list3->removeElementAtIndex(1);
	printf("%d %d\n\n", list->isEqual(list2), list->isEqual(list3));
	// 0 1
	
	return 0;
}