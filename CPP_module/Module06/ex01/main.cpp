#include <string>
#include <iomanip>
#include <iostream>
struct Data
{
    std::string name;
	int			left_blackhole;
};

uintptr_t    serialize( Data *data ) {
    return ( reinterpret_cast< uintptr_t >( data ) );
}

Data*   deserialize( uintptr_t data ) {
    return ( reinterpret_cast< Data* >( data ) );
}

int main( void )
{
    Data *data = new Data;
	uintptr_t casted;

	casted = serialize(data);
    data->name = "dokwak";
    data->left_blackhole = 5;

	std::cout << "\n==============================     address test     ===============================\n";
	std::cout << "data address : \t\t"<< data << "\n";
	std::cout << "uintptr_t's value : \t"<< "0x" << std::setw(sizeof(uintptr_t)) << std::setfill('0') << std::hex << casted << "\n";
	std::cout << "uintptr_t's value as decimal : \t"<< casted << "\n";

	std::cout << "\n==============================     object test     ===============================\n";
    std::cout << "Name: " << data -> name << "\n";
    std::cout << "Left Blackhole days : " << data->left_blackhole << "\n";

	std::cout << "\n==============================     object casting test     ===============================\n";
    std::cout << "Name: " << deserialize( serialize( data ) )->name << "\n";
    std::cout << "Left Blackhole days : " << deserialize( casted )->left_blackhole << "\n";

    delete data;

    return EXIT_SUCCESS;
}
