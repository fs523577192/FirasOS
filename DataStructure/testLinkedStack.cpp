#include <iostream>
#include "Exception.cpp"
#include "LinkedStack.cpp"
int main(){
	LinkedStack<float> *stack = new LinkedStack<float>();
	std::cout << stack->isEmpty(), stack->getSize() << '\n';
	// 1 0
	std::cout << stack->addElement(2.5f) << ' ';
	std::cout << stack->addElement(0.5f) << ' ';
	std::cout << stack->addElement(0.25f) << '\n';
	// 1 1 1
	std::cout << stack->isEmpty() << ' ' << stack->getSize() << '\n';
	// 0 3
	std::cout << stack->hasElement(0.5f) << ' ';
	std::cout << stack->hasElement(1.0f) << '\n';
	// 1 0
	std::cout << stack->removeElement(0.5f) << ' ';
	std::cout << stack->removeElement(1.0f) << '\n';
	// 1 0
	std::cout << stack->isEmpty() << ' ' << stack->getSize();
	std::cout << '\n' << '\n';
	// 0 2
	delete stack;
	
	stack = new LinkedStack<float>(1.5f);
	std::cout << stack->isEmpty() << ' ' << stack->getSize() << '\n';
	// 0 1
	std::cout << stack->pushElement(0.5f) << ' ';
	std::cout << stack->pushElement(0.25f) << ' ';
	std::cout << stack->pushElement(2.0f) << '\n';
	// 1 1 1
	std::cout << stack->isEmpty() << ' ' << stack->getSize() << '\n';
	// 0 4
	std::cout << stack->hasElement(0.5f) << ' ';
	std::cout << stack->hasElement(1.0f) << '\n';
	// 1 0
	std::cout << stack->popElement() << '\t';
	std::cout << stack->popElement() << '\n';
	// 2	0.25
	std::cout << stack->removeAllElement() << '\n';
	// 1
	std::cout << stack->isEmpty() << ' ' << stack->getSize();
	std::cout << '\n' << '\n';
	// 1 0
	
	return 0;
}
