#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	this -> exchange_rate_by_date = obj.get_ex_map();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this -> exchange_rate_by_date = obj.get_ex_map();
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<std::string, float> BitcoinExchange::get_ex_map() const
{
	return (this -> exchange_rate_by_date);
}

float get_ex_rate(std::string date)
{
	std::cout << "getting ex_rate of date " << date << "\n";
	return (0);
}

void BitcoinExchange::insert_rate(std::string date, float rate)
{
	std::map <std::string, float>::iterator iter = this->exchange_rate_by_date.end();
	if (this -> exchange_rate_by_date.size() == 0)
	{
		this -> exchange_rate_by_date.insert(std::make_pair(date, rate));
		return ;
	}
	else {
		--iter;
		if (iter -> second == rate)
			return ;
		else
			this -> exchange_rate_by_date.insert(std::make_pair(date, rate));
	}
//	std::cout << "inserting rate : " << rate << "\n";
//	std::cout << "last key, rate : " << iter -> first << ", " << iter->second << "\n";
}

std::string BitcoinExchange::get_multipied_val(std::string date, double coins)
{
	std::map<std::string, float> t = this -> exchange_rate_by_date;
	std::map<std::string, float>::iterator i = t.begin();
	std::map<std::string, float>::iterator i2 = i;
	std::string ret = "";
	if (coins < 0)
	{
		ret = "Error: not a positive number.";
		return (ret);
	}
	if ((long long)coins > 1000)
	{
		ret = "Error: too large a number.";
		return (ret);
	}
	if ((date[5] >= '1' && date[6] >= '3') || (date[8] >= '3' && date[9] >= '2'))
	{
		ret = "Error: bad input => ";
		ret.append(date);
		return (ret);
	}
	i2++;
	for (;i2 != t.end(); i++, i2++)
	{
		if ((date.compare(i -> first) == 0) || (date.compare(i -> first) > 0 && date.compare(i2 -> first) < 0))
		{
			std::ostringstream ss;
			ss.precision(2);
			ret.append(date);
			ret.append("=> ");
			ss << coins;
			ret.append(ss.str());
			ss.str("");
			ret.append(" = ");
			ss << coins * (i -> second);
			ret.append(ss.str());
		}
		else 
			continue ;
	}
	if (ret.length() == 0)
	{
		ret = "Error: unvaild date => ";
		ret.append(date);
		return (ret);
	}
	return (ret);
}
