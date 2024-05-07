#pragma once
#include <iostream>
#define NMAX 50 //ca sa schimb valoarea fara sa caut in cod

template <typename K, typename V>
struct element
{
	K key;
	V value;
	int index;
};

template <class K, class V>
class Map
{
private:
	element<K, V>* map;
	int number_of_elements;
public:
	Map()
	{
		map = new element<K, V>[NMAX];
		number_of_elements = 0;
	}
	~Map()
	{
		number_of_elements = 0;
		delete[] map;
	}

	element<K,V>* begin()
	{
		return &map[0];
	}

	element<K,V>* end()
	{
		return &map[number_of_elements];
	}

	V& operator[](const K& key)
	{
		int i;
		for (i = 0; i < number_of_elements; i++)
		{
			if (map[i].key == key)
			{
				return map[i].value;
			}
		}

		map[number_of_elements].key = key;
		map[number_of_elements].index = number_of_elements;
		map[number_of_elements].value = V();
		number_of_elements++;
		return map[number_of_elements-1].value;
	}

	void Set(const K& key, const V& value)
	{
		(*this)[key] = value;
	}

	bool Get(const K& key, V value)
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			if (map[i].key == key)
			{
				(*this)[key] = value;
				return true;
			}
		}
		return false;
	}

	int Count()
	{
		return number_of_elements;
	}

	void Clear()
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			map[i].value = V();
		}
	}

	bool Delete(const K& key)
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			if (map[i].key == key)
			{
				for (int j = i; j < number_of_elements-1; j++)
				{
					map[j] = map[j + 1];
				}
				number_of_elements--;
				return true;
			}
		}
		return false;
	}

	bool Exist(const K key, const V value) const
	{
		for (int i = 0; i < number_of_elements; i++)
		{
			if (map[i].key == key && map[i].value == value)
			{
				return true;
			}
		}
		return false;
	}

	//eu am considerat ca verific daca mapa pentru care apelez functia e inclusa in cea data ca parametru 
	bool Includes(const Map<K, V>& map) const
	{
		if (number_of_elements < map.number_of_elements)
		{
			return false;
		}
		for (int i = 0; i < map.number_of_elements; i++)
		{
			if (this->Exist(map.map[i].key, map.map[i].value) == false)
			{
				return false;
			}
		}
		return true;
	}
};