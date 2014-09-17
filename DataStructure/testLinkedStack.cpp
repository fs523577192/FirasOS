#include <iostream>
#include "Exception.cpp"
#include "LinkedStack.cpp"
int main(){
	LinkedStack<float> *stack = new LinkedStack<float>();
	printf("%d %d\n", stack->isEmpty(), stack->getSize());
	// 1 0
	printf("%d ", stack->addElement(2.5f));
	printf("%d ", stack->addElement(0.5f));
	printf("%d\n", stack->addElement(0.25f));
	// 1 1 1
	printf("%d %d\n", stack->isEmpty(), stack->getSize());
	// 0 3
	printf("%d %d\n", stack->hasElement(0.5f), stack->hasElement(1.0f));
	// 1 0
	printf("%d %d\n", stack->removeElement(0.5f), stack->removeElement(1.0f));
	// 1 0
	printf("%d %d\n\n", stack->isEmpty(), stack->getSize());
	// 0 2
	delete stack;
	
	stack = new LinkedStack<float>(1.5f);
	printf("%d %d\n", stack->isEmpty(), stack->getSize());
	// 0 1
	printf("%d ", stack->pushElement(0.5f));
	printf("%d ", stack->pushElement(0.25f));
	printf("%d\n", stack->pushElement(2.0f));
	// 1 1 1
	printf("%d %d\n", stack->isEmpty(), stack->getSize());
	// 0 4
	printf("%d %d\n", stack->hasElement(0.5f), stack->hasElement(1.0f));
	// 1 0
	printf("%f ", stack->popElement());
	printf("%f\n", stack->popElement());
	// 2.0000 0.2500
	printf("%d\n", stack->removeAllElement());
	// 1
	printf("%d %d\n\n", stack->isEmpty(), stack->getSize());
	// 1 0
	
	return 0;
}
