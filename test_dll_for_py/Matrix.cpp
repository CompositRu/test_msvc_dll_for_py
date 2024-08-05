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

Matrix::Matrix( int n, va_list* argptr )
{
    while ( n-- )
    {
        int value = va_arg( *argptr, int );
        dimensions_.push_back( value );
    }

    va_end( *argptr );
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

int Matrix::size()
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

void Matrix::debugCall()
{
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
    int intends = 0;
    auto printIntends = [&intends]()
    {
        for ( int j = 0; j < intends; ++j )
        {
            std::cout << " ";
        }
    };
    for ( auto& v : values_ )
    {
        for ( int i = 0; i < counters.size(); ++i )
        {
            if ( counters[i] == initCounters[i] )
            {
                //std::cout << "(" << dimensions_.size() - i << " level )";
                //intends = i * 2;
                //printIntends();

                std::cout << "[ ";
                //if ( i != counters.size() - 1 )
                //{
                //    std::cout << "\n";
                //}
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
                //if ( i != counters.size() - 1 )
                //{
                //    std::cout << "\n";
                //    printIntends();
                //}
                //else
                //{
                //    std::cout << " ";
                //}
                std::cout << " ]";
                counters[i] = initCounters[i];
            }
        }
    }
    std::cout << "\n";

    return;
}
