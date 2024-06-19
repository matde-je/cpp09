#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif 