#ifndef MATRIX_H
#define MATRIX_H

#include "MatrixRow.h"

template<typename T>
class Matrix{
public:
    explicit Matrix(int rows, int columns){

        if (rows <= 0 || columns <= 0){
            this->rows = 1;
            this->columns = 1;
        }
        else{
            this->rows = static_cast<size_t>(rows);
            this->columns = static_cast<size_t>(columns);
        }

        matrix.reserve(this->rows);
        for (int i = 0; i < this->rows; i++) {
            matrix.emplace_back(this->columns);
        }
    }
    ~Matrix() = default;
public:
    MatrixRow<T>& operator[](size_t index) {
        return matrix[index];
    }

    const MatrixRow<T>& operator[](size_t index) const {
        return matrix[index];
    }


private:
    std::vector<MatrixRow<T>> matrix;
    size_t rows;
    size_t columns;
};
#endif // MATRIX_H
