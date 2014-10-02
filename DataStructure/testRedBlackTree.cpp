#include <iostream>
#include "RedBlackTree.cpp"
int main(){
	RedBlack<double> *tree = new RedBlack<double>();
	printf("%d %d\n", tree->isEmpty(), tree->getSize());
	
	return 0;
}
