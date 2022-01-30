#pragma once
#include"Node.h"

namespace Collections
{
	template <typename T>
	class DLinkedList
	{
	private:
		using Node = DLinked::Node<T>;
		Node* head;
		Node* tail;

	public:
		DLinkedList();

		T operator[](unsigned int index) const;
		T& operator[](unsigned int index);

		void add(const T& value);

		void remove(const T& value);

		void print(std::ostream& out = std::cout) const;

		~DLinkedList();
	};

	template<typename T>
	inline DLinkedList<T>::DLinkedList() :head{ NULL }, tail{ NULL }
	{
	}

	template<typename T>
	inline T DLinkedList<T>::operator[](unsigned int index) const
	{
		if (this->head == NULL)
			throw std::exception("List is empty\n");

		Node* curr = this->head;
		unsigned int count = 0;

		while (curr != NULL && count != index)
		{
			curr = curr->next;
		}

		if (curr == NULL)
			throw std::exception("Index out of range\n");

		return curr->value;
	}

	template<typename T>
	inline T& DLinkedList<T>::operator[](unsigned int index)
	{
		if (this->head == NULL)
			throw std::exception("List is empty\n");

		Node* curr = this->head;
		unsigned int count = 0;

		while (curr != NULL && count != index)
		{
			curr = curr->next;
			count++;
		}

		if (curr == NULL)
			throw std::exception("Index out of range\n");

		return curr->value;
	}

	template<typename T>
	inline void DLinkedList<T>::add(const T& value)
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
			Node* newNode = new(std::nothrow)Node(value, this->tail, NULL);

			if (newNode == nullptr)
				throw std::exception("Cannot allocate the memory\n");

			this->tail->next = newNode;
			this->tail = this->tail->next;
		}
	}

	template<typename T>
	inline void DLinkedList<T>::remove(const T& value)
	{
		if (this->head == NULL)
			throw std::exception("List is empty\n");

		Node* curr = this->head;

		while (curr != NULL && curr->value != value)
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			throw std::exception("No such element at the list\n");
		}

		if (curr == this->head)
		{
			this->head = this->head->next;

			if (this->head != NULL)
				this->head->prev = NULL;
			else
				this->tail = NULL;
			delete curr;
		}

		else
		{
			curr->prev->next = curr->next;

			if (curr->next != NULL)
			{
				curr->next->prev = curr->prev;
			}
			else
			{
				this->tail = curr->prev;
			}

			delete curr;
		}

	}

	template<typename T>
	inline void DLinkedList<T>::print(std::ostream& out) const
	{
		if (this->head == NULL)
			throw std::exception("List is empty\n");

		Node* curr = this->head;

		while (curr != NULL)
		{
			out << curr->value << "\n";
			curr = curr->next;
		}
	}

	template<typename T>
	inline DLinkedList<T>::~DLinkedList()
	{
		while (this->head != NULL)
		{
			Node* tmp = this->head;
			this->head = this->head->next;
			delete tmp;
		}
	}
}
