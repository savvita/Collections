#pragma once
#include<iostream>

namespace Collections
{
	namespace SLinked
	{
		template <typename T>
		struct Node
		{
			T value;
			Node* next;

			Node(const T& value)
			{
				this->value = value;
				this->next = NULL;
			}

			Node(const T& value, Node* next)
			{
				this->value = value;
				this->next = next;
			}
		};
	}

	namespace DLinked
	{
		template <typename T>
		struct Node
		{
			T value;
			Node* next;
			Node* prev;

			Node(const T& value)
			{
				this->value = value;
				this->prev = NULL;
				this->next = NULL;
			}

			Node(const T& value, Node* prev, Node* next)
			{
				this->value = value;
				this->prev = prev;
				this->next = next;
			}
		};
	}
}
