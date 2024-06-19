#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
}


RPN::~RPN()
{
}


RPN &				RPN::operator=( RPN const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


