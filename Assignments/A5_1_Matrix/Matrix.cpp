#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int nrLines, int nrCols) {
    this->number_of_lines = nrLines;
    this->number_of_columns = nrCols;
    this->root = nullptr;
}
/// Overall: Theta(1)\n

int Matrix::nrLines() const {
    return this->number_of_lines;
}
/// Overall: Theta(1)\n

int Matrix::nrColumns() const {
    return this->number_of_columns;
}
/// Overall: Theta(1)\n

TElem Matrix::element(TComp i, TComp j) const {
    if(i < 0 || i >= this->number_of_lines || j < 0 || j >= this->number_of_columns)
        throw std::out_of_range("Invalid position");

    BSTNode* currentNode = this->root;

    while(currentNode != nullptr) {
        if(currentNode->line == i && currentNode->column == j)
            return currentNode->value;
        else if(currentNode->line > i || (currentNode->line == i && currentNode->column > j))
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    return NULL_TELEM;
}
/// Best Case: Theta(1)\n
/// Average Case: \n
/// Worst Case: Theta(height)\n
/// Overall: O(height)\n

TElem Matrix::modify(TComp i, TComp j, TElem e) {
    if(i < 0 || i >= this->number_of_lines || j < 0 || j >= this->number_of_columns)
        throw std::out_of_range("Invalid position");

    BSTNode* parentNode = nullptr;
    BSTNode* currentNode = this->root;

    // Search for the node with the specified position
    while(currentNode != nullptr) {
        if(currentNode->line == i && currentNode->column == j)
            break;

        if(currentNode->line > i || (currentNode->line == i && currentNode->column > j)) {
            parentNode = currentNode;
            currentNode = currentNode->left;
        } else {
            parentNode = currentNode;
            currentNode = currentNode->right;
        }
    }

    // Modify the value if the node exists
    if(currentNode != nullptr) {
        TElem previousValue = currentNode->value;
        currentNode->value = e;
        return previousValue;
    }

    // Create a new node if the node doesn't exist
    BSTNode* newNode = new BSTNode;
    newNode->line = i;
    newNode->column = j;
    newNode->value = e;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Insert the new node into the tree
    if(parentNode == nullptr) {
        this->root = newNode;
    } else if(parentNode->line > i || (parentNode->line == i && parentNode->column > j)) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }

    return NULL_TELEM;
}
/// Best Case: Theta(1)\n
/// Average Case: \n
/// Worst Case: Theta(height)\n
/// Overall: O(height)\n

Matrix::~Matrix() {
    this->destroyTree(this->root);
}
/// Best Case: Theta(nodes)\n
/// Average Case: Theta(nodes)\n
/// Worst Case: Theta(nodes)\n
/// Overall: Theta(nodes)\n

void Matrix::destroyTree(BSTNode* node) {
    if(node != nullptr) {
        // Recursively destroy the left and right subtrees
        destroyTree(node->left);
        destroyTree(node->right);

        // Delete the current node
        delete node;
    }
}
/// Best Case: Theta(nodes)\n
/// Average Case: Theta(nodes)\n
/// Worst Case: Theta(nodes)\n
/// Overall: Theta(nodes)\n
