// Max Marcus and Michelle Soroka
// Data Structures
// Red Black Tree implementation and comparison project
// April 23

// TreeNode struct definition.
/* Also contains functions for working with node color and for finding related nodes within a tree. */

#include <cstdlib>
using namespace std;



// Color data type is used in the TreeNode of the RedBlackTree.
enum Color {red, black};



// TreeNode used in RedBlackTree class.
template <class ItemType>
struct TreeNode{
    ItemType info;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
    Color color;
};





// COLOR FUNCTIONS

template <class ItemType>
Color GetColor(TreeNode<ItemType> * node) {
    if (node == NULL) {
        return black;
        // ^ NULL node is considered black in red black tree.
    } else {
        return node->color;
    }
}

template <class ItemType>
void SwapColors(TreeNode<ItemType> * node1, TreeNode<ItemType> * node2) {
    Color color1 = GetColor<ItemType>(node1);
    Color color2 = GetColor<ItemType>(node2);
    node1->color = color2;
    node2->color = color1;
}






// TREE RELATIONSHIP FUNCTIONS

// parent
template <class ItemType>
TreeNode<ItemType> * Parent(TreeNode<ItemType> * node) {
    return node->parent;
}

// grandparent
template <class ItemType>
TreeNode<ItemType> * Grandparent(TreeNode<ItemType> * node) {
    
    if (node->parent == NULL) {
        return NULL;
    }
    else {
        return node->parent->parent;
    }
}

// uncle
template <class ItemType>
TreeNode<ItemType> * Uncle(TreeNode<ItemType> * node) {
    TreeNode<ItemType> * parent = Parent(node);
    TreeNode<ItemType> * grandparent = Grandparent(node);
    
    if (grandparent == NULL) {
        return NULL;
    }
    if (parent == grandparent->left) {
        return grandparent->right;
    }
    else { // parent == grandparent->right
        return grandparent->left;
    }
}
