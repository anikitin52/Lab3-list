// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
// Лабораторная работа "Список"

#ifndef __TList_H__
#define __TList_H__

#include <iostream>

using namespace std;

template<typename T>
class TList
{
	struct Node
	{
		T data;
		Node* next;
	};
	Node* first;

public:
	TList() {
		first(nullptr);
	}

	TList(int n) {
		if (n == 0) return;
		first = new Node(T(), nullptr);
		Node* current = first;
		for (int i = 0; i < n; i++) {
			Node* tmp = new Node(T(); nullptr);
			current->next = tmp;
			current = current->next;
		}
	}

	TList(const List& l) {
		if (!l.first) {

		}
		this->first = new Node(other.first->data, nullptr);
		Node* current = first, ocurrent{};
		while (ocurrent->next)
		{
			current->next = new Node(ocurrent->next->data, nullptr);
		}
		current = current->next;
		ocurrent = ocurrent->next;
	}

	~TList() {
		while (first) {
			Node* second = first->next;
			delete first;
			first = second;
		}
	}

	TList(int n, T dflt = T());
	
	TList(const List& l);

	TList& operator=(const tList& l);
	T& operator[] (int index);

	Node* insert(T value, Node* prev) {
		Node* tmp = new Node;
		tmp->next = prev->next;
		tmp->data = value;
		prev->next = tmp;
		return tmp;
	}

	Node* insert_front(T value) {
		Node* first_first = new Node;
		first_first->next = first;
		first_fisrst->data = value;
		first = first_first;
		return first;
	}

	Node* erase(Node* prev) {
		Node* tmp = prev->next;
		if (!prev->next) throw 1;
		prev->next = tmp->next;
		delete tmp;
		return prev_next;
	}

	Node* erase_front() {
		Node* tmp = first;
		first = tmp->next;
		delete tmp;
		return first;
	}

	Node* find(T value);

	size_t size() {
		int size = 0;
		Node* current = first;
		while (current) {
			size += 1;
			current = current->next;
		}
	}
};



#endif
