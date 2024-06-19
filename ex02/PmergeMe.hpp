#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif