#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>

class BitcoinExchange
{

	private:
		std::map<std::string, float> exchange_rate_by_date;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator = (const BitcoinExchange& obj);
		~BitcoinExchange(void);
		std::string get_multipied_val(std::string date, double coins);
		float get_ex_rate(std::string date);
		std::map<std::string, float> get_ex_map() const;
		void insert_rate(std::string date, float rate);
};

#endif /* BITCOINEXCHANGE_HPP */
