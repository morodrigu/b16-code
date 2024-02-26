#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;
    BinaryTreeEnhanced<V>* _parent;     // Added _parent. This is just a normal pointer

    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_left_value;
    }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        // Member function that returns the parent of a node
        return t->_parent;  // _parent is a normal pointer so can return directly (without .get())
    }

};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
    // Allocate memory for the tree
    std::unique_ptr<BinaryTreeEnhanced<V>> newTree(new BinaryTreeEnhanced<V>());       // new is used to dynamically allocate - no segmentation fault

    // Set left and right nodes of tree to l and r
    newTree->_value = value;

    // Set given l and r to _left and _right of the new tree
    // Use std::move for l and r because _left and _right are unique pointers
    newTree->_left  = std::move(l);
    newTree->_right = std::move(r);
    
    // if _left is not null, set the parent of _left to be tree
    if(newTree->_left)
    {
        newTree->_left->_parent = newTree.get();        // unique pointer to the tree, so use get
    }
    if(newTree ->_right)
    {
        newTree->_right->_parent = newTree.get();       // unique pointer to the tree, so use get
    }

    return newTree;
}


#endif // __binary_tree_enhanced__;