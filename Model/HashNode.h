//
//  HashNode.hpp
//  NodesInXcode
//
//  Created by Huntsman, Alexander on 5/11/16.
//  Copyright © 2016 Huntsman, Alexander. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include <stdio.h>

#endif /* HashNode_h */

template<class Type>
class HashNode
{
private:
    int key;
    Type value;
    
public:
    HashNode();
    HashNode<Type>(int key, const Type& value);
    void setKey(int key);
    void setValue(const Type& value);
    int getKey();
    Type getValue();
};