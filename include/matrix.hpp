// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_MATRIX_HPP_
#define INCLUDE_MATRIX_HPP_

template<class T>
class Matrix {
    int rows{};
    int columns{};
    T** table;

    static bool check_dimensions(const Matrix<T>& op1, const Matrix<T>& op2) {
        return op1.get_rows() == op2.get_rows() && op1.get_columns() == op2.get_columns();
    }

public:
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        table = new T *[rows];
        for (int i = 0; i < rows; i++) {
            table[i] = new T[columns];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                table[i][j] = 0;
            }
        }
    }


    Matrix(const Matrix<T>& source) {
        this->rows = source.rows;
        this->columns = source.columns;
        table = new T *[rows];
        for (int i = 0; i < rows; i++) {
            table[i] = new T[columns];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                table[i][j] = source.table[i][j];
            }
        }
    }

    T*operator[](int i) const {
        return table[i];
    }

    Matrix<T> operator=(const Matrix<T> &source) {
        this->rows = source.rows;
        this->columns = source.columns;
        table = new T *[rows];
        for (int i = 0; i < rows; i++) {
            table[i] = new T[columns];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                table[i][j] = source.table[i][j];
            }
        }
        return *this;
    }

    friend bool operator==(const Matrix<T> &op1, const Matrix<T> &op2) {
        if (check_dimensions(op1, op2)) {
            for (int i = 0; i < op1.rows; i++) {
                for (int j = 0; j < op1.columns; j++) {
                    if (op1.table[i][j] != op2.table[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    friend bool operator!=(const Matrix<T>& op1, const Matrix<T>& op2) {
        return !(op1 == op2);
    }

    Matrix<T>& operator+(const Matrix<T>& other) {
        if (check_dimensions(*this, other)) {
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->columns; j++) {
                    this->table[i][j]+=other[i][j];
                }
            }
        } else {
            rows = 0;
            columns = 0;
            table = nullptr;
        }
        return *this;
    }

    Matrix<T>& operator-(const Matrix<T>& other) {
        if (check_dimensions(*this, other)) {
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->columns; j++) {
                    this->table[i][j] -= other[i][j];
                }
            }
        } else {
            rows = 0;
            columns = 0;
            table = nullptr;
        }
        return *this;
    }

    Matrix<T>& operator*(const Matrix<T>& other) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->table[i][j]*=other.table[i][j];
            }
        }
        return *this;
    }


    int get_rows() const {
        return rows;
    }

    int get_columns() const {
        return columns;
    }

    Matrix<T> invert() {
        return *this;
    }
};

#endif // INCLUDE_MATRIX_HPP_
