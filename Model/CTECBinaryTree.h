//
//  CTECBinaryTree.h
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 4/11/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#ifndef CTECBinaryTree_h
#define CTECBinaryTree_h

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    int size;
    bool balanced;
    bool contains(Type value, TreeNode<Type> * currentTree);
    void calculateSize(TreeNode<Type> * currentNode);
    TreeNode<Type> * getRightMostChild(TreeNode<Type> * leftSubTree);
    TreeNode<Type> * getLeftMostChild(TreeNode<Type> * rightSubTree);
    void remove(TreeNode<Type> * currentNode);
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    void remove (const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void inorderTransversal(TreeNode<Type> * currentNode);
    void postorderTransversal(TreeNode<Type> * currentNode);
    void preorderTransversal(TreeNode<Type> * currentNode);
};


#endif /* CTECBinaryTree_h */
