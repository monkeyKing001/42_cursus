#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{
    public:

        MutantStack( void ) {};
        ~MutantStack( void ) {};

        MutantStack( const MutantStack& rhs ) { *this = rhs; }
        MutantStack&    operator=( const MutantStack& rhs ) {
            std::stack< T, Container >::operator=( rhs );
            return *this;
        }

        typedef typename Container::iterator    iterator;

        iterator    begin() { return this->c.begin(); }
        iterator    end() { return this->c.end(); }
};

// template < typename T >
// class MutantStack : public std::stack< T >
// {
//     public:
//         MutantStack( void ) {};
//         ~MutantStack( void ) {};

//         MutantStack( const MutantStack& rhs ) { *this = rhs; };
//         MutantStack& operator=( const MutantStack& rhs ) { *this = rhs; return (*this); }

//         typedef typename MutantStack< T >::stack::container_type::iterator iterator;
//         iterator begin( void ) { return this->c.begin(); }
//         iterator end( void ) { return this->c.end(); }

//         // typedef typename MutantStack< T >::stack::container_type::reverse_iterator reverse_iterator;
//         // reverse_iterator rbegin( void ) { return this->c.rbegin(); }
//         // reverse_iterator rend( void ) { return this->c.rend(); }

//         // typedef typename MutantStack< T >::stack::container_type::const_iterator const_iterator;
//         // const_iterator cbegin( void ) { return this->c.cbegin(); }
//         // const_iterator cend( void ) { return this->c.cend(); }

//         // typedef typename MutantStack< T >::stack::container_type::const_reverse_iterator const_reverse_iterator;
//         // const_iterator crbegin( void ) { return this->c.crbegin(); }
//         // const_iterator crend( void ) { return this->c.crend(); }
// };

#endif /* MUTANTSTACK_H */
