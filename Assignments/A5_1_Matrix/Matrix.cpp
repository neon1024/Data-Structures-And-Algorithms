#include "Matrix.h"
#include <exception>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) {
	//TODO - Implementation
}

Matrix::Matrix(const Matrix &matrix) {
    this->number_of_lines = matrix.number_of_lines;
    this->number_of_columns = matrix.number_of_columns;
}

int Matrix::nrLines() const {
	//TODO - Implementation
	return 0;
}

int Matrix::nrColumns() const {
	//TODO - Implementation
	return 0;
}

TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
	return NULL_TELEM;
}

MatrixIterator Matrix::iterator() {
    return MatrixIterator(*this);
}
