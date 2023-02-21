#include "easyfind.hpp"
#include <algorithm>

int main( int ac, char ** av )
{
    if ( ac != 2 )
        return ( -1 );

    // std::vector< int > vect;
    // std::list< int > list;

    // for (int i = 1; i < 11; i++)
    // {
    //     vect.push_back(i);
    //     list.push_back(i);
    // }

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector< int >  vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::list< int >    list( arr, arr + sizeof( arr ) / sizeof( int ) );
	//std::cout << list[3] << "\n"

    easyfind( vect, std::atoi( av[1] ));
    easyfind( list, std::atoi( av[1] ));

    return ( 0 );
}
