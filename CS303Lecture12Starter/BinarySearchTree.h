#pragma once
#include "BinaryTree.h"
#include <vector>
#include <sstream>


template<typename ItemType>
class BinarySearchTree : public BinaryTree<ItemType> {

public:
	ItemType* find(const ItemType& item) { return find(this->root, item); }
	ItemType* findMin() { return findMin(this->root); }
	ItemType* findMax() { return findMax(this->root); }
	std::vector<ItemType> getVector();
	bool insert(const ItemType& item) { return insert(this->root, item); }
	BinarySearchTree<ItemType> readFromVector(std::vector<ItemType>&);
	bool erase(const ItemType& item) { return erase(this->root, item); }

private:
	ItemType* find(BTNode<ItemType>* root, const ItemType&);
	ItemType* findMin(BTNode<ItemType>* root);
	ItemType* findMax(BTNode<ItemType>* root);
	bool insert(BTNode<ItemType>* &root, const ItemType&);
	BTNode<ItemType>* readFromVector(std::vector<ItemType>&, int f, int l);
	bool erase(BTNode<ItemType>* root, const ItemType&);
};
//TASK 1
//PRE: sends in pointer to current root & item to find
//POST: if root is null, return null
//      if value found return root->data
//      if value < current data search left
//      if value > current data search right

template<typename ItemType>
ItemType* BinarySearchTree<ItemType>::find(BTNode<ItemType>* root, const ItemType& item) {

	//if root is null, return null
	if (root == nullptr)
		return nullptr;

	//if value found return root->data
 

	//else determine which side the element should be
 

}
//TASK 2
//PRE: none
//POST: if the tree is empty, return nullptr
//      else return address of the leftmost node
template<typename ItemType>
ItemType* BinarySearchTree<ItemType>::findMin(BTNode<ItemType>* root) {

	//Base case 1: if root is null, return null
	if (root == nullptr)
		return nullptr;
	
	//Base case 2: if the left ptr is nullptr, return address of minimum value
	if (root->left == nullptr)
		return &root->data;

	//recursive call to findMin of left pointer
	return findMin(root->left);

}

//TASK 2
//PRE: none
//POST: if the tree is empty, return nullptr
//      else return the address of the righttmost node
template<typename ItemType>
ItemType* BinarySearchTree<ItemType>::findMax(BTNode<ItemType>* root) {
	cout << "Code this!\n";
	//Base case 1: if root is null, return null
	if (root == nullptr)
		return nullptr;

	//Base case 2: if right ptr is nullptr, return address of data (max value)
 

	//recursive call to find max of right side
 

}

//TASK 3
//PRE: None
//POST: Converts the existing tree into a sorted vector using inOrder function
template<typename ItemType>
std::vector<ItemType> BinarySearchTree<ItemType>::getVector() {
	std::vector<ItemType> theList;
	ItemType tempStr;

	//save inorder listing to a string 
	std::string inOrder = BinaryTree<ItemType>::inOrder();

	//convert to stringstream
	//get each value push onto the return vector
	std::stringstream inSS(inOrder);
	while (inSS >> tempStr) {
		theList.push_back(tempStr);
	}
	return theList;
}

//TASK 4
//PRE:  Accepts Item to insert
//POST: if the current root is null - insert here
//		recursively look for where to insert the item 
//      if item exists in the tree, return false.

template<typename ItemType>
bool BinarySearchTree<ItemType>::insert(BTNode<ItemType>* &root, const ItemType& item) {

	cout << "Code this!\n";

	if (root == nullptr) {
		root = new BTNode<ItemType>(item);
		return true;
	}

	//if item is > data at the current node ->go right

	//else if the item is < data at current node ->go left

	//else the item is in the tree, return false

}
//TASK 5
//Wrapper Function
template<typename ItemType>
BinarySearchTree<ItemType> BinarySearchTree<ItemType>::readFromVector(std::vector<ItemType>& v1) {

	if (v1.size() == 0)
		throw std::runtime_error("vector is empty");

	BTNode<ItemType>* newBSTRoot = readFromVector(v1, 0, v1.size() - 1);
	BinarySearchTree<ItemType> newBST;
	newBST.root = newBSTRoot;

	return newBST;
}

//PRE: accepts a vector (not empty) starting position, ending position
//POST: recursively calls the function with changing start & end positions
//      until 1 node is left
//      creates the node with left & right pointer values

template<typename ItemType>
BTNode<ItemType>* BinarySearchTree<ItemType>::readFromVector(std::vector<ItemType> & v1, int first, int last) {

	int mid = (first + last) / 2;
	BTNode<ItemType>* root = nullptr;
	BTNode<ItemType>* leftPtr = nullptr;
	BTNode<ItemType>* rightPtr = nullptr;

	cout << "Code this!\n";

	return root;
}
//TASK 6
//PRE: accepts original root & next root value
//POST: find largest node in left subtree
//      swap the value with oldRoot (value being deleted)
template<typename ItemType>
void replaceParent(BTNode<ItemType>*& oldRoot, BTNode<ItemType>*& root) {

	if (root->right != NULL) {
		replaceParent(oldRoot, root->right);
	}
	else {
		//swap the old root with the maximum of
		//the left subtree
		oldRoot->data = root->data;
		oldRoot = root;
		root = root->left;
	}
}

//TASK 6
//PRE:  pass in the next node to check with value to delete
//POST: case 1: Item is not in the node
//      case 2: item is a leaf
//      case 3: item is non-leaf with 1 child
//      case 4: item has two children

template<typename ItemType>
bool BinarySearchTree<ItemType>::erase(BTNode<ItemType>* root, const ItemType& item) {
	
	//case 1: Item is not in the tree
	if (root == nullptr)
		return false;
	
	//if item is less - item to erase is left 


	//if item is greater - item to erase is right
 

 
	else {
		BTNode<ItemType>* oldNode = root;

		//  item is non-leaf with 1 child
		//  replace root with remaining child
		if (root->left == nullptr)
			root = root->right;
		else if (root->right == nullptr)
			root = root->left;

		//  item is non-leaf with 2 children
		//  go to replaceParent (finds largest
		//  element in left tree & swaps values)
		else {
			replaceParent(oldNode, oldNode->left);
			delete oldNode;
			return true;
		}
	}

}

