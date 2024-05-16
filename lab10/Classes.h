#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;

class IndexOutOfBounds :public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este in afara domeniului!";
    }
};

class ReachedCapacity :public exception
{
    virtual const char* what() const throw()
    {
        return "Adaugarea unui alt element ar depasi capacitatea array-ului!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class Array;

template<class T>
class ArrayIterator
{
private:
    int Current;
    Array<T>* CurrentPtr;
public:
    ArrayIterator()
    {
        Current = 0;
        CurrentPtr = nullptr;
    }
    ArrayIterator& operator ++ ()
    {
        if (CurrentPtr == nullptr || Current >= CurrentPtr->GetSize())
        {
            throw IndexOutOfBounds();
        }
        Current++;
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        if (CurrentPtr == nullptr || Current <= 0)
        {
            throw IndexOutOfBounds();
        }
        Current--;
        return *this;
    }
    bool operator=(const ArrayIterator<T>& other)
    {
        Current = other.Current;
        CurrentPtr = other.CurrentPtr;
        return true;
    }
    bool operator!=(const ArrayIterator<T>& other)
    {
        return(Current == other.Current && CurrentPtr == other.CurrentPtr);
    }
    T* GetElement()
    {
        if (CurrentPtr == nullptr || Current < 0 || Current >= CurrentPtr->GetSize())
        {
            throw IndexOutOfBounds();
        }
        return &(*CurrentPtr)[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        Capacity = 0;
        Size = 0;
    }
    ~Array() // destructor
    {
        Capacity = 0;
        Size = 0;
        delete[] List;
        List = nullptr;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        Size = 0;
        Capacity = capacity;
        List = new T * [Capacity];
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
        {
            List[i] = new T(*(otherArray.List[i]));
        }
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        if (index < 0 || index >= Size)
        {
            throw IndexOutOfBounds();
        }
        return *List[index];
    }
    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        if (Size >= Capacity)
        {
            throw ReachedCapacity();
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (Size >= Capacity)
        {
            throw ReachedCapacity();
        }
        if (index<0 || index>Size)
        {
            throw IndexOutOfBounds();
        }
        for (int i = Size; i > index; i--)
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (Size+otherArray.Size >= Capacity)
        {
            throw ReachedCapacity();
        }
        if (index<0 || index>Size)
        {
            throw IndexOutOfBounds();
        }
        for (int i = Size - 1; i >= index; i--)
        {
            List[i + otherArray.Size] = List[i];
        }
        Size += otherArray.Size;
        for (int i = index; i < Size; i++)
        {
            List[i] = new T(*(otherArray.List[i - index]));
        }
        return *this;
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index<0 || index>Size)
        {
            throw IndexOutOfBounds();
        }
        for (int i = index; i < Size; i++)
        {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
        {
            List[i] = newT(*(otherArray.List[i]));
        }
        return true;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        sort(List, List + Size, [](const T* a, const T* b)
        {
            return *a < *b;
        });
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        sort(List, List + Size, compare);
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        sort(List, List + Size, [&](T* a, T* b)
        {
            return comparator->CompareElements(a, b) < 0;
        });
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int st = 0;
        int dr = Size - 1;
        while (st <= dr)
        {
            int m = st + (dr - st) / 2;
            if (*List[m] == elem)
            {
                return m;
            }
            if (*List[m] < elem)
            {
                st = m + 1;
            }
            else
            {
                dr = m - 1;
            }
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind binary search si o functie de comparatie
    {
        int st = 0;
        int dr = Size - 1;
        while (st <= dr)
        {
            int m = st + (dr - st) / 2;
            if (compare(*List[m],elem)==0)
            {
                return m;
            }
            if (compare(*List[m], elem) < 0)
            {
                st = m + 1;
            }
            else
            {
                dr = m - 1;
            }
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int st = 0;
        int dr = Size - 1;
        while (st <= dr)
        {
            int m = st + (dr - st) / 2;
            if (comparator->CompareElements(List[m], &elem) == 0)
            {
                return m;
            }
            if (comparator->CompareElements(List[m], &elem) < 0)
            {
                st = m + 1;
            }
            else
            {
                dr = m - 1;
            }
        }
        return -1;
    }

    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0; i < Size; i++)
        {
            if (*List[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
        {
            if (compare(*List[i], elem)==0)
            {
                return i;
            }
        }
        return -1;
    }
    int Find(const T& elem, Compare* comparator) //  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++)
        {
            if (comparator->CompareElements(List[i], &elem)==0)
            {
                return i;
            }
        }
        return -1;
    }

    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> it;
        it.Curent = 0;
        it.CurentPtr = List[0];
        return it;
    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> it;
        it.Curent = 0;
        it.CurentPtr = List[Size-1];
        return it;
    }
};
