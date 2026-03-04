#include "Serializer.hpp"

int main()
{
    Data data;

    data.username = "noaziki";
    data.gender = "Female";
    data.id = "LB-4409-PX";
    data.position = "Lead Systems Architect";
    data.age = 32;
    data.years_of_experience = 11;

    Data* original = &data;

    std::cout << "Original pointer: " << original << std::endl;

    uintptr_t raw = Serializer::serialize(original);

    std::cout << "Serialized value: " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Deserialized pointer: " << restored << std::endl;

    if (original == restored)
        std::cout << "OK: pointers are equal" << std::endl;
    else
        std::cout << "ERROR: pointers are NOT equal" << std::endl;

    return (0);
}