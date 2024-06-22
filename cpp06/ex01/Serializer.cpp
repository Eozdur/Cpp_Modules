#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr)
{
    return reinterpret_cast<Data *>(ptr);
}

Serializer::Serializer(void)
{
    return;
}

Serializer::~Serializer(void)
{
    return;
}

Serializer::Serializer(const Serializer& copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer& copy)
{
    if(this != &copy)
    {
        *this = copy;
    }
    return *this;
}