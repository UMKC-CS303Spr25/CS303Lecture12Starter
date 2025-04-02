// CS303Lecture12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//https://github.com/UMKC-CS303Spr25/CS303Lecture12Starter

#include "BTNode.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream inFile("input3.txt");
    if (!inFile.good()) {
        cout << "Error opening file\n";
        return 0;
    }

    BinarySearchTree<string> myTree;
    //BinaryTree<string> myTree;
    inFile >> myTree;

    //LECTURE 11 TASKS
    cout << "PreOrder:  " << myTree.preOrder() << endl;

    //TASK 1
    cout << "PostOrder: " << myTree.postOrder() << endl;
    //TASK 2
    cout << "InOrder:   " << myTree.inOrder() << endl;
    //TASK 3
    cout << "Height:    " << myTree.height() << endl;
    //TASK 4
    cout << "Depth:     " << myTree.depth("milked") << endl;
    //TASK 5
    cout << "FullTree:  " << myTree.fullTree() << endl;


    //LECTURE 12 TASKS
    //TASK 1 Find
    string findKey = "killed";
    string* keyFound = myTree.find(findKey);
     
    if (keyFound == nullptr)
        cout << "Unable to find value: " << findKey << "\n";
    else
        cout << "Found key value: " << *keyFound << endl;
    /*
    //TASK 2 Find Min & Max Numbers
    cout << "Min Value: " << *(myTree.findMin()) << endl;
    cout << "Max Value: " << *(myTree.findMax()) << endl;


    //TASK 3 Get Vector
    vector<string> theList = myTree.getVector();
    for (auto i : theList)
        cout << i << " ";
    cout << endl;


    //TASK 4 Insert
    string insertKey = "jill";
    if (myTree.insert(insertKey))
        cout << "New value inserted: " << insertKey << "\n";
    else
        cout << "Unable to insert value: " << insertKey << "\n";


    //TASK 5 Convert sorted vector into a tree

    vector<int> newList = { 2, 7, 9, 10, 20, 30 };
    BinarySearchTree<int> myNewTree = myNewTree.readFromVector(newList);

    cout << "InOrder:   " << myNewTree.inOrder() << endl;

    //TASK 6: Deleting an element from the tree
    myNewTree.erase(9);

    cout << "InOrder:   " << myNewTree.inOrder() << endl;


    //TASK 3 Get Vector
    vector<int> newList2 = myNewTree.getVector();
    for (auto i : newList2)
        cout << i << " ";
    cout << endl;
    */
}

