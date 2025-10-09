#pragma once

#include <string>

class Brain
{
public:
	~Brain();
	Brain();
	Brain(Brain const &other);
	Brain &operator=(Brain const &other);

	void setIdea(unsigned int index, std::string idea);
	std::string getIdea(unsigned int index);

private:
	static unsigned int const capacity = 100;
	std::string ideas[capacity];
};
