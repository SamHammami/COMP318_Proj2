#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

typedef char elemType; // "placeholder" for data type

//////*-------------------------***BT - binaryTree Class***---------------------------*//////
class binaryTree { 

protected:
    struct TreeNode {
    elemType data; 	// store data
    TreeNode * left; // link to left subtree
    TreeNode * right; // link to right subtree
    };
    TreeNode * root; // root of the tree

    int heightHelper(TreeNode *root) const; // helper function for height

private:
    // Tree traversals helper functions
    void in_order (TreeNode *node) const;
    void pre_order (TreeNode *node) const;
    void post_order (TreeNode *node) const;
    void level_order (TreeNode *node) const;
    void level_order_Sam (TreeNode *node) const;

    // Additional helper functions
    void displayHelper(TreeNode *node, int indent, bool isRightBranch) const; // helper function for displayHelper
    int size(TreeNode *node) const; // helper function for treeNodeCount


public:
    binaryTree ();  // constructor

    // Functions for tree traversals
    void in_order_Traversal() const;
    void pre_order_Traversal() const;
    void post_orderTraversal() const;
    void level_order_Traversal() const;
    void level_order_Traversal_Sam() const; // Sam's version of level order traversal discussed with Tony

    //Additional Functions
    int height() const;
    void display() const;
    int treeNodeCount() const;
    //int treeLeavesCount() const; // returns the number of leaves in the tree


};

////*----------------------**BST - Binary Search Tree Class**----------------------*////

class BST : public binaryTree {

private:
    bool search (const elemType key, TreeNode* node) const; // helper function for searchItem

public:
    bool searchItem (const elemType key); // Search for a node with the key

  /*
   Find the following in balancedBST class:

     -  void insertItem(const elemType key);
     -  void deleteItem(const elemType key);

     => It's better to implement these functions in the B_BST class because when we
     insert or delete a node, we automatically need to balance the tree to have the
     right structure of the tree.
   */
}; 
			


//*---------------------------------------*B_BST - balancedBST Class*-----------------------------------*//

class balancedBST : public BST {

private:

    // Rotation functions
    TreeNode* rotateRight(TreeNode *node); // Rotate to the right
    TreeNode* rotateLeft(TreeNode *node); // Rotate to the left
    TreeNode* rotateRightLeft(TreeNode *node); // Rotate to the right then to the left
    TreeNode* rotateLeftRight(TreeNode *node); // Rotate to the left then to the right

    // Balance the tree functions
    int calcBalanceFactor(TreeNode *node); // Calculate the balanceFactors
    TreeNode* balanceOurTree(TreeNode *node); // Balances the tree when needed or we insert a node


    // Helper functions
    TreeNode* insertItem(TreeNode *node, const elemType key); // helper function for insertItem (While inserting, it balances the tree)
    TreeNode* deleteItem(TreeNode *node, const elemType key); // helper function for deleteItem
    void balanceFactorsHelper(TreeNode *node); // helper function for to find the balance factors of the tree

public:
    // Functions for tree (Balanced BST)
    void insertItem(const elemType key); // Insert the node with the key
    void deleteItem(const elemType key); // Delete the node with the key
    void balanceFactors (); // Balance factors of the tree

};

