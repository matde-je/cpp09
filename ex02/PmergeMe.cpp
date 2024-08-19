#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe( const PmergeMe & src ) {
	*this = src;
}

PmergeMe::~PmergeMe()
{}

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs ) {
		this->vector = rhs.vector;
		deque = rhs.deque;
	}
	return *this;
}




