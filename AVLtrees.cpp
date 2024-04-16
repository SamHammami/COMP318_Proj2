#include "AVLtrees.h"

//////*------------------------------------------BT - binaryTree Functions--------------------------------------*//////






            /*-------------------- Binary Tree Constructor -------------------*/

/* --- binaryTree() ---
 * Description:
 *  - Initializes a binary tree object with a null root
 *  - The tree is empty
 *
 *  Parameters:
 *  - None
 *
 *  Return:
 *  - None
 */

binaryTree::binaryTree() {
    root = nullptr;
}

/*-------------------------------Private Functions---------------------------------------*/



        /*-------------------- Tree Traversals ---------------------*/

/* --- in_order(TreeNode* node) const ---
 * Description:
 * - Traverses the tree in in-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is left, node, right
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to traverse
 *
 * Return:
 * - None
 */

void binaryTree::in_order(TreeNode *node) const {
    // Check if the node is not null before proceeding
    if (node != nullptr) {
        in_order(node->left);
        cout << node->data << ' ';
        in_order(node->right);
    }
}

/* --- pre_order(TreeNode* node) const ---
 * Description:
 * - Traverses the tree in pre-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is node, left, right
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to traverse
 *
 * Return:
 * - None
 */

void binaryTree::pre_order(TreeNode *node) const {
    if (node != nullptr) {
        cout << node->data << ' ';
        pre_order(node->left);
        pre_order(node->right);
    }
}

/* --- post_order(TreeNode* node) const ---
 * Description:
 * - Traverses the tree in post-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is left, right, root
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to traverse
 *
 * Return:
 * - None
 */
void binaryTree::post_order(TreeNode *node) const {
    if (node != nullptr) {
        post_order(node->left);
        post_order(node->right);
        cout << node->data << ' ';
    }
}

/* --- level_order(TreeNode* node) const ---
 * Description:
 * - Traverses the tree in level-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is from the root to the leaves
 * - The function is iterative and uses a queue
 *
 * Parameters:
 * - TreeNode* node: The current node to traverse
 *
 * Return:
 * - None
 */
void binaryTree::level_order(TreeNode *node) const {
    // Check if the node is not null before proceeding
    if (node != nullptr) {
        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << ' ';

            // Explicitly check if the left child exists before enqueueing
            if (current->left != nullptr) {
                q.push(current->left);
            }

            // Explicitly check if the right child exists before enqueueing
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
}

void binaryTree::level_order_Sam(TreeNode *node) const {
    // Check if the node is not null before proceeding
    if (node != nullptr) {
        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {

            int nodeLevel = q.size();  // Get the number of nodes in the current level

            for (int i = 0; i < nodeLevel; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Print the current node's data
                cout << current->data << ' ';

                // Explicitly check if the left child exists before enqueueing
                if (current->left != nullptr) {
                    q.push(current->left);
                }

                // Explicitly check if the right child exists before enqueueing
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            // Print a newline after each level is processed
            cout << endl;
        }
    }
}

        /*-----------Additional Helper Functions-----------*/

/* --- size(TreeNode* node) const ---
 * Description:
 * - Counts the number of nodes in the tree
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to count
 *
 * Return:
 * - int: The number of nodes in the tree
 */
int binaryTree::size(TreeNode *node) const {
    if (node != nullptr) { // If the node exists, count it (1) and add the count of nodes in the left and right subtrees
        return 1 + size(node->left) + size(node->right);
    } else { // Base case: If the node is null, contribute 0 to the count
        return 0;
    }
}

/* --- height(TreeNode* root) const ---
 * Description:
 * - Calculates the height of the tree
 * - The height of a tree is the number of edges on the longest path between the root and a leaf root
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* root: The current root to calculate the height
 *
 * Return:
 * - int: The heightHelper of the tree
 */
int binaryTree::heightHelper(TreeNode *root) const {
    if (root != nullptr) { // Recursively find the heightHelper of both subtrees and choose the larger one

        return 1 + max(heightHelper(root->left), heightHelper(root->right));

    } else { // Base case: If the root is null, return -1 as the heightHelper

        return -1;
    }
}

/* --- displayHelper() const ---
 * Description:
 * - Displays the tree in a graphical format
 * - The function is recursive
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void binaryTree::displayHelper(TreeNode *node, int indent = 0, bool isRightBranch = true) const {
    if (node != nullptr) {

        // Display right child with added indentation and forward slash
        if (node->right) {
            displayHelper(node->right, indent + 5, true);
            cout << setw(indent) << "" << " /" << endl;
        }

        // Print current node's value
        cout << setw(indent) << node->data << endl;

        // Display left child with added indentation and backward slash
        if (node->left) {
            cout << setw(indent) << "" << " \\" << endl; // setw() is used to set the width of the output
            displayHelper(node->left, indent + 5, false);
        }
    }
}


/*-------------------------------- Public Functions ----------------------------------*/


//Tree Traversals Helper Functions

/* --- in_order_Traversal() const ---
 * Description:
 * - Calls the in_order() function to traverse the tree in in-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is left, root, right
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void binaryTree::in_order_Traversal() const {
    in_order(root); //Starts from the root
    cout << endl; //End with new line after traversal
}

/* --- pre_order_Traversal() const ---
 * Description:
 * - Calls the pre_order() function to traverse the tree in pre-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is root, left, right
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void binaryTree::pre_order_Traversal() const {
    pre_order(root);
    cout << endl;
}

/* --- post_orderTraversal() const ---
 * Description:
 * - Calls the post_order() function to traverse the tree in post-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is left, right, root
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void binaryTree::post_orderTraversal() const {
    post_order(root);
    cout << endl;
}

/* --- level_order_Traversal() const ---
 * Description:
 * - Calls the level_order() function to traverse the tree in level-order fashion
 * - Prints the data of each node in the tree
 * - The traversal order is from the root to the leaves
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void binaryTree::level_order_Traversal() const {
    level_order(root);
    cout << endl;
}

void binaryTree::level_order_Traversal_Sam() const {
    level_order_Sam(root);
    cout << endl;
}


                /*---------*/
//Additional Functions

/* --- treeNodeCount() const ---
 * Description:
 * - Calls the size() function to count the number of nodes in the tree
 *
 * Parameters:
 * - None
 *
 * Return:
 * - int: The number of nodes in the tree
 */
int binaryTree::treeNodeCount() const {
    return size(root);
}

/* --- height() const ---
 * Description:
 * - Calls the heightHelper() function to calculate the height of the tree
 *
 * Parameters:
 * - None
 *
 * Return:
 * - int: The height of the tree
 */
int binaryTree::height() const {
    return heightHelper(root);
}

/* --- display() const ---
 * Description:
 * - Calls the displayHelper() function to display the tree in a graphical format
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void binaryTree::display() const {

    if (root != nullptr) {
        displayHelper(root, 0, true); // Call the displayHelper function with the root node
    } else {
        cout << "The tree is empty." << endl;
    }
}





////*---------------------------------------BST - Binary Search Tree Functions------------------------------------*////


/*---------------Private Functions---------------*/

/* --- search(const elemType key, TreeNode* node) const ---
 * Description:
 * - Searches for a key in the tree
 * - The function is recursive
 *
 * Parameters:
 * - const elemType key: The key to search for
 * - TreeNode* node: The current node to search
 *
 * Return:
 * - bool: True if the key is found, false otherwise
 */
bool BST::search(const elemType key, TreeNode *node) const {
    
    // Check if the node exists before proceeding
    if (node != nullptr) {

        // Compare the key value to the node's key value
        if (node->data == key) {
            return true;
        } else if (key < node->data) {
            return search(key, node->left);
        } else {
            return search(key, node->right);
        }
    }
    return false;
}

/*---------------Public Functions---------------*/



/* --- searchItem(const elemType key) ---
 * Description:
 * - Calls the search() function to search for a key in the tree
 *
 * Parameters:
 * - const elemType key: The key to search for
 *
 * Return:
 * - bool: True if the key is found, false otherwise
 */
bool BST::searchItem(const elemType key) {
    return search(key, root);
}





//*--------------------------------------------B_BST balancedBST Functions------------------------------------------*//

/* --- rotateRight(TreeNode* node) ---
 * Description:
 * - Rotates the tree to the right
 * - The function is used to balanceOurTree the tree
 *
 * Parameters:
 * - TreeNode* node: The current node to rotate
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode *balancedBST::rotateRight(TreeNode *node) {
    TreeNode *temp = node->right; // Store the right child of the node
    node->right = temp->left; // Move the left child of the right child to the right child of the node
    temp->left = node;// Move the node to the left child of the right child
    return temp; // Return the new root of the tree
}

/* --- rotateLeft(TreeNode* node) ---
 * Description:
 * - Rotates the tree to the left
 * - The function is used to balanceOurTree the tree
 *
 * Parameters:
 * - TreeNode* node: The current node to rotate
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode *balancedBST::rotateLeft(TreeNode *node) {
    TreeNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

/* --- rotateRightLeft(TreeNode* node) ---
 * Description:
 * - Rotates the tree to the right and then to the left
 * - The function is used to balanceOurTree the tree
 *
 * Parameters:
 * - TreeNode* node: The current node to rotate
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode *balancedBST::rotateRightLeft(TreeNode *node) {
    node->right = rotateLeft(node->right);
    return rotateRight(node);
}

/* --- rotateLeftRight(TreeNode* node) ---
 * Description:
 * - Rotates the tree to the left and then to the right
 * - The function is used to balanceOurTree the tree
 *
 * Parameters:
 * - TreeNode* node: The current node to rotate
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode *balancedBST::rotateLeftRight(TreeNode *node) {
    node->left = rotateRight(node->left);
    return rotateLeft(node);
}

// Balance the tree functions

/* --- calcBalanceFactor(TreeNode* node) ---
 * Description:
 * - Calculates the balance factor of a node
 * - The balanceOurTree factor is the height of the left subtree minus the height of the right subtree
 *
 * Parameters:
 * - TreeNode* node: The current node to calculate the balance factor
 *
 * Return:
 * - int: The balance factor of the node
 */
int balancedBST::calcBalanceFactor(TreeNode* node) { //Height of left subtree - Height of right subtree

    return heightHelper(node->left) - heightHelper(node->right);
}


/* --- balance(TreeNode* node) ---
 * Description:
 * - Balances the tree by rotating the nodes
 * - The function is used to balance the tree
 *
 * Parameters:
 * - TreeNode* node: The current node to balanceOurTree
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode *balancedBST::balanceOurTree(TreeNode *node) {

    int balanceFactor = calcBalanceFactor(node);

    if (balanceFactor > 1) {
        if (calcBalanceFactor(node->left) > 0) {
            node = rotateLeft(node);
        } else {
            node = rotateLeftRight(node);
        }
    } else if (balanceFactor < -1) {
        if (calcBalanceFactor(node->right) > 0) {
            node = rotateRightLeft(node);
        } else {
            node = rotateRight(node);
        }
    }

    return node;
}



/* --- insertItem(TreeNode* node, const elemType key) ---
 * Description:
 * - Inserts a node into the tree
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to insert the key
 * - const elemType key: The key to insert
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode * balancedBST::insertItem(TreeNode *node, const elemType key) {

    if (node == nullptr) {
        node = new TreeNode;
        node->data = key;
        node->left = nullptr;
        node->right = nullptr;

    } else if (key < node->data) {
        node->left = insertItem(node->left, key);
        node = balanceOurTree(node);

    } else if (key > node->data) {
        node->right = insertItem(node->right, key);
        node = balanceOurTree(node);
    }

    node = balanceOurTree(node);

    return node;
}


/* --- deleteItem(TreeNode* node, const elemType key) ---
 * Description:
 * - Deletes a node from the tree
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to delete the key
 * - const elemType key: The key to delete
 *
 * Return:
 * - TreeNode*: The new root of the tree
 */
binaryTree::TreeNode *balancedBST::deleteItem(TreeNode *node, const elemType key) {

    if (node != nullptr) {
        if (key < node->data) {
            node->left = deleteItem(node->left, key);
        } else if (key > node->data) {
            node->right = deleteItem(node->right, key);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                TreeNode *temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                TreeNode *temp = node;
                node = node->left;
                delete temp;
            } else {
                TreeNode *temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = deleteItem(node->right, temp->data);
            }
        }
    }

    return node;
}


/* --- balanceFactorsHelper(TreeNode* node) ---
 * Description:
 * - Prints the balance factors of each node in the tree
 * - The balance factor is the height of the left subtree minus the height of the right subtree
 * - The function is recursive
 *
 * Parameters:
 * - TreeNode* node: The current node to calculate the balanceOurTree factor
 *
 * Return:
 * - None
 */
void balancedBST::balanceFactorsHelper(TreeNode *node) {
    if (node != nullptr) {
        // Print the node's data and balanceOurTree factor
        cout << node->data << ":" <<calcBalanceFactor(node) << ' ';

        // Recursively calculate the balanceOurTree factors of the left and right subtrees
        balanceFactorsHelper(node->left);
        balanceFactorsHelper(node->right);
    }
}




/*-------------Public Functions------------*/

/* --- insertItemHelper(const elemType key) ---
 * Description:
 * - Calls the insertItem() function to insert a key into the tree
 *
 * Parameters:
 * - const elemType key: The key to insert
 *
 * Return:
 * - None
 */
void balancedBST::insertItem(const elemType key) {

    root = balancedBST::insertItem(root, key);
}

/* --- deleteItem(const elemType key) ---
 * Description:
 * - Calls the deleteItem() function to delete a key from the tree
 *
 * Parameters:
 * - const elemType key: The key to delete
 *
 * Return:
 * - None
 */
void balancedBST::deleteItem(const elemType key) {
    root = balancedBST::deleteItem(root, key);
}

/* --- balanceFactors() ---
 * Description:
 * - Calls the balanceFactorsHelper() function to print the balanceOurTree factors of each node in the tree
 *
 * Parameters:
 * - None
 *
 * Return:
 * - None
 */
void balancedBST::balanceFactors() {
    balanceFactorsHelper(root);
    cout << endl;
}

