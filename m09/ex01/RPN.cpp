#include "RPN.hpp"

#include <limits>
#include <stdexcept>

RPN::~RPN()
{
}

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
	: stack(other.stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return *this;
}

static bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

void RPN::inputSymbol(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		stack.push(symbol - '0');
		return;
	}
	if (!isOperator(symbol))
		throw std::runtime_error("Unknown symbol");

	if (stack.size() < 2)
		throw std::runtime_error("Not enough operands");

	int operand = stack.top();
	stack.pop();

	// Using a larger type is much easier than checking for overflow before every operation
	long long currentValue = stack.top();
	stack.pop();

	switch (symbol)
	{
	case '+':
		currentValue += operand;
		break;
	case '-':
		currentValue -= operand;
		break;
	case '*':
		currentValue *= operand;
		break;
	case '/':
		if (operand == 0)
			throw std::runtime_error("Division by zero");
		currentValue /= operand;
		break;
	}
	if (currentValue < std::numeric_limits<int>::min() ||
		currentValue > std::numeric_limits<int>::max())
		throw std::runtime_error("Overflow");
	stack.push(static_cast<int>(currentValue));
}

int RPN::getResult() const
{
	if (stack.size() != 1)
		throw std::runtime_error("Incomplete expression");
	return stack.top();
}
