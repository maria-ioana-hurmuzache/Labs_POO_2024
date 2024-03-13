#include "Math.h"
#include <cstdarg>
#include <cstring>

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
	int length = strlen(a) + strlen(b) + 1;
	char* ab = new char[length];
	strcpy_s(ab, length, a);
	strcat_s(ab, length, b);
	return ab;
}