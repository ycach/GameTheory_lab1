#ifndef MATRIXROW_H
#define MATRIXROW_H
#include <vector>

template<typename T>
class MatrixRow{
public:
    explicit MatrixRow(int columns){
        if(columns >=0)
            elms = static_cast<size_t>(columns);
        else
            elms = 1;

        row.reserve(this->elms);
    }
    ~MatrixRow() = default;
public:
    T& operator[](int index) {
        return row[static_cast<size_t>(index)];
    }

    const T& operator[](int index) const {
        return row[static_cast<size_t>(index)];
    }

    size_t GetSize() const {
        return row.size();
    }
private:
    std::vector<T> row;
    size_t elms;

};
#endif // MATRIXROW_H
