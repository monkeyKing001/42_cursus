#ifndef WHATEVER_H
#define WHATEVER_H
#include <iostream>

template< typename _T >
void    swap( _T& a, _T& b )
{
    _T tmp = a;
    a = b;
    b = tmp;
}

template< typename T >
T min( T& a, T& b )
{
    if ( a < b )
        return a;
    else
        return b;
}

template< typename T >
T max( T& a, T& b )
{
    if (a > b)
        return a;
    else
        return b;
}
#endif
