#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


PmergeMe::~PmergeMe()
{
}


PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->vector = rhs.vector;
		deque = rhs.deque;
	}
	return *this;
}

std::vector<int>	PmergeMe::pairing(){
	std::vector<int> max;
	int i = -1;
	while (++i < vector.size() / 2) {
		max[i] = std::max(vector[2 * i], vector[2 * i + 1]);
	}

	if (vector.size() % 2 != 0) {
		max.push_back(vector[vector.size() - 1]);
	}
	return max;
}


std::vector<int>	PmergeMe::recursive(){
	if (vector.size() < 1)
		return ;
	std::vector<int> max = pairing();
	return recursive();
}