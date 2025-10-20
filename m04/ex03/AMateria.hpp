#pragma once

#include <string>

class ICharacter;

class AMateria
{
public:
	virtual ~AMateria();

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) = 0;

protected:
	// Only derived classes may create
	AMateria(std::string const &type);
	// Only derived classes may copy
	AMateria(AMateria const &other);

private:
	// Default construction is forbidden, type is required
	AMateria();
	// Assignment to change type is forbidden, only derived classes of matching type should be assigned
	AMateria &operator=(AMateria const &other);

	std::string type;
};
