#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T>
T bst_min(const T &tree)
{
    // Function to find the minimum element in a BST
    // Given the root of the tree
    // Assuming it is a BST, so just need to find leftmost element
    // Initialising current node to the root
    
    // If left node is empty return the value
    if (!left(tree)){
        return tree;
    }
        
    // If left node is not empty, change current node (to left node)
    // If the left subtree is empty, then the minimum value is at the current node
    // Recursively search in the left subtree
    return bst_min(left(tree));
    
}

template <typename T>
T bst_max(const T &tree)
{
    // Function to find the maximum element in a BST
    // Given the root of the tree
    // Assuming it is a BST, so just need to find rightmost element
    if (!right(tree)){
        return tree;
    }

    return bst_max(right(tree));
}

#endif // __binary_saerch_tree_enhanced__