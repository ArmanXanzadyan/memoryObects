#include <iostream>
#include <vector>
#include <iterator>


int
memoryOfTypes(const std::vector<size_t>& ob)
{
    size_t sum = 0;
    size_t pointerMemory = sizeof(size_t);
    size_t maxMemory = 0;
    for (std::vector<size_t>::const_iterator it = ob.begin(); it != ob.end(); ++it) {
        assert((*it % 2 == 0 || *it == 1) && *it >= 1 && *it <= 8);
        while (true) {
            if (pointerMemory == 0) pointerMemory = 8;
            if (pointerMemory % *it == 0) {
                if (*it > maxMemory) maxMemory = *it;
                sum += *it;
                pointerMemory -= *it;
                break;
            }
            ++sum;
            --pointerMemory;
        }
    }

    while (sum % maxMemory != 0) {
        ++sum;
    }

    return sum;
}

struct A
{
    int a;
    int b;
    int c;
    double d;
    int16_t e;
    char f;
    float g;
    char h;
    double a1;
    int k2;
    char a11;
    char a12;
};

int
main()
{
    A ob1;
    std::vector<size_t> ob = {4, 4, 4, 8, 2, 1, 4, 1, 8, 4, 1, 1};
    std::cout << "Memory is " << memoryOfTypes(ob) << " for my function\n"
              << "Memory is " << sizeof(ob1) << " with sizeof\n";
    return 0;
}
