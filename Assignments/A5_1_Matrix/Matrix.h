#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TComp;
#define NULL_TELEM 0

class Matrix {
private:
	//TODO - Representation
    /// Sparse Matrix \n
    /// The elements are of form \<line, column, value\>, value != 0 \n
    /// The elements are stored in a Binary Search Tree \n

    struct BSTNode {
        TComp line;
        TComp column;
        TElem value;

        BSTNode* left;
        BSTNode* right;
    };

    int number_of_lines;
    int number_of_columns;

    BSTNode* root;

public:
	// constructor
	Matrix(int nrLines, int nrCols);

	// returns the number of lines
	int nrLines() const;

	// returns the number of columns
	int nrColumns() const;

	// returns the element from line i and column j (indexing starts from 0)
	// throws exception if (i,j) is not a valid position in the Matrix
	TElem element(TComp i, TComp j) const;

	// modifies the value from line i and column j
	// returns the previous value from the position
	// throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(TComp i, TComp j, TElem e);

    // destructor
    ~Matrix();
};
