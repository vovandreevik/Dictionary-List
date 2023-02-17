#include "DictionaryList.h"
#include <iostream>

int main() {
	DictionaryList test;
	test.insert(9);
	test.insert(1);
	test.insert(2);
	test.insert(1);
	test.insert(4);
	std::cout << "test\n";
	test.out();

	std::cout << ((test.search(1)) ? "1 find \n" : "1 not find \n");
	std::cout << ((test.search(10)) ? "10 find \n" : "10 not find \n");

	std::cout << "test after removing 2\n";
	test.remove(2);
	test.out();

	std::cout << "\ntest1 \n";

	DictionaryList test1;
	test1.merge(&test);

	test1.out();

	test1.insert(4);
	test1.insert(8);
	test1.insert(6);
	test1.insert(7);

	std::cout << "\ntest1 \n";
	test1.out();

	std::cout << "test";
	test.out();

	test.insert(9);
	test.insert(1);
	test.insert(3);
	test.insert(1);
	test.insert(4);


	std::cout << "\ntest after removing test 1\n";
	test.remove(&test1);
	test.out();

	return 0;
}