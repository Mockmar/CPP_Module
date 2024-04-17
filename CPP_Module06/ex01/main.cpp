
#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    Data *data2;
    uintptr_t raw;
    data->nb = 42;
    data->name = "Example";


    std::cout << data << std::endl;
    std::cout << data->nb << std::endl;
    std::cout << data->name << std::endl;
    raw = Serializer::serialize(data);
    std::cout << raw << std::endl;
    data2 = Serializer::deserialize(raw);
    std::cout << data2 << std::endl;
    std::cout << data2->nb << std::endl;
    std::cout << data2->name << std::endl;
    delete (data);
    return 0;
}
