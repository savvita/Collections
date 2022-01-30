#pragma once
#include"Node.h"

namespace Collections
{
	template <typename T>
	class Stack
	{
	private:
		using Node = SLinked::Node<T>;
		Node* tail;

	public:
		Stack();

		void push(const T& value);
		const T& pick() const;
		T pop();

		bool isEmpty() const;

		~Stack();
	};


	template<typename T>
	Stack<T>::Stack() :tail{ NULL }
	{
	}

	template<typename T>
	void Stack<T>::push(const T& value)
	{
		if (this->tail == NULL)
		{
			this->tail = new(std::nothrow) Node(value);

			if (this->tail == nullptr)
				throw std::exception("Cannot allocate the memory\n");
		}

		else
		{
			Node* newNode = new(std::nothrow)Node(value, this->tail);

			if (newNode == nullptr)
				throw std::exception("Cannot allocate the memory\n");

			this->tail = newNode;
		}
	}

	template<typename T>
	const T& Stack<T>::pick() const
	{
		if (this->tail == NULL)
			throw std::exception("Stack is empty\n");

		return this->tail->value;
	}

	template<typename T>
	T Stack<T>::pop()
	{
		if (this->tail == NULL)
			throw std::exception("Stack is empty\n");

		T res = this->tail->value;

		Node* tmp = this->tail;

		this->tail = this->tail->next;

		delete tmp;

		return res;
	}

	template<typename T>
	inline bool Stack<T>::isEmpty() const
	{
		return (this->tail == NULL);
	}

	template<typename T>
	Stack<T>::~Stack()
	{
		while (this->tail != NULL)
		{
			Node* tmp = this->tail;
			this->tail = this->tail->next;
			delete tmp;
		}
	}
}