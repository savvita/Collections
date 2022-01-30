#pragma once
#include"Node.h"

namespace Collections
{
	template <typename T>
	class Queue
	{
	private:
		using Node = SLinked::Node<T>;
		Node* head;
		Node* tail;

	public:
		Queue();

		void enqueue(const T& value);
		const T& pick() const;
		T dequeue();

		bool isEmpty() const;

		~Queue();
	};

	template<typename T>
	inline Queue<T>::Queue() :head{ NULL }, tail{ NULL }
	{
	}

	template<typename T>
	inline void Queue<T>::enqueue(const T& value)
	{
		if (this->head == NULL)
		{
			this->head = new(std::nothrow) Node(value);

			if (this->head == nullptr)
				throw std::exception("Cannot allocate the memory\n");

			this->tail = this->head;
		}

		else
		{
			Node* newNode = new(std::nothrow)Node(value);

			if (newNode == nullptr)
				throw std::exception("Cannot allocate the memory\n");

			this->tail->next = newNode;
			this->tail = this->tail->next;
		}
	}

	template<typename T>
	inline const T& Queue<T>::pick() const
	{
		if (this->head == NULL)
			throw std::exception("Queue is empty\n");

		return this->head->value;
	}

	template<typename T>
	inline T Queue<T>::dequeue()
	{
		if (this->head == NULL)
			throw std::exception("Queue is empty\n");

		T res = this->head->value;

		Node* tmp = this->head;

		this->head = this->head->next;

		delete tmp;

		return res;
	}

	template<typename T>
	inline bool Queue<T>::isEmpty() const
	{
		return (this->head == NULL);
	}

	template<typename T>
	inline Queue<T>::~Queue()
	{
		while (this->head != NULL)
		{
			Node* tmp = this->head;
			this->head = this->head->next;
			delete tmp;
		}
	}
}
