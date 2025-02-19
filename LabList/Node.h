#pragma once

template <typename T>
class Node
{
public:
	T data;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(T _data) {
		data = _data;
	}

};

