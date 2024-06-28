#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	*this = src;
}


RPN::~RPN()
{
}


RPN &				RPN::operator=( RPN const & rhs )
{
	if (this != &rhs)
		this->stack = rhs.stack;
	return *this;
}


void	RPN::operation(char *av){
	int i = -1;
	int a;
	int b;
	while (av[++i]){
		if (isdigit(av[i]))
			stack.push(av[i] - 48);
		else {
			if (av[i] == ' ')
				continue ;
			if (stack.size() < 2) 
				{std::cerr << "Error\n"; return ;}
			b = stack.top();
			stack.pop();
			a = stack.top();
			stack.pop();
			if (av[i] == '+') 
				stack.push(a + b);
			else if (av[i] == '-') 
				stack.push(a - b);
			else if (av[i] == '*') 
				stack.push(a * b);
			else if (av[i] == '/') {
				if (b == 0)
					{std::cerr << "Error\n"; return ;}
				stack.push(a / b);
			}
			else {std::cerr << "Error\n"; return ;}
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		 std::cerr << "Error\n";
}

