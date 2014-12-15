#include "binary_search_tree.h"

#include <iostream>
#include <iomanip>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
{
    this->copyData(other);
}

BinarySearchTree::~BinarySearchTree()
{
    this->deleteTree(root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other)
{
    if (this != &other) {
        this->deleteTree(root);
        this->copyData(other);
    }

    return *this;
}

void BinarySearchTree::copyData(const BinarySearchTree& other)
{
    //TODO: Implement it;
}

void BinarySearchTree::deleteTree(Node* tree)
{
    if (tree != nullptr) {
        if (tree->left) {
            this->deleteTree(tree->left);
        }
        if (tree->right) {
            this->deleteTree(tree->right);
        }
        delete tree;
    }
}

void BinarySearchTree::Insert(int val)
{
    if (this->root == nullptr) {
        this->root = new Node(val);
        return;
    }
    Node* tree = this->root;
    while (1) {
        if (tree->data <= val) {
            if (tree->right == nullptr) {
                tree->right = new Node(val);
                return;
            } else {
                tree = tree->right;
            }
        } else {
            if (tree->left == nullptr) {
                tree->left = new Node(val);
                return;
            } else {
                tree = tree->left;
            }
        }
    }
}

bool BinarySearchTree::Contains(int val)
{
    Node* ptr = this->root;

    while (ptr != nullptr) {
        if (ptr->data == val) {
            return true;
        } else if (ptr->data < val) {
            ptr = ptr->right;
        } else {
            ptr = ptr->left;
        }
    }
    return false;
}

bool BinarySearchTree::Delete(int val)
{
    Node* ptr = this->root;

    while (ptr != nullptr) {
        if (ptr->data < val) {
            ptr = ptr->right;
        } else if (ptr->data < val) {
            ptr = ptr->left;
        } else {
            //delete
            this->deleteNode(ptr);
            return true;
        }
    }
    return false;
}

//FIX IT
void BinarySearchTree::deleteNode(Node* tree)
{
    Node* ptr = tree;

    if (ptr->left == nullptr) {
        tree = tree->right;
        delete ptr;
    } else if (ptr->right == nullptr) {
        tree = tree->left;
        delete ptr;
    } else {
        int data;
        Node* toDelete = this->max(ptr->left, data);

        cout << "data_" << data << endl;
        cout << "tree->data_" << tree->data << endl;

        tree->data = data;
        delete toDelete;
    }
}

int BinarySearchTree::Min()
{
    int min;
    this->min(this->root, min);
    return min;
}

int BinarySearchTree::Max()
{
    int max;
    this->max(this->root, max);
    return max;
}

Node* BinarySearchTree::min(Node* tree, int& min)
{
    Node* ptr = tree;
    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }
    min = ptr->data;
    return ptr;
}

Node* BinarySearchTree::max(Node* tree, int& max)
{
    Node* ptr = tree;
    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }
    max = ptr->data;
    return ptr;
}

void BinarySearchTree::Print()
{
    this->printTree(this->root);
}

void BinarySearchTree::printTree(Node* ptr)
{
    if (ptr != nullptr) {
        cout << ptr->data << endl;

        if (ptr->left != nullptr) {
            this->printTree(ptr->left);
        }
        if (ptr->right != nullptr) {
            this->printTree(ptr->right);
        }
    }
}