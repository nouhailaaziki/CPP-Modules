#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer&)
{}

Serializer& Serializer::operator=(const Serializer&)
{
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    return (addr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}

Serializer::~Serializer()
{}
        