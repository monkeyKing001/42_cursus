#include "RPN.hpp"

void    inputcheck_excution(char *input)
{
    std::stringstream   ss(input);
    std::stack<int> rpn;
    std::string token;

    while (ss >> token)
    {
        if (token.compare("+") == 0 || token.compare("-") == 0 || token.compare("*") == 0 || token.compare("/") == 0)
        {
            std::string err_ch = calculation(rpn, token);
            if (err_ch.compare("Error") == 0) exit(1);
        }
        else
        {
			int i = 0;
			while (i < (int)token.length())
			{
				if (!isdigit(token[i]))
				{
					std::cerr << "Error: Bad input number.\n";
					exit(1);
				}
				i++;
			}
			std::stringstream ss_for_num(token);
			int num = 0;
			ss_for_num >> num;
            if (ss_for_num.fail() || num > 10)
            {
                std::cerr << "Error: Bad input number.\n";
                exit(1);
            }
            rpn.push(num);
        }
    }
    if (rpn.size() == 1)
    {
        std::cout << rpn.top() << "\n";
    }
    else
    {
        std::cerr << "Error: Bad input.\n";
        exit(1);
    }
}

std::string calculation(std::stack<int> &rpn, std::string op)
{
    if (rpn.size() < 2)
    {
        std::cerr << "Error: Wrong expression.\n";
        return ("Error.");
    }
    else
    {
        int tmp2 = rpn.top(); rpn.pop();
        int tmp1 = rpn.top(); rpn.pop();

        int res;
        if (op.compare("+") == 0)
            res = tmp1 + tmp2;
        else if (op.compare("-") == 0)
            res = tmp1 - tmp2;
        else if (op.compare("*") == 0)
            res = tmp1 * tmp2;
        else
        {
            if (tmp2 == 0) 
            {
                std::cerr << "Error: Division by zero.\n";
                return ("Error");
            }
            res = tmp1 / tmp2;
        }
        rpn.push(res);
        return ("ok");
    }
}
