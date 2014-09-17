#include <iostream>
#include "Exception.cpp"
#include "LinkedQueue.cpp"
int main(){
	LinkedQueue<double> *queue = new LinkedQueue<double>();
	printf("%d %d\n", queue->isEmpty(), queue->getSize());
	// 1 0
	printf("%d ", queue->addElement(0.5));
	printf("%d ", queue->addElement(2.5));
	printf("%d\n", queue->addElement(1.5));
	// 1 1 1
	printf("%d %d\n", queue->isEmpty(), queue->getSize());
	// 0 3
	printf("%d %d\n", queue->hasElement(0.5), queue->hasElement(0.25));
	// 1 0
	printf("%d %d\n", queue->removeElement(0.5), queue->removeElement(0.25));
	// 1 0
	printf("%d %d\n\n", queue->isEmpty(), queue->getSize());
	// 0 2
	delete queue;
	
	queue = new LinkedQueue<double>(1.5);
	printf("%d %d\n", queue->isEmpty(), queue->getSize());
	// 0 1
	printf("%d ", queue->addElementToHead(0.5));
	printf("%d ", queue->addElementToHead(2.5));
	printf("%d ", queue->addElementToTail(4.5));
	printf("%d\n", queue->addElementToTail(3.5));
	// 1 1 1 1
	printf("%d %d\n", queue->isEmpty(), queue->getSize());
	// 0 5
	printf("%lf %lf\n", queue->getHeadElement(), queue->getTailElement());
	// 2.5000 3.5000
	printf("%d %d\n", queue->removeHeadElement(), queue->removeTailElement());
	// 1 1
	printf("%lf %lf\n", queue->getHeadElement(), queue->getTailElement());
	// 0.5000 4.5000
	printf("%d %d\n", queue->isEmpty(), queue->getSize());
	// 0 3
	printf("%d\n", queue->removeAllElement());
	// 1
	printf("%d %d\n\n", queue->isEmpty(), queue->getSize());
	// 1 0
	
	return 0;
}
