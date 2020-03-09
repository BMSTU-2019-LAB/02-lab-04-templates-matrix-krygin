// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_MATRIX_HPP_
#define INCLUDE_MATRIX_HPP_

template<class T>
class Matrix {
    int rows{};
    int columns{};
    T **table;

    static bool check_dimensions(const Matrix<T> &op1, const Matrix<T> &op2) {
        return op1.get_rows() == op2.get_rows()
        && op1.get_columns() == op2.get_columns();
    }

public:
    Matrix();

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


    Matrix(const Matrix<T> &source) {
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

    T *operator[](int i) const {
        return table[i];
    }

    Matrix<T>& operator=(const Matrix<T> &source) {
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

    friend bool operator!=(const Matrix<T> &op1, const Matrix<T> &op2) {
        return !(op1 == op2);
    }

    Matrix<T> &operator+(const Matrix<T> &other) {
        if (check_dimensions(*this, other)) {
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->columns; j++) {
                    this->table[i][j] += other[i][j];
                }
            }
        } else {
            rows = 0;
            columns = 0;
            table = nullptr;
        }
        return *this;
    }

    Matrix<T> &operator-(const Matrix<T> &other) {
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

    friend Matrix<T> operator*(const Matrix<T> &op1, const Matrix<T> &op2) {
        Matrix<T> result;
        if (op1.columns == op2.rows) {
            result = Matrix(op1.rows, op2.columns);
            for (int i = 0; i < result.rows; i++) {
                for (int j = 0; j < result.columns; j++) {
                    int sum = 0;
                    for (int k = 0; k < result.columns; k++) {
                        sum += op1.table[i][k] * op2.table[k][j];
                    }
                    result[i][j] = sum;
                }
            }
        } else {
            result = Matrix();
            result.rows = 0;
            result.columns = 0;
            result.table = nullptr;
        }
        return result;
    }


    int get_rows() const {
        return rows;
    }

    int get_columns() const {
        return columns;
    }

    ~Matrix(){
        for (int i = 0; i < rows; i++) {
            delete[] table[i];
        }
        delete [] table;
    }
};

#endif // INCLUDE_MATRIX_HPP_
