// Max Marcus and Michelle Soroka
// Data Structures
// Red Black Tree implementation and comparison project
// April 23

// RedBlackTree class interface.

#include "treenode.h"
#include "helperFunctions.h"
using namespace std;



template <class ItemType>
class RedBlackTree {
    
    private:
    TreeNode<ItemType> * root;
    
    public:
    RedBlackTree() {root = NULL;}
    bool IsInTree(ItemType checkThis);
    void AddItem(ItemType addThis);
};



// CLASS METHODS
/* IsInTree and AddItem methods perform binary search via iteration. AddItem uses helper functions that are defined in the header file. */


template <class ItemType>
bool RedBlackTree<ItemType> :: IsInTree(ItemType checkThis) {
    
    TreeNode<ItemType> * currentNode = root;
    
    // loop exits if it reaches a null leaf
    while (currentNode != NULL) {
        
        if (checkThis == currentNode->info) {
            return true;
        }
        
        // left branch
        if (checkThis < currentNode->info) {
            currentNode = currentNode->left;
        }
        
        // right branch
        else { // findThis > currentNode->info
            currentNode = currentNode->right;
        }
    }
    
    // loop exits, search fails.
    return false;
}




template <class ItemType>
void RedBlackTree<ItemType> :: AddItem(ItemType addThis) {
    
    TreeNode<ItemType> * currentNode = root;
    
    // if tree is empty.
    if (currentNode == NULL) {
        root = new TreeNode<ItemType>;
        root->info = addThis;
        root->color = black;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }
    
    // if tree is not empty
    else {
        
        while (currentNode->info != addThis) {
            // if iteration reaches a node with key value of addThis, loop ends without adding a new node.
            
            // left branch
            if (addThis < currentNode->info) {
                if (currentNode->left == NULL) {
                    
                    TreeNode<ItemType> * newNode = new TreeNode<ItemType>;
                    newNode->info = addThis;
                    newNode->color = red;
                    newNode->left = NULL;
                    newNode->right = NULL;
                    newNode->parent = currentNode;
                    currentNode->left = newNode;
                    
                    ReColor(newNode);
                    while (root->parent != NULL) {
                        root = root->parent;
                    }
                    break;
                }
                else {
                    currentNode = currentNode->left;
                }
            }
            
            // right branch
            else { // addThis > currentNode->info
                if (currentNode->right == NULL) {
                    TreeNode<ItemType> * newNode = new TreeNode<ItemType>;
                    newNode->info = addThis;
                    newNode->color = red;
                    newNode->left = NULL;
                    newNode->right = NULL;
                    newNode->parent = currentNode;
                    currentNode->right = newNode;
                    
                    ReColor(newNode);
                    while (root->parent != NULL) {
                        root = root->parent;
                    }
                    break;
                }
                else {
                    currentNode = currentNode->right;
                }
            }
        }
    }
}
