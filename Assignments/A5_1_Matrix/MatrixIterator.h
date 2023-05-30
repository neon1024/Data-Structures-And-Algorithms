#pragma once

#include "Matrix.h"

typedef int TElem;
typedef int TComp;
#define NULL_TELEM 0

class Matrix;

class MatrixIterator {
private:
    friend class Matrix;
    const Matrix& matrix;

public:
    explicit MatrixIterator(const Matrix &matrix);

    void first();

    bool valid();

    void next();

    TElem get_current();
};
