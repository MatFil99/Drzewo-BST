#include <iostream>


#include "tree_BST.h"
#include "node_tree.h"
#include "test_tree.h"


int main(){
    srand(time(NULL));

    TreeBST<int, int> t;

    insert_test(t);
    erase_test(t);

    return 0;
}