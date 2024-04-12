//observatie: pe cod se vor observa comentarii care sunt un fel de notite de laborator, sper sa nu deranjeze:))
#include <iostream>
#include "Tree.h"

int main()
{
	Tree<int> copac(20);
	copac.add_node(nullptr, 1);
	copac.add_node(copac.root, 2);
	copac.add_node(copac.root, 3);
	copac.add_node(copac.root, 4);
	copac.add_node(copac.root, 5);

	copac.sort(copac.root, compara2);
	copac.printNodes(copac.root);
	std::cout << '\n';

	std::cout << copac.get_node(copac.root)->value << '\n';
	std::cout << copac.get_node(copac.root, 1)->value << '\n';
	std::cout << copac.get_node(nullptr)->value << '\n';
	
	copac.insert(copac.root->children[1], 1, 6);
	copac.printNodes(copac.root);
	std::cout << '\n';
	
	std::cout << copac.count(nullptr) << '\n';

	std::cout << copac.find(3,compara) << '\n';
	std::cout << copac.get_node(copac.root, 2) << '\n'; //verificare ca primesc adresa corecta

	copac.delete_node(&(copac.root->children[1]), copac.root);
	copac.printNodes(copac.root);
	std::cout << '\n';


	Tree<char*> copac2(20);
	copac2.add_node(nullptr, "1");
	copac2.add_node(copac2.root, "2");
	copac2.add_node(copac2.root, "3");
	copac2.add_node(copac2.root, "4");
	copac2.add_node(copac2.root, "5");
	copac2.printNodes(copac2.root);
	std::cout << '\n';

	std::cout << copac2.get_node(copac2.root)->value << '\n';
	std::cout << copac2.get_node(copac2.root, 1)->value << '\n';
	std::cout << copac2.get_node(nullptr)->value << '\n';

	copac2.insert(copac2.root->children[1], 1, "6");
	copac2.printNodes(copac2.root);
	std::cout << '\n';

	std::cout << copac2.count(nullptr) << '\n';

	std::cout << copac2.find("3", compara) << '\n';
	std::cout << copac2.get_node(copac2.root, 2) << '\n'; //verificare ca primesc adresa corecta

	copac2.delete_node(&(copac2.root->children[1]), copac2.root);
	copac2.printNodes(copac2.root);
	std::cout << '\n';
}