#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>

#include "BTNode.h"

template<typename ItemType>
class BinaryTree{
protected:
	// Data Field
    BTNode<ItemType>* root;

    // Protected constructor (given a root)
    //   used so that a BinaryTree can only be instantiated 
    //   is by a derived or friend class
    BinaryTree(BTNode<ItemType>* newRoot) :
        root(newRoot) {}
    
public:
	BinaryTree() :
		root(nullptr) {}

	BinaryTree(const ItemType& theData,
		const BinaryTree<ItemType>& left = BinaryTree(),
		const BinaryTree<ItemType>& right = BinaryTree()) :
		root(new BTNode<ItemType>(theData, left.root, right.root)) {}
 
    //the destructor is virtual so the derived class
    //destructor will be called first
    virtual ~BinaryTree() {}

    const ItemType& getData() const;
	
	BinaryTree<ItemType>  getLeft() const;
	BinaryTree<ItemType>  getRight() const;
	bool isLeaf() const;
	bool isNull() const;
	virtual std::string to_string() const;


    static BinaryTree<ItemType> readBinaryTree(std::istream& in);
    std::string rootToString() const {return root->to_string(); }
    std::string preOrder() const { return preOrder(root); }     //wrapper function
    std::string inOrder() const { return inOrder(root); }     //wrapper function
    std::string postOrder() const { return postOrder(root); }   //wrapper function
    int height() const;
    int depth(ItemType item) const { return depth(this->root, item, 0); } //wrapper function
    bool fullTree() const { return fullTree(root); } //wrapper function


private:

    std::string preOrder(const BTNode<ItemType>* local_root) const;
    std::string inOrder(const BTNode<ItemType>* local_root) const;
    std::string postOrder(const BTNode<ItemType>* local_root) const;
    int depth(const BTNode<ItemType>* root, ItemType item, int itemDepth) const; 
    bool fullTree(const BTNode<ItemType>* root) const;
};

//PRE:  None
//POST: returns a string contining the binary tree fields
template<typename ItemType>
std::string BinaryTree<ItemType>::to_string() const {

    std::ostringstream outStream;

    if (isNull())
        outStream << "NULL\n";
    else {
        outStream << *root << "\n";
        outStream << getLeft().to_string();
        outStream << getRight().to_string();
    }
    return outStream.str();
}

//PRE:  None
//POST: use to output an stream to 'out'
template<typename ItemType>
std::ostream& operator<<(std::ostream& out,
    const BinaryTree<ItemType>& tree) {
    return out << tree.to_string();
}

// Overloading the istream extraction operator
template<typename ItemType>
std::istream& operator>>(std::istream& in,
    BinaryTree<ItemType>& tree) {
    tree = BinaryTree<ItemType>::readBinaryTree(in);
    return in;
}
//PRE: accepts an input stream assumed to be space delineated
//POST: reads each field. 
//      if NULL is encountered - the left or right pointers is set to an empty tree
//      otherise get additional data
template<typename ItemType>
BinaryTree<ItemType> BinaryTree<ItemType>::readBinaryTree(std::istream& in) {
    std::string next_line;

    getline(in, next_line);
    if (next_line == "NULL") {
        return BinaryTree<ItemType>();
    }
    else {
        ItemType the_data;
        std::istringstream ins(next_line);
        ins >> the_data;
        BinaryTree<ItemType> left = readBinaryTree(in);
        BinaryTree<ItemType> right = readBinaryTree(in);
        std::cout << the_data << " ::: ";
        if (!(left.isNull()))
            std::cout << left.getData() << " : ";
        if (!(right.isNull()))
            std::cout << right.getData() << " : ";
        std::cout << std::endl;
        return BinaryTree<ItemType>(the_data, left, right);
    }
}
//PRE: none
//POST: returns the value at the current root position
template<typename ItemType>
const ItemType& BinaryTree<ItemType>::getData() const {
    if (root == nullptr) {
        throw std::invalid_argument("get_data on null tree");
    }
    return root->data;
}
//PRE: none
//POST: returns the binary tree at root->left
template<typename ItemType>
BinaryTree<ItemType> BinaryTree<ItemType>::getLeft() const  {
	if (root == nullptr)
		throw std::runtime_error("Unable to return left subtree");

	return BinaryTree<ItemType>(root->left);
}

//PRE: none
//POST: returns the binary tree at root->right
template<typename ItemType>
BinaryTree<ItemType> BinaryTree<ItemType>::getRight() const {
	if (root == nullptr)
		throw std::runtime_error("Unable to return right subtree");

	return BinaryTree<ItemType>(root->right);
}

//PRE: none
//POST: returns true if both left & right pointers are nullptr
template<typename ItemType>
bool BinaryTree<ItemType>::isLeaf() const {
	if (root != nullptr)
		return (root->left == nullptr && root->right == nullptr);

	return true;
}

//PRE: none
//POST: returns true if root is nullptr
template<typename ItemType>
bool BinaryTree<ItemType>::isNull() const {
	return (root == nullptr);
}





template<typename ItemType>
std::string BinaryTree<ItemType>::preOrder(const BTNode<ItemType>* local_root) const {
    std::string result;
    if (local_root != nullptr) {
        result += local_root->to_string();
        if (local_root->left != nullptr) {
            result += " ";
            result += preOrder(local_root->left);
        }
        if (local_root->right != nullptr) {
            result += " ";
            result += preOrder(local_root->right);
        }
    }
    return result;
}

//TASK 1
//PRE: none
//POST: base case: tree is empty
//      otherise visit left, visit node, visit right
template<typename ItemType>
std::string BinaryTree<ItemType>::inOrder(const BTNode<ItemType>* local_root) const {
    std::string result;
    if (local_root != nullptr) {
        if (local_root->left != nullptr) {
            result += inOrder(local_root->left);
            result += " ";
        }
        result += local_root->to_string();
        if (local_root->right != nullptr) {
            result += " ";
            result += inOrder(local_root->right);
        }
    }
    return result;
}

//TASK 2
//PRE: none
//POST: base case: tree is empty
//      otherise visit left,visit right,visit node
template<typename ItemType>
std::string BinaryTree<ItemType>::postOrder(const BTNode<ItemType>* local_root) const {
    std::string result;
    if (local_root != nullptr) {
        if (local_root->left != nullptr) {
            result += postOrder(local_root->left);
            result += " ";
        }
        if (local_root->right != nullptr) {
            result += postOrder(local_root->right);
            result += " ";
        }
        result += local_root->to_string();
    }
    return result;
}


//TASK 3
//PRE: none
//POST: returns the height of the tree
template<typename ItemType>
int BinaryTree<ItemType>::height() const {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(getLeft().height(), getRight().height());
}

//TASK 4
//PRE: takes in the item to find
//POST: returns the depth of the node or -1 if not found
template<typename ItemType>
int BinaryTree<ItemType>::depth(const BTNode<ItemType>*root, ItemType item, int itemDepth) const {

    // node not found
    if (root == nullptr)
       return -1;

    // return current depth if found
    if (root->data == item)
       return itemDepth;

    // check left side of current root & return depth if found
    int leftDepth = depth(root->left, item, itemDepth + 1);
    if (leftDepth != -1)
      return leftDepth;

    // check right side of current root & return depth if found
    // or -1 if not
    return depth(root->right, item, itemDepth + 1);
    
}

//TASK 5
//PRE: uses a wrapper function to start at root
//POST: returns true if every leaf has nullptr for left & right ptr
template<typename ItemType>
bool BinaryTree<ItemType>::fullTree(const BTNode<ItemType>* root) const {
    if (root == nullptr)
        return true;

    bool result = ((root->left == nullptr && root->right == nullptr)
                || (root->left != nullptr && root->right != nullptr));

    return result && fullTree(root->left) && fullTree(root->right);
}
