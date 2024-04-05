// lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Number.h"

int main()
{
    Number n1("10110010", 2); //178
    Number n2("734", 8); //476
    Number n3("FF", 16); //255
    Number n4("255", 10);

    printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
    
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }

    n1.Print();
    n2.Print();

    n1 = (n2 + n3 - n1) + n1;
    n1.SwitchBase(10);
    n1.Print();

    std::cout << (n1<n2) << ' ' << (n2 > n1) << ' ' << (n4 >= n2) << ' ' << (n3 <= n2) << ' ' << (n3 == n4) << ' ' << (n3!=n4) << '\n';

    n4 = n4 + n3;
    n4.Print();
    n2 = n1 - n2;
    n2.Print();

    --n4;
    n4.Print();
    n4--;
    n4.Print();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
