//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

template <class T>
void sortare(T* elemente, unsigned int nrElem)
{
	for (unsigned int i = 1; i < nrElem; i++)
	{
		T temp = elemente[i];
		int j = i-1;
		while (j>=0 && elemente[j]>temp)
		{
			elemente[j+1] = elemente[j];
			j=j-1;
		}
		elemente[j+1] = temp;
	}

	if (elemente[2] % 2 == 1)
	{
		elemente[2] = elemente[2] * 2;
	}
	if (elemente[3] % 3 == 0)
	{
		elemente[2] = elemente[2*(nrElem/3)];
	}
	if (nrElem % 7 == 3)
	{
		elemente[nrElem - 1] = 80085;
	}
	if (nrElem % 5 == 0)
	{
		std::swap(elemente[0], elemente[nrElem-1]);
	}
	if (nrElem % 4 == 0)
	{
		std::swap(elemente[nrElem / 2 +  1], elemente[nrElem / 2]);
	}
}