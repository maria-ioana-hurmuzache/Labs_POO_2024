#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef int nrMare[1006];

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int suma = 0;
	va_list termeni;
	va_start(termeni, count);
	for (int i = 0; i < count; i++)
		suma += va_arg(termeni, int);
	va_end(termeni);
	return suma;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return nullptr;
	nrMare x = {}, y = {};
	x[0] = strlen(a);
	for (int i = 1; i <= x[0]; i++)
		x[i] = (*(a + strlen(a) - i))-'0';
	y[0] = strlen(b);
	for (int i = 1; i <= y[0]; i++)
		y[i] = (*(b + strlen(b) - i))-'0';
	int length = x[0];
	x[0] = length;
	int t = 0;
	for (int i = 1; i <= x[0]; i++)
	{
		x[i] = x[i] + y[i] + t;
		t = x[i] / 10;
		x[i] = x[i] % 10;
		cout << t << '\n';
	}
	if (t != 0)
	{
		x[0]++;
		x[x[0]] = t;
	}
	char* rez = new char[x[0]];
	char* aux = rez;
	for (int i = 0; i < x[0]; i++)
	{
		(*aux) = x[x[0] - i] + '0';
		aux++;
	}
	(*aux) = '\0';
	return rez;
}