// Max Marcus and Michelle Soroka
// Data Structures
// Red Black Tree implementation and comparison project
// April 23

// Helper functions.

#include <iostream>
#include "rotations.h"

using namespace std;

template <class ItemType> void ReStructure(TreeNode<ItemType> * node);



// ReColor()
// Algorithm is based on the textbook.
template <class ItemType>
void ReColor(TreeNode<ItemType> * node) {
    
    if (node->parent == NULL) { // ie, node is tree root.
        node->color = black;
        }
    
    if (GetColor(node->parent) == red) {
        TreeNode<ItemType> * grandparent = Grandparent(node);
        TreeNode<ItemType> * uncle = Uncle(node);
        
        // if parent and uncle both are red
        if (GetColor(uncle) == red) {
            node->parent->color = black;
            uncle->color = black;
            grandparent->color = red;
            ReColor(grandparent);
        }
        
        // if parent is red but uncle is black
        else {
            ReStructure(node);
        }
    }
}




template <class ItemType>
void ReStructure(TreeNode<ItemType> * node) {
    TreeNode<ItemType> * uncle = Uncle(node);
    TreeNode<ItemType> * grandparent = Grandparent(node);
    TreeNode<ItemType> * parent = node->parent;

    if ( (node == parent->left) and (parent == grandparent->left) ) {
        RotateRight(grandparent);
        SwapColors(grandparent, parent);
    }
    if ( (node == parent->right) and (parent == grandparent->left) ) {
        RotateLeftRight(parent);
        SwapColors(grandparent, node);
    }
    if ( (node == parent->right) and (parent == grandparent->right) ) {
        RotateLeft(grandparent);
        SwapColors(grandparent, parent);
    }
    if ( (node == parent->left) and (parent == grandparent->right) ) {
        RotateRightLeft(parent);
        SwapColors(grandparent, node);
    }
}
