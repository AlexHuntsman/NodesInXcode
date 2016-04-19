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
CTECBinaryTree<Type>:: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
Type CTECBinaryTree<Type> :: remove(const Type &value)
{
   
    if(!contains(value))
    {
        return value;
    }
    else
    {
        /**
         find the node
         check if it has any kids
         else if only left
            replace with left
            delete old node
         else if only right
            replace with right
            delete old node
         else both
            find LMC/RMC
            swap with
            do left only or right only
         
         */
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: insert(const Type &value)
{
    TreeNode<Type> * insertedNode(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
        else
        {
            current = root;
            while (current != nullptr)
            {
                trailingCurrent = current;
                if (current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            if(trailingCurrent->getValue() > value)
            {
                trailingCurrent->setLeftChild(insertedNode);
                insertedNode->setParent(trailingCurrent);
            }
            else
            {
                trailingCurrent->setRightChild(insertedNode);
                insertedNode->setParent(trailingCurrent);
            }
               
        }
        return true;
    }
}

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







