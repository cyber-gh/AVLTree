#include "AVL.h"

template<typename T>
Node<T>* insert(Node<T>* curr, T value) {
	std::cout << "called internal isnert";
}

template<typename T>
Node<T>* AVL<T>::leftRotate(Node<T>* curr){
	Node<T>* rightSonCurr = curr->rightNode;
	Node<T>* leftSonOfRightSonCurr = rightSonCurr->leftNode;
	
	rightSonCurr->leftNode = curr;
	curr->rightNode = leftSonOfRightSonCurr;

	curr->updateHeight();
	rightSonCurr->updateHeight();

	return rightSonCurr;
}

template<typename T>
Node<T>* AVL<T>::rightRotate(Node<T>* curr){
	Node<T>* leftSonCur = curr->leftNode;
	Node<T>* rightSonOfLeftSonCurr = curr->rightNode;

	leftSonCur->rightNode = curr;
	curr->leftNode = rightSonOfLeftSonCurr;

	curr->updateHeight();
	leftSonCur->updateHeight();

	return leftSonCur;
}
