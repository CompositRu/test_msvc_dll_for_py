#pragma once

#include "exports.h"


enum class Error
{
    Success = 0,
    InvalidArguments,
    WrongDimension
};

class Matrix
{
public:
    Matrix() {};
    Matrix( const Matrix& other );
    Matrix( int n, va_list* arg );

    void swap( Matrix&& other );
    void setDimensions( const std::vector<int>& dimensions );
    const std::vector<int>& getDimensions() const;
    int fill( int n, va_list* arg );
    int size() const;
    void print();
    void sort();

    void operator+=( const Matrix& otherMatrix );
    void operator-=( const Matrix& otherMatrix );
    void operator*=( const Matrix& otherMatrix );

private:
    std::vector<double> values_;
    std::vector<int> dimensions_;
};