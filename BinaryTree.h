#pragma once
#include"Node.h"

namespace Collections
{
	template <typename T>
	class BinaryTree
	{
	private:
		using Node = DLinked::Node<T>;

		Node* root;

		void _add(Node** root, const T& value);
		void _remove(Node** root, const T& value);
		void _print(Node* root, std::ostream& out = std::cout) const;
		void _deleteTree(Node* root);
		const T& _findMin(Node* root) const;
		const T* _find(Node* root, const T& value) const;

	public:
		BinaryTree();

		void add(const T& value);

		void remove(const T& value);

		void print(std::ostream& out = std::cout) const;

		const T* find(const T& value) const;

		~BinaryTree();
	};

	template<typename T>
	inline void BinaryTree<T>::_add(Node** root, const T& value)
	{
		if (*root == NULL)
			*root = new Node(value);

		else
		{
			if (value < (*root)->value)
			{
				this->_add(&(*root)->prev, value);
			}
			else
			{
				this->_add(&(*root)->next, value);
			}
		}
	}

	template<typename T>
	inline void BinaryTree<T>::_remove(Node** root, const T& value)
	{
		if (*root == NULL)
			return;

		if (value < (*root)->value)
			this->_remove(&(*root)->prev, value);

		else if (value > (*root)->value)
			this->_remove(&(*root)->next, value);

		else
		{
			if ((*root)->prev == NULL)
			{
				Node* tmp = *root;
				(*root) = (*root)->next;
				delete tmp;
			}

			else if ((*root)->next == NULL)
			{
				Node* tmp = *root;
				(*root) = (*root)->prev;
				delete tmp;
			}

			else
			{
				T min = this->_findMin((*root)->next);
				(*root)->value = min;
				this->_remove(&(*root)->next, min);
			}
		}
	}

	template<typename T>
	inline void BinaryTree<T>::_print(Node* root, std::ostream& out) const
	{
		if (root == NULL)
			return;

		this->_print(root->prev, out);
		out << root->value << "\n";
		this->_print(root->next, out);
	}

	template<typename T>
	inline void BinaryTree<T>::_deleteTree(Node* root)
	{
		if (root == NULL)
			return;

		if (root->prev != NULL)
			this->_deleteTree(root->prev);

		if (root->next != NULL)
			this->_deleteTree(root->next);
	}

	template<typename T>
	inline const T& BinaryTree<T>::_findMin(Node* root) const
	{
		if (root == NULL)
			return NULL;

		if (root->prev == NULL)
			return root->value;

		return this->_findMin(root->prev);
	}

	template<typename T>
	inline const T* BinaryTree<T>::_find(Node* root, const T& value) const
	{
		if (root == NULL)
			return nullptr;

		if (root->value == value)
			return &root->value;

		if (value < root->value)
			return this->_find(root->prev, value);
		else
			return this->_find(root->next, value);
	}

	template<typename T>
	inline BinaryTree<T>::BinaryTree() :root{ NULL }
	{
	}

	template<typename T>
	inline void BinaryTree<T>::add(const T& value)
	{
		this->_add(&this->root, value);
	}

	template<typename T>
	inline void BinaryTree<T>::remove(const T& value)
	{
		this->_remove(&this->root, value);
	}

	template<typename T>
	inline void BinaryTree<T>::print(std::ostream& out) const
	{
		this->_print(this->root, out);
	}

	template<typename T>
	inline const T* BinaryTree<T>::find(const T& value) const
	{
		return this->_find(this->root, value);
	}

	template<typename T>
	inline BinaryTree<T>::~BinaryTree()
	{
		this->_deleteTree(this->root);
	}
}