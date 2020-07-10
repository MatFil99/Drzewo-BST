#pragma once

#include <cstdlib>
#include "node_tree.h"
#include <random>

template <typename KeyType, typename ValueType>
class TreeBST{
    private:
    NodeTree<KeyType, ValueType>* root;
    int size;

    public:
    TreeBST():    root(nullptr), size(0){}
    ~TreeBST(){
        if(root!=nullptr){
            deallocating(root);
            size = 0;
        }
    }

    int sizeTree(){
        return size;
    }

    bool eraseEl(KeyType key){
        static short flag;
        NodeTree<KeyType, ValueType>* eraseEl = doSearching(root, key);
        ++flag;
        if( eraseEl == nullptr ) return false;
        if(flag%2){
            if(!swapConsequent(eraseEl)){
                if(!swapAntecedent(eraseEl)){
                    if(eraseEl->isLeftChild()) eraseEl->getParent()->attachLeft(nullptr);
                    else if(eraseEl->isRightChild()) eraseEl->getParent()->attachRight(nullptr);
                }
                
            }
        }else{
            if(!swapAntecedent(eraseEl)){
                if(!swapConsequent(eraseEl)){
                    if(eraseEl->isLeftChild()) eraseEl->getParent()->attachLeft(nullptr);
                    else if(eraseEl->isRightChild()) eraseEl->getParent()->attachRight(nullptr);
                }
                
            }
        }
        delete eraseEl;
        eraseEl = nullptr;
        --size;
        if(size == 0) root = nullptr;
        return true;
    }

    bool swapConsequent(NodeTree<KeyType, ValueType>* eraseEl){
        NodeTree<KeyType, ValueType>* conseq = getConsequent(eraseEl);
            if(conseq!=nullptr && conseq != eraseEl){
                if( conseq != eraseEl->getRightChild() ){
                    conseq->getParent()->attachLeft(conseq->getRightChild());
                    conseq->attachRight(eraseEl->getRightChild());
                    
                }
                
                if(eraseEl != root ){
                    if(eraseEl->isLeftChild()){
                        eraseEl->getParent()->attachLeft(conseq);
                    }else{
                        eraseEl->getParent()->attachRight(conseq);
                    }
                }else{
                    conseq->attachParent(nullptr);
                    root = conseq;
                }
                conseq->attachLeft(eraseEl->getLeftChild());
                return true;
            }
            return false;
    }

    bool swapAntecedent(NodeTree<KeyType, ValueType>* eraseEl){
            NodeTree<KeyType, ValueType>* antec = getAntecedent(eraseEl);
            if(antec!=nullptr && antec != eraseEl){
                if( antec != eraseEl->getLeftChild() ){
                    antec->getParent()->attachRight(antec->getLeftChild());
                    antec->attachLeft(eraseEl->getLeftChild());
                }
                if(eraseEl != root ){
                    if(eraseEl->isLeftChild()){
                        eraseEl->getParent()->attachLeft(antec);
                    }else{
                        eraseEl->getParent()->attachRight(antec);
                    }
                }else{
                    antec->attachParent(nullptr);
                    root = antec;
                }
                antec->attachRight(eraseEl->getRightChild());
                return true;
            }
        return false;
    }

    NodeTree<KeyType,ValueType>* getConsequent(NodeTree<KeyType, ValueType>* node){
        NodeTree<KeyType, ValueType>* conseq = node->getRightChild();
        if(conseq != nullptr){
            while(conseq->getLeftChild() != nullptr ){
                conseq = conseq->getLeftChild();
            }
        }
        return conseq;
    }

    NodeTree<KeyType,ValueType>* getAntecedent(NodeTree<KeyType, ValueType>* node){
        NodeTree<KeyType, ValueType>* antec = node->getLeftChild();
        if(antec != nullptr){
            while(antec->getRightChild() != nullptr ){
                antec = antec->getRightChild();
            }
        }
        return antec;
    }

    NodeTree<KeyType, ValueType>* search( KeyType key){
        return doSearching(root, key);
    }

    NodeTree<KeyType, ValueType>* doSearching(NodeTree<KeyType, ValueType>* el, KeyType key){
        if(el != nullptr){
            if(el->getKey() == key) return el;
            else{
                if(el->getKey()>key) doSearching(el->getLeftChild(), key);
                else doSearching(el->getRightChild(), key);
            }
        }
        return nullptr;
    }

    void insert(KeyType k, ValueType v){
        NodeTree<KeyType, ValueType>* new_el = createNode(k, v);
        if( root == nullptr ){
            root = new_el;
            ++size;
        }else{
            doInsertion(root, new_el);
            ++size;
        }

    }

    void writeOut(){
        if(root!=nullptr){
            doWriting(root);
        }
    }


    void doWriting(NodeTree<KeyType, ValueType>* el){
        if(el->haveLeftChild()){
            doWriting(el->getLeftChild());
        }
        if(el->haveRightChild()){
            doWriting(el->getRightChild());
        }
        el->writeOut();
        std::cout<<"\n";
    }

//private:
    void doInsertion(NodeTree<KeyType, ValueType>* node_a, NodeTree<KeyType, ValueType>* new_el){
        if(node_a->getKey()>new_el->getKey()){
            if(node_a->haveLeftChild()){
                doInsertion(node_a->getLeftChild(), new_el);
            }else
            node_a->attachLeft(new_el);
        }else{
            if(node_a->haveRightChild()){
                doInsertion(node_a->getRightChild(), new_el);
            }else
            node_a->attachRight(new_el);
        }
    }

//private:
    NodeTree<KeyType, ValueType>* createNode(KeyType key, ValueType value){
        return new NodeTree<KeyType, ValueType>(key, value);
    }



//private:
    void deallocating(NodeTree<KeyType, ValueType>* node_del){
        if(node_del->haveLeftChild() ){
            deallocating(node_del->getLeftChild());
        }
        if(node_del->haveRightChild() ){
            deallocating(node_del->getRightChild());
        }
        delete node_del;
        node_del = nullptr;
    }

    void eraseTree(){
        if(root != nullptr ){
            deallocating(root);
            root = nullptr;
            size = 0;
        }
    }

   

};