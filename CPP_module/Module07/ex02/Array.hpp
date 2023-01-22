#ifndef ARRAY_H
#define ARRAY_H

#define DEFAULT "\033[0;39m"
#define GRAY "\033[0;90m"
#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define WHITE "\033[0;97m"

#include <exception>
#include <iostream>
#include <limits>

template < typename T >
class Array 
{
    private:
        T*              _arr;
        unsigned int    _size;
    public:
		//defualt construct
        Array( void ) : _arr( new T() ), _size( 0 ) {};
		//size construct
        Array( unsigned int n )
		{
//			std::cout << "n : "<< n << "\n";
//			std::cout << "(int)n : "<< (int) n << "\n";
//			if (static_cast<int>(n) < 0
//					|| static_cast<int>(n) >= std::numeric_limits<unsigned int>::max())
//			{
//				std::cout << " size :  " << n << "\n";
//				throw (OutOfBoundsException());
//				return ;
//			}
//			else
//			{
				_arr = new T[n];
				_size = n;
				//init as 0 bit;
				for (unsigned int i = 0; i < n; i++)
				{
					_arr[i] = 0;
				}
//			}
        };

		//copy construct
        Array( const Array& rhs ) : _arr( new T[rhs.size()] ), _size( rhs.size() ) {
            for ( unsigned int i( 0 ); i < _size; i++ )
                _arr[i] = rhs._arr[i];
        };

		//copy assignment construct
        Array& operator=( const Array& rhs ) {
            if ( this != &rhs ) {
                delete [] _arr;
                _arr = new T[rhs.size()];
                _size = rhs._size;
                for ( unsigned int i( 0 ); i < _size; i++ )
                    _arr[i] = rhs._arr[i];
            }
            return *this;
        }

		//overloading [] operator
        T& operator[]( unsigned int i ) const {
            if ( i >= _size )
                throw OutOfBoundsException();
            return _arr[i];
        }

		//getsize
        unsigned int  size( void ) const { return _size; }

        ~Array( void ) { delete [] _arr; }

		//out of bounds exception
        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Index is out of bounds";}
        };
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
	for ( unsigned int i( 0 ); i < arr.size(); i++ )
		out << arr[i] << " ";
    return out;
}
#endif
