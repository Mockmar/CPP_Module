
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    int*        mirror = new int[MAX_VAL];
    Array<int>  numbers(MAX_VAL);

    Array<int>*    test = new Array<int>();
    delete test;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int   value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int>  tmp = numbers;
        Array<int>  test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "All values are the same for Array<int> and int[]\n";
    {
        Array<int>    copy;

        copy = numbers;
        copy[0] = numbers[0] + 10;
        std::cout << "copy[0] = " << copy[0] << ", numbers[0] = " << numbers[0] << std::endl;
    }
    try {
        std::cout << "Trying to access index -2 of array:\n";
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "Trying to access index LEN of array:\n";
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}