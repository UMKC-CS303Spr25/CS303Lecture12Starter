#pragma once

#include <sstream>


/** A node for a Binary Tree. */
template<typename ItemType>
struct BTNode
{
	// Data Fields
	ItemType data;
	BTNode<ItemType>* left;
	BTNode<ItemType>* right;

	// Constructor
	BTNode(const ItemType& theData,
		BTNode<ItemType>* leftVal = nullptr,
		BTNode<ItemType>* rightVal = nullptr) :
		data(theData), left(leftVal), right(rightVal) {}

	// Destructor (to avoid warning message)
	virtual ~BTNode() {}

	virtual std::string to_string() const {
		std::ostringstream os;
		os << data;
		return os.str();
	}
}; // End BTNode

template<typename ItemType>
std::ostream& operator<<(std::ostream& out, const BTNode<ItemType>& node) {
	return out << node.to_string();
}
