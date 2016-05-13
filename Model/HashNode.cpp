//
//  HashNode.cpp
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 5/11/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#include "HashNode.h"
template<class Type>
HashNode<Type> :: HashNode()
{
    
}

template<class Type>
HashNode<Type> :: HashNode(int key, const Type& value)
{
    this->key = key;
    this->value = value;
}

template<class Type>
int HashNode<Type> :: getKey()
{
    return this->key;
}

template<class Type>
Type HashNode<Type> :: getValue()
{
    return this->value;
}
