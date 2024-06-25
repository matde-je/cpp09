#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
#include <deque>
#include <vector>
#include <ctime>
#include <algorithm>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );
		std::deque<int> deque;
		std::vector<int> vector;
		std::vector<int>	pairing();
		std::vector<int>	recursive();

	private:

};

#endif