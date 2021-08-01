#include "IntArray.h"
#include <iostream>

void printIntArr(const IntArray& intArr)
{
    for(int idx = 0; idx < intArr.getLen(); ++idx)
    {
        std::cout << intArr[idx] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    IntArray intArr{5, 1};
    std::cout << "initialization: ";
    printIntArr(intArr);

    intArr.resize(3);
    printIntArr(intArr);

    intArr.insertAtBegining(3);
    printIntArr(intArr);

    intArr.insertAtEnd(4);
    printIntArr(intArr);

    intArr.remove(0);
    printIntArr(intArr);

    return 0;
}
