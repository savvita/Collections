#include <iostream>
#include"Collections.h"

using namespace Collections;

int main()
{
	try
	{
		size_t length = 10;
		SLinkedList<int> s;
		DLinkedList<char> s2;
		Stack<int> s3;
		Queue<int> s4;
		BinaryTree<int> s5;

		for (size_t i = 0; i < length; i++)
		{
			s.add(i);
			s2.add(char(97 + i));
			s3.push(-1 - i);
			s4.enqueue(-1 - i);
			s5.add(rand() % 100);
		}

		std::cout << "SLinked:\n";
		s.print();
		std::cout << "=============================\n";

		std::cout << "DLinked:\n";
		s2.print();
		std::cout << "=============================\n";

		std::cout << "Stack:\n";
		while (!s3.isEmpty())
			std::cout << s3.pop() << "\t";
		std::cout << "\n";
		std::cout << "=============================\n";

		std::cout << "Queue:\n";
		while (!s4.isEmpty())
			std::cout << s4.dequeue() << "\t";
		std::cout << "\n";
		std::cout << "=============================\n";

		std::cout << "BinaryTree:\n";

		s5.print();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
}
