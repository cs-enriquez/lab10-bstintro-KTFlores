#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public: 
	#include <iostream>
using namespace std;

class Node {
public:
    int key;         
    Node* left;      
    Node* right;     

    
    Node(int keyValue) : key(keyValue), left(nullptr), right(nullptr) {}
};

};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
    // Creating nodes
    Node* root = new Node(13);
    root->left = new Node(0);
    root->right = new Node(21);

    root->left->left = new Node(-2);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(99);

    root->left->left->left = new Node(-1);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(12);
    root->right->left->right = new Node(18);

    root->right->left->right->right = new Node(19);

    return root;

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
    // Base case: tree is empty or target found
    if (root == nullptr) return false;
    if (root->key == target) return true;

    // General case: search in left or right subtree
    if (target < root->key) {
        return searchTree(target, root->left);
    } else {
        return searchTree(target, root->right);
    }
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
    // Base case: empty tree
    if (root == nullptr) return 0;

    // General case: size of left + size of right + 1 (current node)
    return 1 + treeSize(root->left) + treeSize(root->right);
}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
    // Base case: empty tree
    if (root == nullptr) return -1; // Height of empty tree is -1

    // General case: 1 + max height of left or right subtree
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}