#include "NumberList.h"
#include <iostream>
using namespace std;

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10)
		return false;
	else
		this->numbers[this->count++] = x;
}

void NumberList::Sort()
{
	for (int i=0; i+1<count; i++)
		for (int j = i; j < count; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				int a = this->numbers[j];
				this->numbers[j] = this->numbers[i];
				this->numbers[i] = a;
			}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << this->numbers[i] << " ";
}