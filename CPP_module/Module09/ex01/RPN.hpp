#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

void inputcheck_excution(char *input);
std::string calculation(std::stack<int> &rpn, std::string op);

#endif
