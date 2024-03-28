#include "Number.h"
#include <cstring>
#include <iostream>

Number::Number(const char* value, int base)
{
	sir = new char[100]; /*{} <- s-ar inintializa cu 0*/ //se foloseste ca sa alocam memorie in mod dinamic, adica pe heap
	//sir = (char*)/* castare de la void* la char* */malloc(100*sizeof(char)) <- alta modalitate
	strcpy(sir, value);
	sirLen = strlen(sir);
	nrBase = base;
}

Number::Number(const Number& otherNumber)
{
	sir = new char[100];
	strcpy(sir, otherNumber.sir);
	nrBase = otherNumber.nrBase;
	sirLen = otherNumber.sirLen;
}

Number::Number(Number&& otherNumber) noexcept
{
	sir = new char[100];
	strcpy(sir, otherNumber.sir);
	nrBase = otherNumber.nrBase;
	sirLen = otherNumber.sirLen;
	otherNumber.sir = nullptr;
}

Number& Number::operator=(const Number& otherNumber)
{
	strcpy(sir, otherNumber.sir);
	nrBase = otherNumber.nrBase;
	sirLen = otherNumber.sirLen;
	return *this;
}

Number& Number::operator=(Number&& otherNumber) noexcept
{
	delete[] sir;
	sir = new char[100];
	strcpy(sir, otherNumber.sir);
	nrBase = otherNumber.nrBase;
	sirLen = otherNumber.sirLen;
	otherNumber.sir = nullptr;
	otherNumber.nrBase = 0;
	otherNumber.sirLen = 0;
	return *this;
}

Number::~Number()
{
	delete[] sir; //pt ca sterg intregul array folosesc []
	sir = nullptr; //de bun simt :))
}

unsigned int Number::GetBase10Number() const
{
	unsigned int result = 0, power = 1;
	int i;
	for (i = sirLen - 1; i >= 0; i--)
	{
		if (sir[i] >= '0' && sir[i] <= '9')
		{
			result = result + (sir[i] - '0') * power;
			power = power * nrBase;
		}
		else
		{
			result = result + (sir[i] - 'A' + 10) * power;
			power = power * nrBase;
		}
	}
	return result;
}

char& Number::operator [](int index)
{
	return sir[index];
}

bool Number::operator <(const Number& otherNumber)
{
	return GetBase10Number()<otherNumber.GetBase10Number();
}

bool Number::operator >(const Number& otherNumber)
{
	return GetBase10Number() > otherNumber.GetBase10Number();
}

bool Number::operator >=(const Number& otherNumber)
{
	return GetBase10Number() >= otherNumber.GetBase10Number();
}

bool Number::operator <=(const Number& otherNumber)
{
	return GetBase10Number() <= otherNumber.GetBase10Number();
}

bool Number::operator ==(const Number& otherNumber)
{
	return GetBase10Number() == otherNumber.GetBase10Number();
}

bool Number::operator !=(const Number& otherNumber)
{
	return GetBase10Number() != otherNumber.GetBase10Number();
}
/*bool operator .... functia friend nu mai trebuie sa fie in clasa si punem friend doar la clasa*/

Number operator+(const Number& n1, const Number& n2)
{
	int newBase=0;
	if (n1.nrBase > n2.nrBase)
		newBase = n1.nrBase;
	else
		newBase = n2.nrBase;
	int s = n1.GetBase10Number() + n2.GetBase10Number();
	char* suma = new char[100];
	int sumaLen = 0;
	while (s > 0)
	{
		int cf = s % 10;
		char* cifra = new char[1];
		if (cf < 10)
			(*cifra) = '0' + cf;
		else
			(*cifra) = 'A' + cf - 10;
		suma[sumaLen++] = (*cifra);
		s = s / 10;
		delete[] cifra;
		cifra = nullptr;
	}
	suma[sumaLen] = '\0';
	for (int i = 0; i < sumaLen / 2; i++)
	{
		char aux = suma[i];
		suma[i] = suma[sumaLen - i - 1];
		suma[sumaLen - i - 1] = aux;
	}
	Number n(suma, 10);
	n.SwitchBase(newBase);
	return n;
}

Number operator-(const Number& n1, const Number& n2)
{
	int newBase=0;
	if (n1.nrBase > n2.nrBase)
		newBase = n1.nrBase;
	else
		newBase = n2.nrBase;
	int d;
	if (n1.GetBase10Number() > n2.GetBase10Number())
		d = n1.GetBase10Number() - n2.GetBase10Number();
	else
		d = n2.GetBase10Number() - n1.GetBase10Number();
	char* dif = new char[100];
	int difLen = 0;
	while (d > 0)
	{
		int cf = d % 10;
		char* cifra = new char[1];
		if (cf < 10)
			(*cifra) = '0' + cf;
		else
			(*cifra) = 'A' + cf - 10;
		dif[difLen++] = (*cifra);
		d = d / 10;
		delete[] cifra;
		cifra = nullptr;
	}
	dif[difLen] = '\0';
	for (int i = 0; i < difLen / 2; i++)
	{
		char aux = dif[i];
		dif[i] = dif[difLen - i - 1];
		dif[difLen - i - 1] = aux;
	}
	Number n(dif, 10);
	n.SwitchBase(newBase);
	return n;
}

void Number::operator--()
{
	for (int i = 0; i < sirLen; i++)
		sir[i] = sir[i + 1];
	sirLen--;
}

void Number::operator--(int)
{
	sir[sirLen - 1] = sir[sirLen];
	sirLen--;
}

void Number::Print()
{
	std::cout << "The number " << sir << " as it is written in base " << nrBase << '\n';
}

void Number::SwitchBase(int newBase)
{
	int nr10 = GetBase10Number();
	nrBase = newBase;
	memset(sir, 0, sizeof(sir));
	sirLen = 0;
	while (nr10 != 0)
	{
		int cf = nr10 % nrBase;
		char* cifra = new char[1];
		if (cf < 10)
			(*cifra) = '0' + cf;
		else
			(*cifra) = 'A' + cf - 10;
		sir[sirLen++] = (*cifra);
		nr10 = nr10 / nrBase;
		delete[] cifra;
		cifra = nullptr;
	}
	sir[sirLen] = '\0';
	for (int i = 0; i < sirLen / 2; i++)
	{
		char aux = sir[i];
		sir[i] = sir[sirLen - i - 1];
		sir[sirLen - i - 1] = aux;
	}
}

int  Number::GetDigitsCount()
{
	return strlen(sir);
}

int  Number::GetBase()
{
	return nrBase;
}