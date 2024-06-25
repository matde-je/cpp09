#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
#include <stack>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );
		std::stack<int> stack;
		void	operation(char *av);

	private:

};


#endif 