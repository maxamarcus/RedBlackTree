// Max Marcus and Michelle Soroka
// Data Structures
// Red Black Tree implementation and comparison project
// April 23

// Rotation functions.

using namespace std;



// Right rotation.
/* Argument currentNode represents the root of the sub tree that is to be rotated.
 After rotation, currentNode is now the right branch of the sub tree (newRight).
 The newRoot of the sub tree is the node that was originally currentNode->left. */
template <class ItemType>
void RotateRight(TreeNode<ItemType> * currentNode) {
    TreeNode<ItemType> * newRoot = currentNode->left;
    TreeNode<ItemType> * newRight = currentNode;
    TreeNode<ItemType> * newRightLeft = currentNode->left->right;
    // ^ RIGHT sub tree's LEFT sub tree.

    // set newRoot pointers:
    newRoot->parent = currentNode->parent;
    newRoot->right = newRight;

    // set parent pointers:
    if (Parent(currentNode) != NULL) {  // skip if parent is null.
        
        // if currentNode was the right child
        if (currentNode == Parent(newRoot)->right) {
            Parent(newRoot)->right = newRoot;
            }
        
        // if currentNode was the left child.
        else {
            Parent(newRoot)->left = newRoot;
        }
    }

    // set newRight pointers:
    newRight->parent = newRoot;
    newRight->left = newRightLeft;

    // set newRightLeft pointers:
    if (newRightLeft != NULL) {
        // special case -- this node may be NULL.
        newRightLeft->parent = newRight;
    }
}



// Left rotation.
/* Argument currentNode represents the root of the sub tree that is to be rotated.
 After rotation, currentNode is now the left branch of that sub tree (newLeft).
 The newRoot of the sub tree is the node that was originally currentNode->right. */
template <class ItemType>
void RotateLeft(TreeNode<ItemType> * currentNode) {
    TreeNode<ItemType> * newRoot = currentNode->right;
    TreeNode<ItemType> * newLeft = currentNode;
    TreeNode<ItemType> * newLeftRight = currentNode->right->left;
    // ^ LEFT sub tree's RIGHT sub tree.

    // set newRoot pointers:
    newRoot->parent = currentNode->parent;
    newRoot->left = newLeft;

    // set parent pointers:
    if (currentNode->parent != NULL) {
        
        // if currentNode was the right child
        if (currentNode == Parent(newRoot)->right) {
            Parent(newRoot)->right = newRoot;
            }
        
        // if currentNode was the left child
        else {
            Parent(newRoot)->left = newRoot;
        }
    }

    // newLeft's pointers:
    newLeft->parent = newRoot;
    newLeft->right = newLeftRight;

    // newLeftRight's pointers:
    if (newLeftRight != NULL) {
        // special case -- this node may be NULL.
        newLeftRight->parent = newLeft;
    }
}



// Right-left rotation.
/* Argument currentNode represents the root of the sub tree that rotates RIGHT (the first rotation).
 After right rotation, currentNode now points to the right branch of that sub tree.
 So the LEFT rotation is performed on currentNode's grandparent. */
template <class ItemType>
void RotateRightLeft(TreeNode<ItemType> * currentNode) {
    RotateRight<ItemType>(currentNode);
    RotateLeft<ItemType>(currentNode->parent->parent);
}



// Left-right rotation.
/* Argument currentNode represents the root of the sub tree that rotates LEFT (first rotation).
 After left rotation, currentNode now points to the left branch of that sub tree.
 So the RIGHT rotation is performed on the currentNode's grandparent. */
template <class ItemType>
void RotateLeftRight(TreeNode<ItemType> * currentNode) {
    RotateLeft<ItemType>(currentNode);
    RotateRight<ItemType>(currentNode->parent->parent);
}
