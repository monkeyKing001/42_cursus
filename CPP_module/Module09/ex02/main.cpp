#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<std::string> input_string;
	std::vector<int> nums_vec;
	std::deque<int> nums_deq;
	/*######################################*/
	/*#######       argc check     #########*/
	/*######################################*/
	if (argc < 2)
	{
		std::cout << "Error\n";
		return (1);
	}
	/*######################################*/
	/*#######      vector start     ########*/
	/*######################################*/
	clock_t start_time = clock();
	for (int i = 1; i < argc; i++)
	{
		int num;
		std::stringstream ss;
		ss << argv[i];
		ss >> num;
		if (ss.fail() || num < 0)
		{
			std::cout << "Error\n";
			return (1);
		}
		nums_vec.push_back(num);
	}
	mergesort_vec(0, argc - 2, nums_vec);
	clock_t end_time = clock();
	double elapsed_time_vec = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	/*######################################*/
	/*#######      deque start      ########*/
	/*######################################*/
	start_time = clock();
	for (int i = 1; i < argc; i++)
	{
		int num;
		std::stringstream ss;
		ss << argv[i];
		ss >> num;
		if (ss.fail() || num < 0)
		{
			std::cout << "Error\n";
			return (1);
		}
		nums_deq.push_back(num);
	}
	mergesort_deq(0, argc - 2, nums_deq);
	end_time = clock();
	double elapsed_time_deq = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

	/*######################################*/
	/*#######     print result      ########*/
	/*######################################*/
	std::cout << "Before:\t";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << "\n";
	//print sorted arr
	std::cout << "After:\t";
	for (int i = 0; i < argc - 1; i++)
		std::cout << nums_vec[i] << " ";
	std::cout << "\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with "<< GREEN << "std::vector : "<< elapsed_time_vec <<" us\n" << DEFAULT;
	std::cout << "Time to process a range of " << argc - 1 << " elements with "<< RED << "std::deque : "<< elapsed_time_deq <<" us\n" << DEFAULT;
	return (0);
}

