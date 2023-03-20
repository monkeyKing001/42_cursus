#include <array>
#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include "BitcoinExchange.hpp"

int err(std::string err_msg)
{
	std::cout << err_msg << "\n";
	return (1);
}

int	main(int argc, char **argv)
{
	std::ifstream ifs;
	std::string data_file_path;
	std::string input_file_path;
	std::string buf;
	if (argc != 2)
		return (err("Error: could not open file.\n"));
	//reading data.csv
	data_file_path = "data.csv";
	ifs.open(data_file_path);
	if (!ifs.good())
		return (err("Error: could not open file.\n"));
	std::string seperator = ",";

	//bitcoin exchange start
	BitcoinExchange btc;
	std::getline(ifs, buf);
	std::getline(ifs, buf);
	size_t pos = 0;
	pos = buf.find(seperator, pos);
	while (pos != std::string::npos)
	{
		std::string date;
		std::string rate_s;
		float rate;
		date = buf.substr(0, pos);
		rate_s = buf.substr(pos + 1, buf.length());
		rate = stof(rate_s, NULL);
//		std::cout << "date : " << date << " rate : " << rate << "\n";
		btc.insert_rate(date, rate);
		std::getline(ifs, buf);
		pos = buf.find(seperator, pos);
		if (ifs.eof())
			break ;
	}
	ifs.close();
	ifs.open(argv[1]);
//	std::cout << "opened input.txt file!\n";
//	std::map<std::string, float> t = btc.get_ex_map();
//	std::map<std::string, float>::iterator i = t.begin();
//	for (i = t.begin(); i != t.end(); i++) {
//		std::cout << "key, value : " << i -> first << ", " << i -> second << "\n";
//	}
	std::getline(ifs,buf);
	std::getline(ifs,buf);
	pos = 0;
	seperator = "|";
	while (!ifs.eof())
	{
		std::string date;
		std::string coins_s;
		double coins;
		pos = 0;
		pos = buf.find(seperator, pos);
//		std::cout << date << ", " << coins_s << "\n";
		if (pos == std::string::npos)
			std::cout << "Error: bad input => " << buf << "\n";
		else
		{
			date = buf.substr(0, pos);
			coins_s = buf.substr(pos + 2, buf.length());
			coins = stod(coins_s, NULL);
			std::cout << btc.get_multipied_val(date, coins) << "\n";
		}
		std::getline(ifs, buf);
	}
	return (0);
}
