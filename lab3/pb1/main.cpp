#include <iostream>
#include <cstdarg>
#include <cstring>
#include "Math.h"

using namespace std;

int main()
{
	cout << Math::Add(4, 2) << '\n';
	cout << Math::Add(4.2, 2.7) << '\n';
	cout << Math::Add(4, 2, 7) << '\n';
	cout << Math::Add(4.2, 2.7, 7.5) << '\n';
	cout << Math::Mul(4, 2) << '\n';
	cout << Math::Mul(4.2, 2.7) << '\n';
	cout << Math::Mul(4, 2, 7) << '\n';
	cout << Math::Mul(4.2, 2.7, 7.5) << '\n';
	cout << Math::Add(5, 1, 2, 3, 4, 5) << '\n';
	cout << Math::Add("pisica ", "neagra");
	return 0;
}