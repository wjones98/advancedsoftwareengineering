#pragma once
#include <string>
#include <iostream>
#include <functional>
namespace Containers
{
	template <class K, class I>
	class Dictionary
	{
	public:
		using Key = K;
		using Item = I;

		//Default Constructor
		Dictionary() = default;

		//Default Destructor
		~Dictionary();

		//copy constructor
		Dictionary(const Dictionary&);

		//Copy assignment operator
		Dictionary& operator=(const Dictionary&);

		//move constructor
		Dictionary(Dictionary&&);

		//Move assignment operator
		Dictionary& operator=(Dictionary&&);

		//Higher Order remove if function
		void removeIf(std::function<bool(Key)>);

		bool insert(Key, Item);
		Item* lookup(Key);
		bool remove(Key);

	private:
		struct Node {
			Key key;
			Item item;
			Node* nextNode = nullptr;
			Node(Key k, Item i);
		};
		Node* root = nullptr;

		static bool isPresent(Node*&);

		static bool insertRec(Key, Item, Node*&);
		static Item* lookupRec(Key, Node*);
		static bool removeRec(Key, Node*&);
		static void removeIfRec(std::function<bool(Key)>, Node*&);

		Node* deepCopy(Node*);
		static Node* deepCopyRec(Node* dictN, Node*& n);

		void deepDelete(Node*&);
		static void deepDeleteRec(Node*&);

	};
	
	//Default Destructor
	template <class Key, class Item>
	Dictionary<Key, Item>::~Dictionary() {
		deepDelete(this->root);
	}

	//copy constructor
	template <class Key, class Item>
	Dictionary<Key,Item>::Dictionary(const Dictionary& dict) {
		this->root = deepCopy(dict.root);
	}

	//Copy assignment operator
	template <class Key, class Item>
	Dictionary<Key, Item>& Dictionary<Key, Item>::operator=(const Dictionary& dict) {
		if (this != &dict) {
			deepDelete(this->root);
			this->root = deepCopy(dict.root);
		}
		return *this;
	}

	//deep copy
	template <class Key, class Item>
	typename Dictionary<Key, Item>::Node* Dictionary<Key, Item>::deepCopy(Node* dictN) {
		return deepCopyRec(dictN, this->root);
	}

	//deep copy worker
	template <class Key, class Item>
	typename Dictionary<Key, Item>::Node* Dictionary<Key, Item>::deepCopyRec(Node* dictN, Node*& n) {
		if (isPresent(dictN)) {
			n = new Node(dictN->key, dictN->item);
			deepCopyRec(dictN->nextNode, n->nextNode);
		}
		return n;
	}

	//deep delete
	template <class Key, class Item>
	void Dictionary<Key, Item>::deepDelete(Node*& n) {
		deepDeleteRec(n);
	}

	//deep delete worker
	template <class Key, class Item>
	void Dictionary<Key, Item>::deepDeleteRec(Node*& n) {
		if (isPresent(n)) {
			deepDeleteRec(n->nextNode);
			delete n;
			n = nullptr;
		}
	}

	//move constructor
	template <class Key, class Item>
	Dictionary<Key, Item>::Dictionary(Dictionary&& dict) {
		this->root = dict.root;
		dict.root = nullptr;
	}

	//Move assignment operator
	template <class Key, class Item>
	Dictionary<Key, Item>& Dictionary<Key, Item>::operator=(Dictionary&& dict) {
		if (this != &dict) {
			deepDelete(this->root);
			this->root = dict.root;
			dict.root = nullptr;
		}
		return *this;
	}

	//default Node constructor
	template <class Key, class Item>
	Dictionary<Key, Item>::Node::Node(Key k, Item i) {
		this->key = k;
		this->item = i;
	}

	//Determines whether a node is absent or present
	template <class Key, class Item>
	bool Dictionary<Key, Item>::isPresent(Node*& n) {
		return (n != nullptr);
	}


	//insert 
	template <class Key, class Item>
	bool Dictionary<Key, Item>::insert(Key k, Item i) {
		return insertRec(k, i, root);
	}

	//insert worker
	template <class Key, class Item>
	bool Dictionary<Key, Item>::insertRec(Key k, Item i, Node * &n) {
		if (isPresent(n)) {
			if (k == n->key) {
				n->item = i;
				return false;
			}
		}
		else {
			n = new Node(k, i);
			return true;
		}
		return insertRec(k, i, n->nextNode);
	}

	//lookup
	template <class Key, class Item>
	typename Dictionary<Key, Item>::Item* Dictionary<Key, Item>::lookup(Key k) {
		return lookupRec(k, this->root);
	}

	//lookup worker
	template <class Key, class Item>
	typename Dictionary<Key, Item>::Item* Dictionary<Key, Item>::lookupRec(Key k, Node * n) {
		if (isPresent(n)) {
			if (k == n->key) {
				return &n->item;
			}
			else {
				return lookupRec(k, n->nextNode);
			}
		}
		return nullptr;
	}

	//remove
	template <class Key, class Item>
	bool Dictionary<Key, Item>::remove(Key k) {
		return removeRec(k, this->root);
	}

	//remove worker
	template <class Key, class Item>
	bool Dictionary<Key, Item>::removeRec(Key k, Node*& n) {
		if (isPresent(n)) {
			if (k == n->key) {
				if (!isPresent(n->nextNode)) {
					delete n;
					n = nullptr;
				}
				else {
					Node* toDelete = n;
					n = n->nextNode;
					delete toDelete;
					toDelete = nullptr;
				}
				return true;
			}
			else {
				return removeRec(k, n->nextNode);
			}
		}
		return false;
	}


	template <class Key, class Item>
	void Dictionary<Key, Item>::removeIf(std::function<bool(Key)> p) {
		removeIfRec(p, this->root);
	}

	template<class Key, class Item>
	void Dictionary<Key, Item>::removeIfRec(std::function<bool(Key)> p, Node*& n) {
		if (isPresent(n)) {
			if (p(n->key)) {
				if (!isPresent(n->nextNode)) {
					delete n;
					n = nullptr;
				}
				else {
					Node* toDelete = n;
					n = n->nextNode;
					delete toDelete;
					toDelete = nullptr;
				}
			}
			removeIfRec(p, n->nextNode);
		}
	}
}