#pragma once

#include <stack>

class RPN
{
public:
	~RPN();
	RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);

	void inputSymbol(char symbol);
	int getResult() const;

private:
	std::stack<int> stack;
};
