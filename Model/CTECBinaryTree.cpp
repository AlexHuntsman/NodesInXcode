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
