#pragma once

#include "tree_BST.h"
#include "node_tree.h"
#include <cstdlib>

template<typename KeyType, typename ValueType>
void insert_test(TreeBST<KeyType, ValueType>& t){
    srand(time(NULL));
    int sizeTree = rand()%40 + 10;
    bool good = true;
    for(int i = 0; i<sizeTree; ++i){
        int a = rand()%200;
        t.insert(a, a);
        if(t.sizeTree() == i+1 ) ;
        else good = false;
    }
    std::cout<<"Test wstawiania\t"<<sizeTree<<" elementow:\t"<<std::boolalpha<<good<<"\n";
}

template<typename KeyType, typename ValueType>
void clear_test(TreeBST<KeyType, ValueType>& tree){
    
}

template<typename KeyType, typename ValueType>
void erase_test(TreeBST<KeyType, ValueType>& t){
    int nrElToEr = rand()%40 + 10;
    int startSize = t.sizeTree();
    bool good = true;
    for(int i = 0; i<nrElToEr; ++i){
        int a = rand()%200;
        if(t.eraseEl(a)){
            if(t.sizeTree() == --startSize) ;
            else good = false;
        }else
        {
            if(t.sizeTree() == startSize) ; 
            else good = true;
        }
        
    }

    std::cout<<"Test usuwania\t"<<nrElToEr<<" elementow:\t"<<std::boolalpha<<good<<"\n\t(nie musza byc w drzewie)\n";
}