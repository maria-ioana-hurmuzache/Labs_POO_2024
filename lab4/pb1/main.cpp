// problema1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"

int main()
{
    int v[7] = { 1, 2, 6, 5, 9, 14, 202 };
    char string[] = "12,13,14,15";
    Sort a1(10, 3, 15);
    Sort a2(v, 7);
    Sort a3(4, 3, 15, 14, 17);
    Sort a4(string);
    Sort a5;
    a1.Print();
    std::cout<<a1.GetElementFromIndex(15)<<'\n';
    std::cout<<a1.GetElementFromIndex(3)<<'\n';
    a1.BubbleSort();
    a1.Print();
    a2.Print();
    std::cout << a2.GetElementsCount() << '\n';
    a2.InsertSort();
    a2.Print();
    a3.Print();
    a3.InsertSort();
    a3.Print();
    a4.Print();
    a5.Print();
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
