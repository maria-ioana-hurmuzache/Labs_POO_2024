#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <cstring>

Sort::Sort(int nrElemente, int minim, int maxim) : elemente(nullptr), size(nrElemente)
{
	this->elemente = new int[this->size];
	srand(time(NULL));
	for (int i = 0; i < this->size; i++)
		this->elemente[i] = rand() % (maxim - minim + 1) + minim;
}

Sort::Sort(int* v, int nrElemente) : elemente(nullptr), size(nrElemente)
{
	this->elemente = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->elemente[i] = v[i];
}

Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);
	this->size = count;
	this->elemente = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		int nr = va_arg(args, int);
		this->elemente[i] = nr;
	}
}

Sort::Sort(char* string)
{
	this->size = 0;
	char* string2=new char[strlen(string)+1];
	strcpy(string2, string);
	char* p = strtok(string,",");
	while (p != NULL)
	{
		this->size++;
		p = strtok(NULL, ",");
	}
	this->elemente = new int[this->size];
	p = strtok(string2, ",");
	int i = 0;
	while (p != NULL)
	{
		this->elemente[i] = atoi(p);
		i++;
		p = strtok(NULL, ",");
	}
	delete[] string2;
}

Sort::Sort() : elemente(new int[4] {1, 2, 7 ,8})
{
	this->size = 4;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->size; i++)
	{
		int temp = this->elemente[i];
		int j = i - 1;
		while (j >= 0 && (this->elemente[j] > temp))
		{
			this->elemente[j + 1] = this->elemente[j];
			j--;
		}
		this->elemente[j + 1] = temp;
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int ultim = this->size-1;
	while (ultim > 0)
	{
		int n1 = ultim - 1;
		ultim = 0;
		for (int i = 0; i <= n1; i++)
		{
			if (this->elemente[i] > this->elemente[i + 1])
			{
				int aux = this->elemente[i];
				this->elemente[i] = this->elemente[i + 1];
				this->elemente[i + 1] = aux;
				ultim = i;
			}
		}
	}
}

int Sort::Partitionare(int p, int q)
{
	int x = this->elemente[p];
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if (this->elemente[i] <= x)
			i++;
		if (this->elemente[j] >= x)
			j--;
		if (i<j && this->elemente[i]>x && x > this->elemente[j])
		{
			int aux = this->elemente[i];
			this->elemente[i] = this->elemente[j];
			this->elemente[j] = aux;
			i++;
			j--;
		}
	}
	int k = i - 1;
	this->elemente[p] = this->elemente[k];
	this->elemente[k] = x;
	return k;
}

void Sort::recursieQuickSort(int p, int q)
{
	if (p<q)
	{
		int k = this->Partitionare(p, q);
		this->recursieQuickSort(p, (k - 1));
		this->recursieQuickSort((k + 1), q);
	}
}

void Sort::QuickSort(bool ascendent)
{
	this->recursieQuickSort(0, (this->size - 1));
}

void Sort::Print()
{
	for (int i = 0; i < this->size; i++)
		std::cout << this->elemente[i] << ' ';
	std::cout<<'\n';
}

int  Sort::GetElementsCount()
{
	return this->size;
}

int  Sort::GetElementFromIndex(int index)
{
	if (index<this->size)
		return this->elemente[index];
	std::cout << "index invalid ";
	return -1;
}