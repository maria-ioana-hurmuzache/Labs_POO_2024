#pragma once
class Number
{
	char* sir;
	int nrBase;
	unsigned int sirLen;
public:
	//constructor
	Number(const char* value, int base); // where base is between 2 and 16
	//copy constructor
	Number(const Number& otherNumber);
	//move constructor
	Number(Number&& otherNumber) noexcept;
	//destructor
	~Number();
	unsigned int GetBase10Number() const;
	
	//operator index
	char& operator [](int index);

	//operatori de comparatie
	bool operator <(const Number& otherNumber);
	bool operator >(const Number& otherNumber);
	bool operator >=(const Number& otherNumber);
	bool operator <=(const Number& otherNumber);
	bool operator ==(const Number& otherNumber);
	bool operator !=(const Number& otherNumber);

	//operatori de asignare
	Number& operator=(const Number& otherNumber);
	Number& operator=(Number&& otherNumber) noexcept;

	//operatori de adunare si scadere
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	//operator --
	void operator--();
	void operator--(int);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
