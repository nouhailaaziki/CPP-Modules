#include "Serializer.hpp"

int main()
{
    Data* ptr = new Data();

    ptr->username = "noaziki";
    ptr->gender = "Female";
    ptr->id = "LB-4409-PX";
    ptr->position = "Lead Systems Architect";
    ptr->age = 32;
    ptr->years_of_experience = 11;

    Data* original = ptr;

    std::cout << "Original pointer: " << ptr << std::endl;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << restored << std::endl;

    if (original == restored)
        std::cout << "OK: pointers are equal" << std::endl;
    else
        std::cout << "ERROR: pointers are NOT equal" << std::endl;

    delete ptr;
}