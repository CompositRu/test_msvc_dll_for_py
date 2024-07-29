#pragma once

#include "exports.h"

extern "C" void EXPORTS_API testFunc();


class Node
{
public:
    Node()
    {
        deep_ = 0;
    };

    template <typename... Args>
    Node( Args... dimensions )
    {
        deep_ = sizeof...( dimensions );

        create_( dimensions... );
    };

    //~Node();

    template <typename... Args>
    void fill( Args... values )
    {
        //static_assert( sizeof...( values ) == values_.size(), "" );
        fill_( values... );
    };

    void call()
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
        for ( auto& v : values_ )
        {
            for ( int i = 0; i < counters.size(); ++i )
            {
                if ( counters[i] == initCounters[i] )
                {
                    std::cout << "(" << deep_ - i << ")";
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
            
            for ( int i = 0; i < counters.size(); ++i )
            {
                --counters[i];
                if ( counters[i] == 0 )
                {
                    std::cout << " ]";
                    counters[i] = initCounters[i];
                }
            }
        }
    }
private:
    std::vector<double> values_;
    std::vector<int> dimensions_;
    size_t deep_ = 0;

    template <typename T>
    void create_( T d )
    {
        static_assert( std::is_same_v<T, int>, "The number of matrix elements can only be integers" );
        dimensions_.push_back( d );

        auto size = 1;
        for ( auto d : dimensions_ )
        {
            size *= d;
        }

        values_.resize( size, 1 );
    }

    template <typename T, typename... Args>
    void create_( T d, Args... dimensions )
    {
        //static_assert( std::is_same_v<T, int>, "The number of matrix elements can only be integers" );
        static_assert( std::is_same_v<T, int>, "" );
        dimensions_.push_back( d );
        create_( dimensions... );
    }

    template <typename T>
    void fill_( T newValue )
    {
        static_assert( std::is_floating_point<T>::value || std::is_integral<T>::value, "" );
        values_.back() = newValue;
    }

    template <typename T, typename... Args>
    void fill_( T newValue, Args... values )
    {
        static_assert( std::is_floating_point<T>::value || std::is_integral<T>::value, "" );
        size_t idx = values_.size() - sizeof...( values ) - 1;
        values_[idx] = newValue;
        fill_( values... );
    }
};

class EXPORTS_API Matrix
{
public:
    Matrix();

    void f();
private:

};