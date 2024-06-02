#include "Serializer.hpp"

void printData(const std::string& label, Data* data) {
    std::cout << label << ":\n";
    std::cout << "\taddress: " << data << "\n";
    std::cout << "\tname: " << data->name << "\n";
    std::cout << "\tage: " << data->age << "\n";
    std::cout << "\taddress next: " << data->next << "\n";
    if (data->next) {
        std::cout << "\t\tnext->address: " << data->next << "\n";
        std::cout << "\t\tnext->name: " << data->next->name << "\n";
        std::cout << "\t\tnext->age: " << data->next->age << "\n";
    }
    std::cout << std::endl;
}

int main() {
    Data ptr2("koko tit", 42, nullptr);
    Data ptr("nono bit", 42, &ptr2);
    Serializer a;

    std::cout << "Original Data structures:" << std::endl;
    printData("ptr", &ptr);
    printData("ptr2", &ptr2);

    uintptr_t serialized = a.serialize(&ptr);
    Data* reserialized_struct = a.deserialize(serialized);

    std::cout << "Unsigned int value of serialized Data structures:";
    std::cout << serialized << std::endl<< std::endl;


    std::cout << "Reserialized Data structures:" << std::endl;
    printData("reserialized_struct", reserialized_struct);

    if (reserialized_struct == &ptr &&
        reserialized_struct->next == &ptr2) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }
    return 0;
}
