#pragma once

#include <string>

class ICharacter;

class AMateria
{
public:
	virtual ~AMateria();

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) const = 0;

protected:
	// Only derived classes may create or assign
	AMateria(std::string const &type);
	AMateria(AMateria const &other);
	AMateria &operator=(AMateria const &other);

private:
	// Default construction is forbidden, type is required
	AMateria();

	std::string type;
};
