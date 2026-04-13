#include "Serializer.hpp"

#include <cstdint>

#include "Data.hpp"

// The project requirements are nonsense!
// We're not serializing the Data struct, we're just converting a pointer to an integer and back.
// The deserialized pointer is only valid in the same process, and only if the original pointer is still valid.

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
