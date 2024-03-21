#pragma once
class Sort
{
private:
	int* elemente;
	int size;
	int Partitionare(int p, int q);
	void recursieQuickSort(int p, int q);
public:
	Sort(int nrElemente, int minim, int maxim);
	Sort(int* v, int nrElemente);
	Sort(int count, ...);
	Sort(char* string);
	Sort();
	void InsertSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};