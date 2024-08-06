#include "pch.h"

#include "Matrix.h"


namespace
{

template<class T>
void sPrint( const std::vector<T> v )
{
    for ( int n : v )
        std::cout << n << ' ';
    std::cout << '\n';
}

}

Matrix::Matrix( const Matrix& other )
    : values_( other.values_ )
    , dimensions_( other.dimensions_ )
{
}

Matrix::Matrix( int n, va_list* argptr )
{
    while ( n-- )
    {
        int value = va_arg( *argptr, int );
        dimensions_.push_back( value );
    }

    va_end( *argptr );
}

void Matrix::swap( Matrix&& other )
{
    values_ = std::move( other.values_ );
    dimensions_ = std::move( other.dimensions_ );;
}

void Matrix::setDimensions( const std::vector<int>& dimensions )
{
    dimensions_ = dimensions;
}

const std::vector<int>& Matrix::getDimensions() const
{
    return dimensions_;
}

int Matrix::fill( int n, va_list* argptr )
{
    if ( n != size() )
    {
        return static_cast<int>( Error::InvalidArguments );
    }

    while ( n-- )
    {
        int value = va_arg( *argptr, int );
        values_.push_back( value );
    }

    va_end( *argptr );
    return static_cast<int>( Error::Success );
}

int Matrix::size() const
{
    if ( dimensions_.empty() )
    {
        return 0;
    }
    int size = 1;
    for ( int d : dimensions_ )
    {
        size *= d;
    }
    return size;
}

void Matrix::print()
{
    //sPrint( dimensions_ );
    //sPrint( values_ );

    auto getCounter = [this]( int i )
    {
        int counter = 1;
        for ( int j = i; j < dimensions_.size(); ++j )
        {
            counter *= dimensions_[j];
        }
        return counter;
    };

    auto initCounters = dimensions_;
    for ( int i = 0; i < initCounters.size(); ++i )
    {
        initCounters[i] = getCounter( i );
    }

    auto counters = initCounters;

    bool isFirst = true;
    for ( auto& v : values_ )
    {
        for ( int i = 0; i < counters.size(); ++i )
        {
            if ( counters[i] == initCounters[i] )
            {
                std::cout << "[ ";
                isFirst = true;
                
            }
        }

        if ( isFirst )
        {
            isFirst = false;
        }
        else
        {
            std::cout << ", ";
        }
        std::cout << v;

        for ( int i = counters.size() - 1; i >= 0; --i )
        {
            --counters[i];
            if ( counters[i] == 0 )
            {
                std::cout << " ]";
                counters[i] = initCounters[i];
            }
        }
    }
    std::cout << "\n";

    return;
}

void Matrix::sort()
{
    std::sort( values_.begin(), values_.end() );
}

void Matrix::operator+=( const Matrix& otherMatrix )
{
    if ( dimensions_ != otherMatrix.dimensions_ )
    {
        throw static_cast<int>( Error::InvalidArguments );
    }

    for ( size_t i = 0; i < values_.size(); ++i )
    {
        values_[i] += otherMatrix.values_[i];
    }
}

void Matrix::operator-=( const Matrix& otherMatrix )
{
    if ( dimensions_ != otherMatrix.dimensions_ )
    {
        throw static_cast<int>( Error::InvalidArguments );
    }

    for ( size_t i = 0; i < values_.size(); ++i )
    {
        values_[i] -= otherMatrix.values_[i];
    }
}

void Matrix::operator*=( const Matrix& otherMatrix )
{
    if ( dimensions_.size() != 2 || otherMatrix.dimensions_.size() != 2 )
    {
        throw static_cast<int>( Error::InvalidArguments );
    }

    if ( dimensions_[1] !=  otherMatrix.dimensions_[0] ) // [2x3] * [3x1] = [2x1]
    {
        throw static_cast<int>( Error::WrongDimension );
    }

    int d1 = dimensions_[0];
    int d2 = dimensions_[1];
    int d3 = otherMatrix.dimensions_[1];
   
    std::vector<int> newDimensions;
    newDimensions.push_back( d1 );
    newDimensions.push_back( d3 );

    auto result = Matrix();
    result.setDimensions( newDimensions );
    result.values_.resize( result.size(), 0 );

    for ( int i = 0; i < d1; i++ )
    {
        for ( int j = 0; j < d3; j++ )
        {
            int resIdx = i * d3 + j;
            result.values_[resIdx] = 0;

            for ( int k = 0; k < d2; k++ )
            {
                int idx1 = i * d2 + k;
                int idx2 = k * d3 + j;
                result.values_[resIdx] += values_[idx1] * otherMatrix.values_[idx2];
            }
        }
    }
    dimensions_ = result.dimensions_;
    values_ = result.values_;
}
