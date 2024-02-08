#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

// Make a class for bst 
class BST {
public:
    BST() : root(nullptr) {}
    void insert(int key) {
        root = insert(root, key);
    }
    void remove(int key) {
        root = remove_node(root, key);
    }
    bool search(int key) {
        return search(root, key);
    }
private:
    TreeNode* root;
    //Bst node insertion
    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            TreeNode* temp = new TreeNode(key);
            return temp;
        }
        if (key<node->key) {
            node->left = insert(node->left, key);
        } 
        else if (key>node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }
    
    // Finding the predecessor of node to delete
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    TreeNode* remove_node(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->key) {
            node->left = remove_node(node->left, key);
        } 
        else if (key > node->key) {
            node->right = remove_node(node->right, key);
        } 
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                return temp;
            } 
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                return temp;
            }
            //Rotation of nodes for remove operation 
            TreeNode* temp = findMin(node->right);
            node->key = temp->key;
            node->right = remove_node(node->right, temp->key);
        }
        return node;
    }
    bool search(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (key == node->key) {
            return true;
        } 
        else if (key < node->key) {
            return search(node->left, key);
        } 
        else {
            return search(node->right, key);
        }
        return false;
    }
};

int main() {
    BST bst;
    int d; cin >> d;
    while(d--){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'B'){
            if(!bst.search(x)) bst.insert(x);
        }
        else if(c == 'S'){
            if(bst.search(x)) bst.remove(x);
        }
        else{
            if(bst.search(x)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
