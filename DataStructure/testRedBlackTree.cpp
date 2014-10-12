#include <iostream>
#include "RedBlackTree.cpp"
int main(){
	RedBlack<double> *tree = new RedBlack<double>();
	std::cout << tree->isEmpty() << '\t' << tree->getSize() << '\n';
	
	return 0;
}
