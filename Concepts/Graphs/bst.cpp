#include <iostream>
using namespace std;

// -----------------------------
// Node structure for BST
// -----------------------------
struct TreeNode {
    int data;           // value of node
    TreeNode* left;     // pointer to left child
    TreeNode* right;    // pointer to right child
};

// -----------------------------
// BST class
// -----------------------------
class BST {
private:
    TreeNode* root;     // root node of BST

    // Helper function for inorder traversal
    void inorder(TreeNode* ptr) {
        if(ptr != nullptr) {
            inorder(ptr->left);          // traverse left subtree
            cout << ptr->data << " ";    // visit node
            inorder(ptr->right);         // traverse right subtree
        }
    }

    // Helper function for postorder traversal
    void postorder(TreeNode* ptr) {
        if(ptr != nullptr) {
            postorder(ptr->left);        // traverse left subtree
            postorder(ptr->right);       // traverse right subtree
            cout << ptr->data << " ";    // visit node
        }
    }

    // Helper function for preorder traversal
    void preorder(TreeNode* ptr) {
        if(ptr != nullptr) {
            cout << ptr->data << " ";    // visit node
            preorder(ptr->left);         // traverse left subtree
            preorder(ptr->right);        // traverse right subtree
        }
    }

public:
    // Constructor
    BST() {
        root = nullptr; // initialize root as NULL
    }

    // Check if BST is empty
    bool isEmpty() {
        return root == nullptr;
    }

    // Insert a new node
    void insert(int item) {
        TreeNode* p = new TreeNode; // create new node
        p->data = item;
        p->left = nullptr;
        p->right = nullptr;

        // If tree is empty, new node becomes root
        if(isEmpty()) {
            root = p;
            return;
        }

        // Otherwise, find the correct position
        TreeNode* ptr = root;
        TreeNode* parent = nullptr;

        while(ptr != nullptr) {
            parent = ptr;
            if(item < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        // Insert as left or right child of parent
        if(item < parent->data)
            parent->left = p;
        else
            parent->right = p;
    }

    // Public function to traverse inorder
    void inorderTrav() {
        inorder(root);
    }

    // Public function to traverse postorder
    void postorderTrav() {
        postorder(root);
    }

    // Public function to traverse preorder
    void preorderTrav() {
        preorder(root);
    }
};

// -----------------------------
// Main function to test BST
// -----------------------------
int main() {
    BST b;

    // Insert nodes
    b.insert(52);
    b.insert(25);
    b.insert(50);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(20);

    // Traverse BST in different orders
    cout << "Inorder traversal: ";
    b.inorderTrav();
    cout << endl;

    cout << "Postorder traversal: ";
    b.postorderTrav();
    cout << endl;

    cout << "Preorder traversal: ";
    b.preorderTrav();
    cout << endl;

    return 0;
}
