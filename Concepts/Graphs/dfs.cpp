//convert and add dfs code from bfs file
#include <iostream>
using namespace std;

// -----------------------------
// Node structure for BST
// -----------------------------
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// -----------------------------
// BST class
// -----------------------------
class BST {
private:
    TreeNode* root;

    // -------- DFS Traversals --------
    void inorder(TreeNode* ptr) {
        if (ptr) {
            inorder(ptr->left);
            cout << ptr->data << " ";
            inorder(ptr->right);
        }
    }

    void preorder(TreeNode* ptr) {
        if (ptr) {
            cout << ptr->data << " ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(TreeNode* ptr) {
        if (ptr) {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->data << " ";
        }
    }

    // -------- DFS Search --------
    bool dfs(TreeNode* ptr, int key) {
        if (ptr == nullptr)
            return false;

        if (ptr->data == key)
            return true;

        return dfs(ptr->left, key) || dfs(ptr->right, key);
    }

public:
    BST() {
        root = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    // Insert node
    void insert(int item) {
        TreeNode* p = new TreeNode;
        p->data = item;
        p->left = nullptr;
        p->right = nullptr;

        if (isEmpty()) {
            root = p;
            return;
        }

        TreeNode* ptr = root;
        TreeNode* parent = nullptr;

        while (ptr) {
            parent = ptr;
            if (item < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        if (item < parent->data)
            parent->left = p;
        else
            parent->right = p;
    }

    // Public traversal calls
    void inorderTrav() { inorder(root); }
    void preorderTrav() { preorder(root); }
    void postorderTrav() { postorder(root); }

    // Public DFS search
    bool dfsSearch(int key) {
        return dfs(root, key);
    }
};

// -----------------------------
// Main function
// -----------------------------
int main() {
    BST b;

    b.insert(45);
    b.insert(20);
    b.insert(60);
    b.insert(10);
    b.insert(30);

    cout << "Inorder (DFS): ";
    b.inorderTrav();
    cout << endl;

    cout << "Preorder (DFS): ";
    b.preorderTrav();
    cout << endl;

    cout << "Postorder (DFS): ";
    b.postorderTrav();
    cout << endl;

    cout << "DFS search 20: " 
         << (b.dfsSearch(20) ? "Found" : "Not Found") << endl;

    cout << "DFS search 99: " 
         << (b.dfsSearch(99) ? "Found" : "Not Found") << endl;

    return 0;
}
