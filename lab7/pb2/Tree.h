#pragma once
#include <iostream>

template <typename T>
int compara(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
	{
		return -1;
	}
	else if (firstValue > secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
int compara2(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
	{
		return 1;
	}
	else if (firstValue > secondValue)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//specializarea functiei pentru cazul cu char *
template <>
int compara <const char*>(const char* firstValue, const char* secondValue)
{
	return strcmp(firstValue, secondValue);
}

template <typename T>
struct Node
{
	T value;
	Node<T>** children;//nu aloc direct nr de copii (cum ar fi fost daca era Node<T>* children[100]), ci fac un pointer la pointer
	unsigned int nrChildren;
};

//Node<int> nod;
//Node<float> nod2;

template<class T>
class Tree
{
public:
	Node<T>* root;
	unsigned int maxChildrenPerNode;
	//constructor
	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}
	//adaugare nod
	void add_node(Node<T>* parinte, T value)
	{
		if (parinte == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T>*[maxChildrenPerNode] {};//cu acoladele am initializat tot vectorul cu nullptr
		}
		else
		{
			parinte->children[parinte->nrChildren] = new Node<T>;
			parinte->children[parinte->nrChildren]->value=value;
			parinte->children[parinte->nrChildren]->nrChildren=0;
			parinte->children[parinte->nrChildren]->children = new Node<T>*[maxChildrenPerNode] {};
			parinte->nrChildren++;
		}
	}

	Node<T>* get_node(Node<T>* parinte, unsigned int index=0)
	{
		if (parinte == nullptr)
		{
			return root;
		}

		else
		{
			return parinte->children[index];
		}
	}

	void delete_node(Node<T>** nod, Node<T>*parent)
	{
		if (*nod == nullptr)
		{
			return;
		}

		Node<T>* node = *nod;
		unsigned int i;
		for (i = 0; i < maxChildrenPerNode; i++)
		{
			delete_node(&(node->children[i]), node);
		}

		delete[] node->children;
		delete node;
		*nod = nullptr;
		parent->nrChildren--;
	}

	unsigned int count(Node<T>* nod)
	{
		unsigned int i;
		if (nod == nullptr)
			nod = root;
		unsigned int counter=nod->nrChildren;
		for (i = 0; i < maxChildrenPerNode; i++)
		{
			if (nod->children[i] != nullptr)
				counter += this->count(nod->children[i]);
		}
		return counter;
	}

	Node<T>* find(T parameter, int(*comparatie)(T, T), Node<T>* nod=nullptr)
	{
		unsigned int i;
		Node<T>* gasit=nullptr;
		if (nod == nullptr)
		{
			nod = root;
		}
		if (comparatie(nod->value, parameter) == 0)
		{
			return nod;
		}
		else
		{
			for(i=0; i<maxChildrenPerNode && gasit==nullptr; i++)
				if (nod->children[i] != nullptr)
				{
					gasit=this->find(parameter, comparatie, nod->children[i]);
				}
			if (gasit != nullptr)
			{
				return gasit;
			}
			else
			{
				return nullptr;
			}
		}

	}

	void insert(Node<T>* parinte, unsigned int index, T value)
	{
		if (index >= maxChildrenPerNode)
			return;
		else
		{
			parinte->children[index] = new Node<T>;
			parinte->children[index]->value = value;
			parinte->children[index]->nrChildren = 0;
			parinte->children[index]->children = new Node<T>*[maxChildrenPerNode] {};
			parinte->nrChildren++;
		}
	}

	void sort(Node<T>* parinte, int (*comparatie)(T,T))
	{
		unsigned int i, j;
		for(i=0; i<parinte->nrChildren-1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					T aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}

	//print
	void printNodes(Node<T>* parinte)
	{
		unsigned int i;
		for (i = 0; i < maxChildrenPerNode; i++)
			if (parinte->children[i] != nullptr)
			{
				std::cout << parinte->children[i]->value << " {";
				this->printNodes(parinte->children[i]);
				std::cout << "} ";
			}
	}
};

template<>
class Tree <char*>
{
public:
	Node<char*>* root;
	unsigned int maxChildrenPerNode;
	//constructor
	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}
	//adaugare nod
	void add_node(Node<char*>* parent, const char* value)
	{
		if (parent == nullptr)
		{
			root = new Node<char*>;
			root->value = new char [100] {};
			strcpy(root->value, value);
			root->nrChildren = 0;
			root->children = new Node<char*>*[maxChildrenPerNode] {};//cu acoladele am initializat tot vectorul cu nullptr
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<char*>;
			parent->children[parent->nrChildren]->value = new char[100] {};
			strcpy(parent->children[parent->nrChildren]->value, value);
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<char*>*[maxChildrenPerNode] {};
			parent->nrChildren++;
		}
	}

	void insert(Node<char*>* parinte, unsigned int index, const char* value)
	{
		if (index >= maxChildrenPerNode)
			return;
		else
		{
			parinte->children[index] = new Node<char*>;
			parinte->children[index]->value = new char[100] {};
			strcpy(parinte->children[index]->value, value);
			parinte->children[index]->nrChildren = 0;
			parinte->children[index]->children = new Node<char*>*[maxChildrenPerNode] {};
			parinte->nrChildren++;
		}
	}

	Node<char*>* get_node(Node<char*>* parinte, unsigned int index = 0)
	{
		if (parinte == nullptr)
		{
			return root;
		}

		else
		{
			return parinte->children[index];
		}
	}

	void delete_node(Node<char*>** nod, Node<char*>* parent)
	{
		if (*nod == nullptr)
		{
			return;
		}

		Node<char*>* node = *nod;
		unsigned int i;
		for (i = 0; i < maxChildrenPerNode; i++)
		{
			delete_node(&(node->children[i]), node);
		}

		delete[] node->children;
		delete node;
		*nod = nullptr;
		parent->nrChildren--;
	}

	unsigned int count(Node<char*>* nod)
	{
		unsigned int i;
		if (nod == nullptr)
			nod = root;
		unsigned int counter = nod->nrChildren;
		for (i = 0; i < maxChildrenPerNode; i++)
		{
			if (nod->children[i] != nullptr)
				counter += this->count(nod->children[i]);
		}
		return counter;
	}

	Node<char*>* find(const char* parameter, int(*comparatie)(const char*, const char*), Node<char*>* nod = nullptr)
	{
		unsigned int i;
		Node<char*>* gasit = nullptr;
		if (nod == nullptr)
		{
			nod = root;
		}
		if (comparatie(nod->value, parameter) == 0)
		{
			return nod;
		}
		else
		{
			for (i = 0; i < maxChildrenPerNode && gasit == nullptr; i++)
				if (nod->children[i] != nullptr)
				{
					gasit = this->find(parameter, comparatie, nod->children[i]);
				}
			if (gasit != nullptr)
			{
				return gasit;
			}
			else
			{
				return nullptr;
			}
		}

	}

	void sort(Node<char*>* parinte, int (*comparatie)(const char*, const char*))
	{
		unsigned int i, j;
		for (i = 0; i < parinte->nrChildren - 1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					char* aux;
					strcpy(aux, parinte->children[i]->value);
					strcpy(parinte->children[i]->value, parinte->children[j]->value);
					strcpy(parinte->children[j]->value, aux);
				}
			}
	}
	//print
	void printNodes(Node<char*>* parinte)
	{
		unsigned int i;
		for (i = 0; i < maxChildrenPerNode; i++)
			if (parinte->children[i] != nullptr)
			{
				std::cout << parinte->children[i]->value << " {";
				this->printNodes(parinte->children[i]);
				std::cout << "} ";
			}
	}
};