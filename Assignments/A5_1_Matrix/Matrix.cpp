#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int nrLines, int nrCols) {
    this->number_of_lines = nrLines;
    this->number_of_columns = nrCols;
    this->root = nullptr;
}

int Matrix::nrLines() const {
    return this->number_of_lines;
}

int Matrix::nrColumns() const {
    return this->number_of_columns;
}

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

TElem Matrix::modify(TComp i, TComp j, TElem e) {
    if(i < 0 || i >= this->number_of_lines || j < 0 || j >= this->number_of_columns)
        throw std::out_of_range("Invalid position");

    BSTNode* parentNode = nullptr;
    BSTNode* currentNode = this->root;

    // Search for the node with the specified position
    while (currentNode != nullptr) {
        if (currentNode->line == i && currentNode->column == j)
            break;

        if (currentNode->line > i || (currentNode->line == i && currentNode->column > j)) {
            parentNode = currentNode;
            currentNode = currentNode->left;
        } else {
            parentNode = currentNode;
            currentNode = currentNode->right;
        }
    }

    // Modify the value if the node exists
    if (currentNode != nullptr) {
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
    if (parentNode == nullptr) {
        this->root = newNode;
    } else if (parentNode->line > i || (parentNode->line == i && parentNode->column > j)) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }

    return NULL_TELEM;
}

Matrix::~Matrix() {
    // TODO: Implement destructor to deallocate memory
    //       occupied by the BST nodes.
    //       This can be done using post-order traversal.
}
