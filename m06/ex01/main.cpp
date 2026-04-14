#include <cstdint>
#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	double d = 3.14f;
	Data data;
	data.i = 42;
	data.dp = &d;

	Data *dataPtr = &data;
	std::cout << "Original Data ptr: " << dataPtr << "\n";

	uintptr_t serialized = Serializer::serialize(dataPtr);
	std::cout << "\nSerialized value (uintptr_t): " << serialized << "\n";

	Data *deserializedData = Serializer::deserialize(serialized);
	std::cout << "\nDeserialized Data ptr: " << deserializedData << "\n";

	return 0;
}
