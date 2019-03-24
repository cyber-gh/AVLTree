#include "AVL.h"

template<typename T>
Node<T>* AVL<T>::insert(Node<T>* curr, T value) {
	if (curr == nullptr) return (new Node<T>(value));

	if (value < curr->value)
		curr->leftNode = insert(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = insert(curr->rightNode, value);
	else return curr;

	curr->updateHeight();

	int balance = Node<T>::getBalance(curr);

	// left heavy
	if (balance > 1) {
		if (value < curr->leftNode->value)
			return rightRotate(curr);
		if (value > curr->leftNode->value) {
			curr->leftNode = leftRotate(curr->leftNode);
			return rightRotate(curr);
		}
	}

	// right heavy
	if (balance < -1) {
		if (value > curr->rightNode->value)
			return leftRotate(curr);
		if (value < curr -> rightNode->value) {
			curr->rightNode = rightRotate(curr->rightNode);
			return leftRotate(curr);
		}
	}

	// if is balanced return and go up
	return curr;

}

template<typename T>
Node<T>* AVL<T>::remove(Node<T>* curr, T value){
	// same as bst remove
	if (curr == nullptr) 
		return curr;

	if (value < curr->value)
		curr->leftNode = remove(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = remove(curr->rightNode, value);
	else {
		//found it, now deleting

		//only one child
		if (curr->leftNode == nullptr || curr->rightNode == nullptr) {
			Node<T>* temp = (curr->leftNode == nullptr) ? curr->rightNode : curr->leftNode;

			// no child
			if (temp == nullptr) {
				temp = curr;
				curr = nullptr;
			}
			else {
				curr = temp;
				free(temp);
			}
		}
		else {
			//both children, find succ
			Node<T>* temp =this->succ(curr);
			curr->value = temp->value;
			curr->rightNode = remove(curr->rightNode, temp->value);
			free(temp);
		}
	}

	if (curr == nullptr)
		return curr;

	curr->updateHeight();

	int balance = Node<T>::getBalance(curr);
	if (balance > 1 && Node<T>::getBalance(curr->leftNode) >= 0) {
		return rightRotate(curr);
	}

	if (balance > 1 && Node<T>::getBalance(curr->leftNode) < 0) {
		curr->leftNode = leftRotate(curr->leftNode);
		return rightRotate(curr);
	}

	if (balance < -1 && Node<T>::getBalance(curr->rightNode) <= 0) {
		return leftRotate(curr);
	}

	if (balance < -1 && Node<T>::getBalance(curr->rightNode) > 0) {
		curr->rightNode = rightRotate(curr->rightNode);
		return leftRotate(curr);
	}

	return curr;

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

template<typename T>
inline void AVL<T>::insert(T value) {
	this->size++;
	this->root = insert(this->root, value);
}

template<typename T>
void AVL<T>::remove(T value){
	this->size--;
	this->root = remove(this->root, value);
}

template<typename T>
AVL<T>& AVL<T>::operator=(AVL<T> other)
{
	std::swap(this->root, other.root);
	std::swap(this->size, other.size);
	return *this;
}

template<typename T>
bool operator>(AVL<T>& lhs,AVL<T>& rhs) {
	if (lhs.maxVal() > rhs.maxVal()) return true;
	return false;
}

template<typename T>
bool operator<(AVL<T>& lhs, AVL<T>& rhs) {
	if (lhs.maxVal() < rhs.maxVal()) return true;
	return false;
}

template<typename T>
AVL<T>::AVL(const AVL<T>& other) {
	this->root = nullptr;
	this->size = 0;
	other.traverse([&](T value) {
		insert(value);
		});


}

template<typename T>
AVL<T>& AVL<T>::operator+=(const AVL<T>& other)
{
	other.traverse([&](T value) {
		insert(value);
		});

	return *this;
}

template<typename T>
AVL<T> AVL<T>::operator+(const AVL<T>& other)
{
	AVL<T> res(*this);
	res += other;
	return res;
}

template<typename T>
AVL<T>& AVL<T>::operator-=(const AVL<T>& other)
{
	std::vector<T> toDelete;

	this->traverse([&](T value) {
		if (other.search(value)) toDelete.push_back(value);

		});
	for (auto it : toDelete)
		remove(it);
	toDelete.clear();

	return *this;
	
}

template<typename T>
AVL<T> AVL<T>::operator-(const AVL<T>& other)
{
	AVL<T> res(*this);
	res -= other;
	return res;
}

template<typename T>
std::ostream& operator <<(std::ostream& output, const AVL<T>& avl) {
	output << "AVL: size = " << avl.sz() << std::endl;
	avl.traverse([&](T value) {
		output << value << " ";
		});
	output << std::endl;
	return output;
}

template<typename T>
std::istream& operator >>(std::istream& input, AVL<T>& avl) {
	int size = 0;
	input >> size;
	for (T value; size--;) {
		input >> value;
		avl.insert(value);
	}
	return input;
}