#ifndef BINARY_SEACRH_TREE_H
#define BINARY_SEACRH_TREE_H

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    void copyData(const BinarySearchTree& other);
    void deleteTree(Node* tree);
    Node* min(Node* tree, int& min);
    Node* max(Node* tree, int& max);
    void deleteNode(Node* tree);
    void printTree(Node* tree);

public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);

    void Insert(int val);
    bool Contains(int val);
    //void Travers();
    bool Delete(int val);
    int Min();
    int Max();
    void Print();
};

#endif // BINARY_SEACRH_TREE_H