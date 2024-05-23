#include "pch.h"

//am testat codul Cristianei Nistor

TEST(TesteSortare, Test1) {
	int a[] = { 2, 2, 7, 5, 6 };
	unsigned int nrElem = 5;
	sortare<int>(a, nrElem);

	for (int i = 0; i < nrElem; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';

	for (int i = 1; i < nrElem; i++)
	{
		ASSERT_LE(a[i - 1], a[i]);
	}
}

TEST(TesteSortare, Test2)
{
	int a[] = { 5, 2, 11, 9, 6, 8 };
	int maxim = 11;
	unsigned int nrElem = 6;
	sortare<int>(a, nrElem);
	for (int i = 0; i < nrElem; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
	ASSERT_EQ(a[0], maxim);
}

TEST(TesteSortare, Test3)
{
	int a[] = { 2,3,3};
	unsigned int nrElem = 3;
	sortare<int>(a, nrElem);
	for (int i = 0; i < nrElem; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < nrElem; i++)
	{
		ASSERT_EQ(a[i], 3);
	}
	//3-ul se modifica
}

TEST(TesteSortare, Test4)
{
	int a[] = { 6,6,6 };
	unsigned int nrElem = 3;
	sortare<int>(a, nrElem);
	for (int i = 0; i < nrElem; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < nrElem; i++)
	{
		ASSERT_EQ(a[i], 6);
	}
	//una dintre valori se modifica
}

TEST(TesteSortare, Test5)
{
	int a[] = { 5,3 };
	unsigned int nrElem = 2;
	sortare<int>(a, nrElem);
	for (int i = 0; i < nrElem; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < nrElem; i++)
	{
		ASSERT_GT(a[i], 5);
	}
}

TEST(TesteSortare, Test6)
{
	int a[] = { 15, 17, 19,121,9 };
	unsigned int nrElem = 5;
	sortare<int>(a, nrElem);
	for (int i = 0; i < nrElem; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < nrElem; i++)
	{
		ASSERT_EQ(a[i]%2, 1);
	}
}