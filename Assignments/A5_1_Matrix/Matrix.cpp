#include "Matrix.h"
#include <exception>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) {
    this->number_of_lines = nrLines;
    this->number_of_columns = nrCols;

    this->root = nullptr;
}

Matrix::Matrix(const Matrix &matrix) {
    this->number_of_lines = matrix.number_of_lines;
    this->number_of_columns = matrix.number_of_columns;

    this->root = new BSTNode{};
    this->root->line = matrix.root->line;
    this->root->column = matrix.root->column;
    this->root->value = matrix.root->value;

    this->root->left = new BSTNode{};
    this->root->left->line = matrix.root->left->line;
    this->root->left->column = matrix.root->left->column;
    this->root->left->value = matrix.root->left->value;

    this->root->right = new BSTNode{};
    this->root->right->line = matrix.root->right->line;
    this->root->right->column = matrix.root->right->column;
    this->root->right->value = matrix.root->right->value;

    // TODO rest of the nodes
}

int Matrix::nrLines() const {
    return this->number_of_lines;
}

int Matrix::nrColumns() const {
    return this->number_of_columns;
}

TElem Matrix::element(TComp line, TComp column) const {
    if(line >= this->number_of_lines or column >= this->number_of_columns) {
        return NULL_TELEM;
    }

    BSTNode* current = this->root;

    while(current != nullptr) {
        if(current->line == line and current->column == column) {
            return current->value;
        }

        if(current->line < line and current->column < column) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
}

TElem Matrix::modify(TComp line, TComp column, TElem value) {
	if(line >= this->number_of_lines or column >= this->number_of_columns) {
        return NULL_TELEM;
    }

    BSTNode* current = this->root;

    while(current != nullptr) {
        if(current->line == line and current->column == column) {
            return current->value;
        }

        if(current->line < line and current->column < column) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
}

MatrixIterator Matrix::iterator() {
    return MatrixIterator(*this);
}

Matrix::~Matrix() {

}
