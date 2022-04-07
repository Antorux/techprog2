#pragma once
#include <iostream>
class Node
{
public:
	int data;
	Node* pNext;


	Node(int data, Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;

	}

};

class List
{

public:

	List();
	~List();

	friend std::ostream& operator<< (std::ostream& out, const List& obj);
	friend std::istream& operator>>(std::istream& in, List& obj);
	List& operator=(const List& obj);
	void operator==(const List& obj);
	void operator!=(const List& obj);
	List& operator+(int num);
	List& operator-(int number);
	friend List& operator*(List& obj, int number3);
	bool IsEmptyCheck(List& obj);
	void push(int index);


protected: int size;
private: Node* head;
};