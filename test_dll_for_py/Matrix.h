#pragma once

#include "exports.h"


class Matrix
{
public:
    Matrix() {};
    Matrix( int n, va_list* arg );
    void fill( int n, va_list* arg );
    int size();
    void debugCall();

private:
    std::vector<double> values_;
    std::vector<int> dimensions_;
};