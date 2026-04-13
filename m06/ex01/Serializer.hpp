#pragma once

#include <cstdint>

#include "Data.hpp"

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	// Disable automatic member functions
	~Serializer();
	Serializer();
	Serializer(Serializer const &);
	Serializer operator=(Serializer const &);
};
