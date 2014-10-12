#include <iostream>
#include "Exception.cpp"
#include "LinkedList2.cpp"
int main(){
	LinkedList2<float> *list = new LinkedList2<float>();
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 1 0
	std::cout << list->addElement(2.5f) << ' ';
	std::cout << list->addElement(0.5f) << ' ';
	std::cout << list->addElement(0.25f) << '\n';
	// 1 1 1
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 0 3
	std::cout << list->hasElement(0.5f) << ' ';
	std::cout << list->hasElement(1.0f) << '\n';
	// 1 0
	std::cout << list->removeElement(0.5f) << ' ';
	std::cout << list->removeElement(1.0f) << '\n';
	// 1 0
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 0 2
	std::cout << list->addElement(0.125f) << ' ';
	std::cout << list->addElement(3.5f) << ' ';
	std::cout << list->removeElement(3.5f) << ' ';
	std::cout << list->removeAllElement() << '\n' << '\n';
	// 1 1 1 1
	delete list;
	
	list = new LinkedList2<float>(1.5f);
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 0 1
	std::cout << list->insertElementAtIndex(0.5f, 0) << ' ';
	std::cout << list->insertElementAtIndex(2.5f, 1) << ' ';
	std::cout << list->insertElementAtIndex(0.25f, 3) << ' ';
	std::cout << list->insertElementAtIndex(2.0f, 5) << '\n';
	// 1 1 1 0
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 0 4
	std::cout << list->hasElement(0.5f) << ' ';
	std::cout << list->hasElement(2.0f) << '\n';
	// 1 0
	std::cout << list->getElementAtIndex(0) << '\t';
	std::cout << list->getElementAtIndex(1) << '\t';
	std::cout << list->getElementAtIndex(2) << '\n';
	// 0.5	2.5	1.5
	List<float> *list2 = list->subList(0, 2);
	List<float> *list3 = list->subList(1, 4);
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 2 3
	std::cout << list->removeElementAtIndex(0) << ' ';
	std::cout << list->removeElementAtIndex(1) << ' ';
	std::cout << list->removeElementAtIndex(3) << '\n';
	// 1 1 0
	std::cout << list->isEmpty() << ' ' << list->getSize() << '\n';
	// 0 2
	std::cout << list->getElementAtIndex(0) << '\t';
	std::cout << list->getElementAtIndex(1) << '\n';
	// 2.5	0.25
	list3->removeElementAtIndex(1);
	std::cout << list->isEqual(list2) << ' ';
	std::cout << list->isEqual(list3) << '\n' << '\n';
	// 0 1
	
	return 0;
}
