#pragma once

#include "MatrixIterator.h"

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class MatrixIterator;

class Matrix {
private:
    friend class MatrixIterator;

	//TODO - Representation
    /// Sparse Matrix \n
    /// The elements are of form \<line, column, value\>, value != 0 \n
    /// The elements are stored in a Binary Search Tree \n
    int number_of_lines;
    int number_of_columns;

public:
	// constructor
	Matrix(int nrLines, int nrCols);

    // copy constructor
    Matrix(const Matrix& matrix);

	// returns the number of lines
	int nrLines() const;

	// returns the number of columns
	int nrColumns() const;

	// returns the element from line i and column j (indexing starts from 0)
	// throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	// modifies the value from line i and column j
	// returns the previous value from the position
	// throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

    MatrixIterator iterator();
};
