#ifndef SPAN_H
#define SPAN_H

#define DEFAULT "\033[0;39m"
#define GRAY "\033[0;90m"
#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define WHITE "\033[0;97m"

#include <iostream>
#include <list>
#include <exception>
#include <cstdlib>

class Span
{
    private:
        std::list<int>  _list;
        unsigned int    _n;

    public:
        Span( void );
        Span( unsigned int );
        Span( const Span& );
        ~Span( void );

        Span&               operator=( const Span& );
        void                addNumber( int );
        void                addNumber( std::list<int>::const_iterator, std::list<int>::const_iterator );
        unsigned int        longestSpan( void ) const;
        unsigned int        shortestSpan( void ) const;

        const std::list< int >*   getList( void ) const;
};

std::ostream& operator<<( std::ostream&, const Span& );
#endif
