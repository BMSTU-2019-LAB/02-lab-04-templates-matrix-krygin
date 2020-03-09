// Copyright 2018 Ivan Krygin <krygin.ia@gmail.com>

#include <matrix.hpp>

template <class T>
Matrix<T>::Matrix() {
    this->rows = 0;
    this->columns = 0;
    this->table = nullptr;
}