#pragma once

template <typename KeyType, typename ValueType>
class NodeTree{
    private:
    std::pair<KeyType, ValueType> key_value;
    NodeTree<KeyType, ValueType>* parent;
    NodeTree<KeyType, ValueType>* left;
    NodeTree<KeyType, ValueType>* right;
    
    public:
    NodeTree(KeyType key, ValueType new_value):
        key_value(key, new_value),
        parent(nullptr),
        left(nullptr),
        right(nullptr)
    {}

    ~NodeTree(){
        key_value.first = 0;
        key_value.second = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        //this = nullptr;
    }

    KeyType getKey(){
        return key_value.first;
    }

    ValueType& getValue(){
        return key_value.first;
    }

    NodeTree<KeyType, ValueType>* getRightChild(){
        return right;
    }

    NodeTree<KeyType, ValueType>* getLeftChild(){
        return left;
    }

    NodeTree<KeyType, ValueType>* getParent(){
        return parent;
    }

    bool isLeftChild(){
        if(parent!=nullptr) return parent->getLeftChild() == this;
        else return false;
    }

    bool isRightChild(){
        if(parent!=nullptr) return parent->getRightChild() == this;
        else return false;
    }

    bool haveLeftChild(){
        return left != nullptr;
    }

    bool haveRightChild(){
        return right != nullptr;
    }

    void attachRight(NodeTree<KeyType, ValueType>* node_child){
        right = node_child;
        if (node_child != nullptr ) node_child->parent = this;
    }

    void attachLeft(NodeTree<KeyType, ValueType>* node_child){
        left = node_child;
        if (node_child != nullptr ) node_child->parent = this;
    }

    void attachParent(NodeTree<KeyType, ValueType>* node_parent){
        parent = node_parent;
    }
    void writeOut(){
        std::cout<<key_value.first<<"::"<<key_value.second;
    }
};