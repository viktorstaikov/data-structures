#include "binary_search_tree.h"

#include <iostream>

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
            std::cout << "left" << std::endl;

            this->deleteTree(tree->left);
        }
        if (tree->right) {
            std::cout << "right" << std::endl;
            this->deleteTree(tree->right);
        }
        std::cout << "mid" << std::endl;
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