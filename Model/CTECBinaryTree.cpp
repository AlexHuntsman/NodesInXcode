//
//  CTECBinaryTree.cpp
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 4/11/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#include "CTECBinaryTree.h"

using namespace std;

template <class Type>
void CTECBinaryTree<Type> :: inorderTransversal(TreeNode<Type> *currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTransversal(currentNode->getLeftChild());
        cout << currentNode->getValue << " " ;
        inorderTransversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: preorderTransversal(TreeNode<Type> *currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue << " " ;
        preorderTransversal(currentNode->getLeftChild());
        preorderTransversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: postorderTransversal(TreeNode<Type> *currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTransversal(currentNode->getLeftChild());
        postorderTransversal(currentNode->getRightChild());
        cout << currentNode->getValue << " " ;
    }
}

template <class Type>
int CTECBinaryTree<Type> :: getSize()
{
    size = calculateSize(root);
    return size;
}

template<class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        size++;
    }
    
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    bool isInTree = false;
    if(root->getValue() == value)
    {
        isInTree = true;
    }
    else if(value <root->getLeftChild())
    {
        isInTree = contains(value, root->getleftChild());
    }
    else
    {
        isInTree = contains(value, root->getRightChild());

    }
    return isInTree;
}


template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    if(currentTree == nullptr)
    {
        return false;
    }
    if(currentTree->getRoot()->getValue() == value)
    {
        return true;
    }
    else if(value < currentTree->getRoot()->getValue())
    {
        return contains(value, currentTree->getRoot()->getleftChild());
    }
    else
    {
        return contains(value, currentTree->getRoot()->getRightChild());
        
    }
    return false;
}



