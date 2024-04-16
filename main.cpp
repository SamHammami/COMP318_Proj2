/* --------------------------------- Wheaton College MA - Spring 2024 ---------------------------------*\
 * Comp 318, programming assignment 2
 * Sam Hammami '25
 **********************************
 *       Inheritance diagram:     *
 **********************************
 *     Binary Tree class          *
 *             |                  *
 *   Binary Search Tree Class     *
 *             |                  *
 * Balanced Binary Search  class  *
 *             |                  *
 *          main.cpp              *
 **********************************
 */

#include "AVLtrees.h"
#include <iostream>

using namespace std;


int main() {

    cout << endl << endl << ".                        ***     Welcome to The AVL Trees World     ***                    ." << endl << endl;

/*------- Test the binary tree functions -------*/


    cout << endl << "--------------------------------------------------------------------------------------------------" << endl << endl;

    // Create a binary tree object
    balancedBST* tree = new balancedBST();

/*------- Test the insert function -------*/

    // Insert the alphabet into the tree
    cout << "Inserting: ";

    for (int i = 0; i < 26; i++) {
        cout << (char)(i+97) << ' ';
        tree->insertItem((char)i+97);
    }
    cout << endl;


/*------- Test the displayHelper function -------*/

    // Great Source to visualize the tree: https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

    // Display the tree
    cout << endl << "Loading the tree... " << endl << endl;
    tree->display();


/*------- Test the tree functions -------*/

    // Test the number of nodes in the tree, N = 26
    cout << endl << "Number of nodes: " << tree->treeNodeCount() << endl;

    // Test the heightHelper of the tree floor(log(N)), N = 26, floor(log(26)) = 4
    cout << "Height of the tree: " << tree->height() << endl;

    // Test the balanceOurTree factors of the tree
    cout << "Balance Factors: ";
    tree->balanceFactors();
    cout << endl;


    cout << endl << "--------------------------------------------------------------------------------------------------" << endl << endl;

/*------- Test the tree traversals -------*/

    cout << endl << "Traversals: " << endl;

    // Test the tree traversals
    cout << endl << "Pre-order: ";
    tree->pre_order_Traversal();     // p h d b a c f e g l j i k n m o t r q s x v u w y z
    cout << endl << "In-order: ";
    tree->in_order_Traversal();      // a b c d e f g h i j k l m n o p q r s t u v w x y z
    cout << endl << "Post-order: ";
    tree->post_orderTraversal();     // a c b e g f d i k j m o n l h q s r u w v z y x t p


    cout << endl << "Level-order: ";
    tree->level_order_Traversal();   // p h t d l r x b f j n q s v y a c e g i k m o u w z
    cout << endl << "Level-order by Sam: " << endl;
    tree->level_order_Traversal_Sam();

    cout << endl << endl;

/*------- Test the search function -------*/

    cout << "Searching for node 'c': ";
    // Test the search function
    if (tree->searchItem('c')) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for node 'm': ";
    if (tree->searchItem('m')) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << endl;


    cout << endl << "--------------------------------------------------------------------------------------------------" << endl << endl;

/*------- Test the delete function -------*/


    cout << "Deleting some nodes... " << endl << endl;
    cout << "node 'h' - Deleted " << endl;
    tree->deleteItem('h');
    cout << "node 'i' - Deleted  " << endl;
    tree->deleteItem('i');
    cout << "node 'm' - Deleted  " << endl;
    tree->deleteItem('m');
    cout << "node 'g' - Deleted  " << endl;
    tree->deleteItem('g');
    cout << "node 't' - Deleted  " << endl;
    tree->deleteItem('t');
    cout << "node 'a' - Deleted  " << endl;
    tree->deleteItem('a');
    cout << "node 'z' - Deleted  " << endl;
    tree->deleteItem('z');
    cout << "node 'x' - Deleted  " << endl;
    tree->deleteItem('x');


    // Test deleting a node that doesn't exist
    cout << endl << "Deleting node 'm' - Test when a node already do not exist " << endl;
    tree->deleteItem('m');

    cout << endl << endl << "** after deleting - Display the new tree **" << endl << endl;
    tree->display();



    cout << endl << "Number of nodes: " << tree->treeNodeCount() << endl;
    cout << "Height of the tree: " << tree->height() << endl;

    cout << endl << "Searching for the deleted node 'm': ";
    // Test the search function
    if (tree->searchItem('m')) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Searching for the deleted node 'g': ";
    if (tree->searchItem('g')) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    
    return 0;
}