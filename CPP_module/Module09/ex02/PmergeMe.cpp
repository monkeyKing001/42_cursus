#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj){(void)obj; return (*this);}

PmergeMe::PmergeMe(const PmergeMe& obj){(void)obj;}

std::deque<int>merge_deq(int start, int mid, int end, std::deque<int> &deq)
{
	std::deque<int> temp(deq);
	int l_s = start;
	int l_e = mid;
	int r_s = mid + 1;
	int r_e = end;
	int i = l_s;
	while (l_s <= l_e && r_s <= r_e)
	{
		if (temp[l_s] <= temp[r_s])
			deq[i++] = temp[l_s++];
		else if (temp[l_s] > temp[r_s])
			deq[i++] = temp[r_s++];
	}
	while (l_s <= l_e)
		deq[i++] = temp[l_s++];
	while (r_s <= r_e)
		deq[i++] = temp[r_s++];
	return (deq);
}

std::deque<int>mergesort_deq(int start, int end, std::deque<int>&deq)
{
	if (start == end)
		return (deq);
	int mid = (end + start) / 2;
	mergesort_deq(start, mid, deq);
	mergesort_deq(mid + 1, end, deq);
	merge_deq(start, mid, end, deq);
	return (deq);
}


std::vector<int>merge_vec(int start, int mid, int end, std::vector<int>&vec)
{
	std::vector<int> temp(vec);
	int l_s = start;
	int l_e = mid;
	int r_s = mid + 1;
	int r_e = end;
	int i = l_s;
	while (l_s <= l_e && r_s <= r_e)
	{
		if (temp[l_s] <= temp[r_s])
			vec[i++] = temp[l_s++];
		else if (temp[l_s] > temp[r_s])
			vec[i++] = temp[r_s++];
	}
	while (l_s <= l_e)
		vec[i++] = temp[l_s++];
	while (r_s <= r_e)
		vec[i++] = temp[r_s++];
	return (vec);
}

std::vector<int>mergesort_vec(int start, int end, std::vector<int>&vec)
{
	if (start == end)
		return (vec);
	int mid = (end + start) / 2;
	mergesort_vec(start, mid, vec);
	mergesort_vec(mid + 1, end, vec);
	merge_vec(start, mid, end, vec);
	return (vec);
}
