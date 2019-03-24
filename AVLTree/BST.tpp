#include "BST.h"


template<typename T>
Node<T>* BST<T>::insert(Node<T>* curr, T value){
	if (curr == nullptr) return (new Node<T>(value));

	if (value < curr->value)
		curr->leftNode = insert(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = insert(curr->rightNode, value);

	return curr;
}

template<typename T>
void BST<T>::preorder(Node<T>* curr, std::function<void(T)> it){
	if (curr == nullptr) return;

	//std::cout << curr->value << " ";
	it(curr->value);
	preorder(curr->leftNode, it);
	preorder(curr->rightNode, it);
}

template<typename T>
void BST<T>::inorder(Node<T>* curr, std::function<void(T)> it){
	if (curr == nullptr) return;

	inorder(curr->leftNode, it);
	it(curr->value);
	//std::cout << curr->value << " ";
	inorder(curr->rightNode, it);
}

template<typename T>
Node<T>* BST<T>::remove(Node<T>* curr, T value){
	if (curr == nullptr) return curr;


	//recontrsuct the tree on the way up
	if (value < curr->value)
		curr->leftNode = remove(curr->leftNode, value);
	else if (value > curr->value)
		curr->rightNode = remove(curr->rightNode, value);
	else {
		//found the node, now deleting
		if (curr->leftNode == nullptr) {
			Node<T>* temp = curr->rightNode;
			delete curr;
			return temp;
		}
		if (curr->rightNode == nullptr) {
			Node<T>* temp = curr->leftNode;
			delete curr;
			return temp;
		}

		Node<T>* nxt = succ(curr);
		curr->value = nxt->value;

		curr->rightNode = remove(curr->rightNode, nxt->value);
	}

	return curr;

}

template<typename T>
Node<T>* BST<T>::succ(Node<T>* curr)
{
	curr = curr->rightNode;
	while (curr->leftNode != nullptr)
		curr = curr->leftNode;
	return curr;
}

template<typename T>
Node<T>* BST<T>::search(Node<T>* curr, T value) const {
	if (curr == nullptr) return nullptr;
	if (curr->value == value) return curr;
	if (curr->value < value)
		return search(curr->rightNode, value);
	return search(curr->leftNode, value);
}

template<typename T>
void BST<T>::traverse(Node<T>* curr, std::function<void(T)> it) const {
	if (curr == nullptr) return;
	
	//it(curr->value); /TODO change this back here in case of bugs
	traverse(curr->leftNode, it);
	it(curr->value);
	traverse(curr->rightNode, it);
	
}



template<typename T>
BST<T>::BST() {
	this->size = 0;
	this->root = nullptr;

}

template<typename T>
BST<T>::BST(T value){
	root = new Node<T>(value);
	size = 1;
}



template<typename T>
BST<T>::~BST(){
	if (root == nullptr || size <= 0 || size >= 1000) return;
	std::stack<Node<T>* > st;
	st.push(root);
	while (!st.empty()) {
		Node<T>* curr = st.top();

		st.pop();
		if (curr->rightNode != nullptr) st.push(curr->rightNode);
		if (curr->leftNode != nullptr) st.push(curr->leftNode);

		free(curr);
		curr = nullptr;
	}
	root = nullptr;
	size = 0;
	
}

template<typename T>
inline void BST<T>::insert(T value) {
	size++;
	root = insert(root, value);
}

template<typename T>
void BST<T>::remove(T value){
	size--;
	root = remove(root, value);
}

template<typename T>
bool BST<T>::search(T value) const {
	return (search(root, value) != nullptr);
}

template<typename T>
T BST<T>::maxVal(){
	Node<T>* it = root;
	if (it == nullptr) return T(); // because the avl comparator requires an value
	while (it->rightNode != nullptr)
		it = it->rightNode;
	return it->value;
}

template<typename T>
T* BST<T>::preorder(){
	T* rs= (T*)calloc(this->size, sizeof(T));
	int index = 0;
	preorder(root, [&](T value) {
		rs[index++] = value;
		});
	return rs;
}

template<typename T>
T* BST<T>::inorder(){
	T* rs = (T*)calloc(this->size, sizeof(T));
	int index = 0;
	inorder(root, [&](T value) {
		rs[index++] = value;
		});
	return rs;
}

template<typename T>
T* BST<T>::postorder(){
	T* rs = (T*)calloc(this->size, sizeof(T));
	int index = 0;
	postorder(root, [&](T value) {
		rs[index++] = value;
		});
	return rs;
}

template<typename T>
void BST<T>::postorder(Node<T>* curr, std::function<void(T)> it){
	if (curr == nullptr) return;

	postorder(curr->leftNode, it);
	postorder(curr->rightNode, it);
	it(curr->value);
	//std::cout << curr->value << " ";
}



