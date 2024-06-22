#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data = new Data;
    data->a = 42;
    

    std::cout << "a : " << data->a<<std::endl;

    uintptr_t Ptr = Serializer::serialize(data);
    std::cout<<"---------------" << std::endl;
    std::cout << Ptr << std::endl;
    std::cout<<"---------------" << std::endl;

    float *ptr = reinterpret_cast<float *>(Ptr);
    std::cout << "----------------" << std::endl;
    std::cout << *ptr << std::endl;
    *ptr += 0.5;
    std::cout << *ptr << std::endl;
    std::cout << "----------------" << std::endl;

    Data *tmp = NULL;
    tmp = Serializer::deserialize(Ptr);
    std::cout << "a : " << tmp->a<<std::endl;
    
    delete data;
    return 0;
}
