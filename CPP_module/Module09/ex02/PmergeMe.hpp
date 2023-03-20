#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#define RED  "\033[0;91m"
#define GREEN "\033[0;92m"
#define DEFAULT "\033[0;39m"
class PmergeMe
{

	private:

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator = (const PmergeMe& obj);
		~PmergeMe(void);

};
std::vector<int>mergesort_vec(int start, int end, std::vector<int>&vec);
std::vector<int>merge_vec(int start, int mid, int end, std::vector<int>&vec);
std::deque<int>mergesort_deq(int start, int end, std::deque<int>&deq);
std::deque<int>merge_deq(int start, int mid, int end, std::deque<int> &deq);

#endif /* PMERGEME_HPP */
