#include<iostream>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
    Node(int val) {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int height(Node* n) { return n ? n->height : 0; }
int balance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int val) {
    if(!node) return new Node(val);
    if(val < node->data) node->left = insert(node->left, val);
    else if(val > node->data) node->right = insert(node->right, val);
    else return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int bal = balance(node);

    if(bal > 1 && val < node->left->data) return rightRotate(node);
    if(bal < -1 && val > node->right->data) return leftRotate(node);
    if(bal > 1 && val > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(bal < -1 && val < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << "(h=" << root->height << ") ";
    inorder(root->right);
}

void preorder(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = 6;

    cout << "Inserting: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        root = insert(root, arr[i]);
    }
    cout << endl;

    cout << "\nInorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Root: " << root->data << endl;
    cout << "Tree height: " << root->height << endl;
    cout << "Balance factor: " << balance(root) << endl;

    return 0;
}