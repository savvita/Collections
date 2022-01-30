#pragma once
#include"Node.h"

namespace Collections
{
	template <typename T>
	class SLinkedList
	{
	private:
		using Node = SLinked::Node<T>;
		Node* head;
		Node* tail;

	public:
		SLinkedList();

		T operator[](unsigned int index) const;
		T& operator[](unsigned int index);

		void add(const T& value);

		void remove(const T& value);

		void print(std::ostream& out = std::cout) const;

		~SLinkedList();
	};

	template<typename T>
	inline SLinkedList<T>::SLinkedList() :head{ NULL }, tail{ NULL }
	{
	}

	template<typename T>
	inline T SLinkedList<T>::operator[](unsigned int index) const
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
	inline T& SLinkedList<T>::operator[](unsigned int index)
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
	inline void SLinkedList<T>::add(const T& value)
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
	inline void SLinkedList<T>::remove(const T& value)
	{
		if (this->head == NULL)
			throw std::exception("List is empty\n");

		if (this->head->value == value)
		{
			Node* curr = this->head;
			this->head = this->head->next;
			delete curr;
		}

		else
		{
			Node* curr = this->head;
			Node* prev = nullptr;

			while (curr->next != NULL && curr->next->value != value)
			{
				prev = curr;
				curr = curr->next;
			}

			if (curr->next == NULL && curr->value != value)
			{
				throw std::exception("No such element at the list\n");
			}

			if (curr->next == NULL)
			{
				if (prev == nullptr)
				{
					this->head = NULL;
					this->tail = NULL;

					delete curr;
				}

				else
				{
					prev->next = NULL;
					this->tail = prev;

					delete curr;
				}
			}

			else
			{
				Node* tmp = curr->next;
				curr->next = curr->next->next;
				delete tmp;
			}
		}
	}

	template<typename T>
	inline void SLinkedList<T>::print(std::ostream& out) const
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
	inline SLinkedList<T>::~SLinkedList()
	{
		while (this->head != NULL)
		{
			Node* tmp = this->head;
			this->head = this->head->next;
			delete tmp;
		}
	}

}