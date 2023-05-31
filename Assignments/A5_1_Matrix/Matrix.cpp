#include "Matrix.h"
#include <exception>
#include <iostream>

using namespace std;

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

TElem Matrix::element(TComp line, TComp column) const {
    if(line >= this->number_of_lines or column >= this->number_of_columns
        or line < 0 or column < 0) {
        return NULL_TELEM;
    }

    BSTNode* current = this->root;

    while(current != nullptr) {
        if(current->line == line and current->column == column) {
            return current->value;
        }

        if(current->line == line and current->column < column) {
            current = current->left;
        } else if(current->line == line and current->column > column) {
            current = current->left;
        } else if(current->line < line) {
            current = current->right;
        }
    }

    return NULL_TELEM;
}

void Matrix::insert(BSTNode* node, TComp value) {

}

TElem Matrix::modify(TComp line, TComp column, TElem value) {
	if(line >= this->number_of_lines or column >= this->number_of_columns
        or line < 0 or column < 0) {
        return NULL_TELEM;
    }

    BSTNode* current = this->root;
    BSTNode* previous = current;
    
    while(current != nullptr) {
        if(current->line == line and current->column == column) {
            TElem old_value = current->value;
            current->value = value;
            return old_value;
        }

        previous = current;

        if(current->line == line and current->column < column) {
            current = current->left;
        } else if(current->line == line and current->column > column) {
            current = current->left;
        } else if(current->line < line) {
            current = current->right;
        }
    }

    /// In case there was no matching element in the sparse matrix we create one
    current = new BSTNode{};
    current->line = line;
    current->column = column;
    current->value = value;
    current->left = nullptr;
    current->right = nullptr;

    if(previous == nullptr) {
        this->root = current;
    } else {
        if(current->line <= previous->line and current->column <= previous->column) {
            previous->left = current;
        } else {
            previous->right = current;
        }
    }

    return NULL_TELEM;
}

Matrix::~Matrix() {

}
