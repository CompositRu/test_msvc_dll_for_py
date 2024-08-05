#pragma once

#include "exports.h"


enum class Error
{
    Success = 0,
    InvalidArguments
};

class Matrix
{
public:
    Matrix() {};
    Matrix( const Matrix& other );
    Matrix( int n, va_list* arg );
    void setDimensions( const std::vector<int>& dimensions );
    const std::vector<int>& getDimensions() const;
    int fill( int n, va_list* arg );
    int size();
    void debugCall();
    void sort();

    void operator+=( const Matrix& otherMatrix );
private:
    std::vector<double> values_;
    std::vector<int> dimensions_;
};