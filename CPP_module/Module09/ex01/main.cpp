#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error\n";
        exit(1);
    }
    inputcheck_excution(av[1]);
    return (0);
}
