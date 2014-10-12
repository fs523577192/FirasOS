#include <iostream>
#include "Exception.cpp"
#include "LinkedQueue.cpp"
int main(){
	LinkedQueue<double> *queue = new LinkedQueue<double>();
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 1 0
	std::cout << queue->addElement(0.5) << ' ';
	std::cout << queue->addElement(2.5) << ' ';
	std::cout << queue->addElement(1.5) << '\n';
	// 1 1 1
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 0 3
	std::cout << queue->hasElement(0.5) << ' ';
	std::cout << queue->hasElement(0.25) << '\n';
	// 1 0
	std::cout << queue->removeElement(0.5) << ' ';
	std::cout << queue->removeElement(0.25) << '\n';
	// 1 0
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 0 2
	delete queue;
	
	queue = new LinkedQueue<double>(1.5);
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 0 1
	std::cout << queue->addElementToHead(0.5) << ' ';
	std::cout << queue->addElementToHead(2.5) << ' ';
	std::cout << queue->addElementToTail(4.5) << ' ';
	std::cout << queue->addElementToTail(3.5) << '\n';
	// 1 1 1 1
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 0 5
	std::cout << queue->getHeadElement() << '\t';
	std::cout << queue->getTailElement() << '\n';
	// 2.5	3.5
	std::cout << queue->removeHeadElement() << ' ';
	std::cout <<queue->removeTailElement() << '\n';
	// 1 1
	std::cout << queue->getHeadElement() << '\t';
	std::cout << queue->getTailElement() << '\n';
	// 0.5	4.5
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 0 3
	std::cout << queue->removeAllElement() << '\n';
	// 1
	std::cout << queue->isEmpty() << ' ' <<queue->getSize() << '\n';
	// 1 0
	
	return 0;
}
