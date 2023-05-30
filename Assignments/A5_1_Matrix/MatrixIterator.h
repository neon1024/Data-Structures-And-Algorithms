#include "Matrix.h"

class Matrix;

class MatrixIterator {
private:
    friend class Matrix;
    Matrix matrix;

public:
    explicit MatrixIterator(Matrix matrix);

    void first();

    bool valid();

    void next();

    TElem get_current();
};
