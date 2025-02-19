#pragma once
#include"Node.h"
#include<iostream>

template <typename T>

class List
{
private:
	unsigned long int size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	Node<T>* getNode(unsigned long int id) {
		if (id >= size) {
			throw "id bigger then size";
		}
		Node<T>* cur = nullptr;
		if (id / size <= 0.5) { //Оптимизация
			cur = head;
			for (unsigned long int i = 0; i < id; i++) {
				cur = cur->next;
			}
		}
		else {
			cur = tail;
			for (unsigned long int i = size - 1; i > id; i--) {
				cur = tail->prev;
			}
		}
		return cur;
	}


public:
	//Добавить в конец
	void push(T _data) {
		Node<T>* element = new Node<T>(_data);
		if (head == nullptr) {
			head = element;
			tail = element;
		}
		else {
			tail->next = element;
			element->prev = tail;
			tail = element;
		}
		size++;
		return;
	}

	//Добавить в начало
	void pushFirst(T _data) {
		if (head == nullptr) {
			return push(_data);
		}
		else {
			Node<T>* temp = new Node<T>(_data);
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
		size++;
		return;
	}

	//Добавить между элементами
	void insert(T _data, unsigned long int id) {
		Node<T>* temp = new Node<T>(_data);
		Node<T>* cur = getNode(id);
		Node<T>* prev = cur->prev;
		prev->next = temp;
		temp->prev = prev;
		temp->next = cur;
		cur->prev = temp;
		size++;
		return;
	}

	//Удалить первый элемент списка
	void delFirst() {
		if (head == nullptr)
			throw "List is empty";

		Node<T>* cur = head;
		Node<T>* next = head->next;
		head = next;
		head->prev = nullptr;
		delete cur;
		size--;
		return;
	}

	//Удалить последний элемент списка
	void delLast() {
		if (tail == nullptr)
			throw "List is empty";

		Node<T>* cur = tail;
		Node<T>* prev = tail->prev;
		prev->next = nullptr;
		tail = prev;
		delete cur;
		size--;
		return;
	}

	//Удалить элемент под номером
	void pop(unsigned long int id) {
		if (id >= size)
			throw "id bigger then size";

		if (id == 0)
			return delFirst();
		else if (id == size-1)
			return delLast();
		else {
			Node<T>* cur = getNode(id);
			Node<T>* next = cur->next;
			Node<T>* prev = cur->prev;
			prev->next = next;
			next->prev = prev;
			delete cur;
			size--;
		}
		return;
	}

	//Получить длину списка
	int getSize() {
		return size;
	}

	//Получить данные элемента
	T getData(unsigned long int id) {
		return getNode(id)->data;
	}

	void print() {
		if (head == nullptr)
			throw "List is empty";

		for (unsigned long int i = 0; i < size; i++) {
			std::cout << i  << ": " << getData(i) << std::endl;
		}
	}

	//Деструктор должен удалить все элементы списка
	~List() {
		while (head != nullptr){
		Node<T>* temp = head->next;
		delete head;
		head = temp;
	}
	return;
	}

	Node<T>* getHeadNode() {
		return getNode(0);
	}

	Node<T>* getTailNode() {
		return getNode(size - 1);
	}

	void clear() {
		head = nullptr;
		tail = nullptr;
	}

	void addList(List<T>* list) {
		Node<T>* cur = getTailNode();
		Node<T>* next = list->getHeadNode();
		Node<T>* newTail = list->getTailNode();
		cur->next = next;
		tail = newTail;
		list->clear();
		size += list->getSize();
	}
};

