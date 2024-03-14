// pb2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas c(25, 25);
    c.DrawLine(1, 1, 3, 1, 'a');
    c.Clear();
    c.SetPoint(5, 1, 'q');
    c.DrawRect(0, 1, 2, 3, 'e');
    c.FillRect(0, 1, 2, 3, 'h');
    c.DrawCircle(12, 11, 10, 'w');
    c.FillCircle(12, 11, 10, '*');
    c.Print();
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
