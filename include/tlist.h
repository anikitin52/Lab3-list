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
        Node(T data, Node* next) : data(data), next(next) {}
	};
	Node* first;

public:
	
    TList() {
        first = nullptr;
    }

    TList(int n) {
        if (n < 0) {
            throw "Error!";
        }
        if (n == 0) {
            first = nullptr;
            return;
        }
        first = new Node(T(), nullptr);
        Node* current = first;
        for (int i = 1; i < n; i++) {
            Node* tmp = new Node(T(), nullptr);
            current->next = tmp;
            current = current->next;
        }
    }

    TList(const TList& other) {
        if (!other.first) {
            first = nullptr;
            return;
        }
        first = new Node(other.first->data, nullptr);
        Node* current = first;
        Node* ocurrent = other.first->next;
        while (ocurrent) {
            current->next = new Node(ocurrent->data, nullptr);
            current = current->next;
            ocurrent = ocurrent->next;
        }
    }

    ~TList() {
        while (first) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    TList(int n, T dflt) {
        if (n < 0) {
            throw "Error!";
        }
        if (n == 0) {
            first = nullptr;
            return;
        }
        first = new Node(dflt, nullptr);
        Node* current = first;
        for (int i = 1; i < n; i++) {
            Node* tmp = new Node(dflt, nullptr);
            current->next = tmp;
            current = current->next;
        }
    }

    TList& operator=(const TList& l) {
        if (this == &l) {
            return *this;
        }
        while (first) {
            Node* second = first->next;
            delete first;
            first = second;
        }
        if (!l.first) {
            first = nullptr;
            return *this;
        }
        first = new Node(l.first->data, nullptr);
        Node* current = first;
        Node* ocurrent = l.first->next;
        while (ocurrent) {
            current->next = new Node(ocurrent->data, nullptr);
            current = current->next;
            ocurrent = ocurrent->next;
        }
        return *this;
    }
	

    T& operator[] (int index) {
        if (index < 0) {
            throw "Error!";
        }
        Node* current = first;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                throw "Error!";
            }
            current = current->next;
        }
        if (current == nullptr) {
            throw "Error!";
        }
        return current->data;
    }

    Node* insert(T value, Node* prev) {
        if (prev == nullptr) {
            throw "Error!";
        }
        Node* tmp = new Node(value, prev->next);
        prev->next = tmp;
        return tmp;
    }
    
    Node* erase(Node* prev) {
        if (prev == nullptr) {
            throw "Error!";
        }
        Node* tmp = prev->next;
        if (!prev->next) throw "Error!";
        prev->next = tmp->next;
        delete tmp;
        return prev->next;
        
    }
    
    Node* find(T value) {
        Node* current = first;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    size_t size() {
        int size = 0;
        Node* current = first;
        while (current) {
            size += 1;
            current = current->next;
        }
        return size;
    }

    void print();
	
    class iterator {
        Node* cur;
        explicit iterator(Node* node) : cur(node) {}
    public:
        iterator& operator++() {
            cur = cur->next;
            return *this;
        }
        iterator operator++(int) {
            iterator copy = *this;
            cur = cur->next;
            return copy;
        }
        T* operator->() {
            return &(cur->data);
        }
        friend bool operator!=(const iterator it1, const iterator it2) {
            return it1.cur != it2.cur;
        }
    };

    iterator begin() {
        return iterator(first);
    }
    iterator end() {
        return iterator(nullptr);
    }
};



#endif
