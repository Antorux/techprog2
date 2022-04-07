#include "queue.h"
#include <iostream>
#include <string>
using namespace std;

List::List()
{
	size = 0;
	head = nullptr;
}

List::~List()
{
	for (int i = 0; i != size; i++)
	{
		Node* temp = head;
		head = temp->pNext;
		delete temp;
	}
	cout << "Вызван деструктор";
}

List& List::operator=(const List& obj)
{
	int temp[100];
	Node* current = obj.head;
	for (int i = 0; i < obj.size; i++)
	{
		temp[i] = current->data;
		current = current->pNext;
	}

	for (int i = 0; i < obj.size; i++)
	{
		this->push(temp[i]);
	}
	return *this;
}


void List::operator==(const List& obj)
{
	Node* temp1 = this->head;
	Node* temp2 = obj.head;


	if (obj.size != this->size) { cout << "Очереди не равны по длине" << endl; }
	else
	{
		while (temp1 != nullptr) {
			if (temp1->data == temp2->data)
			{
				cout << to_string(temp1->data) << " == " << to_string(temp2->data) << " - true" << endl;
			}
			else
			{
				cout << to_string(temp1->data) << " == " << to_string(temp2->data) << " - false" << endl;
			}
			temp1 = temp1->pNext;
			temp2 = temp2->pNext;
		}
	}
}

void List::operator!=(const List& obj)
{
	Node* temp1 = this->head;
	Node* temp2 = obj.head;


	if (obj.size != this->size) { cout << "Очереди не равны по длине" << endl; }
	else
	{
		while (temp1 != nullptr) {
			if (temp1->data != temp2->data)
			{
				cout << to_string(temp1->data) << " != " << to_string(temp2->data) << " - true" << endl;
			}
			else
			{
				cout << to_string(temp1->data) << " != " << to_string(temp2->data) << " - false" << endl;
			}
			temp1 = temp1->pNext;
			temp2 = temp2->pNext;
		}
	}

}


void List::push(int index)
{
	if (head == nullptr)head = new Node(index);


	else {
		Node* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(index);
	}
}

bool List::IsEmptyCheck(List& obj)
{
	if (obj.size != 0) return true;
	else return false;
}

List& List::operator+(int num)
{
	if (this->head == nullptr)this->head = new Node(num);

	else {
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(num);


	}
	size++;
	return *this;

}



List& List::operator-(int number)
{
	int counter = 0;
	size--;
	if (this->head == nullptr) { return *this; }
	else if (number == head->data)
	{
		Node* temp = this->head;
		this->head = temp->pNext;
		delete temp;
		return *this;
	}
	Node* current = this->head;
	while (current != nullptr)
	{
		if (number == current->pNext->data)
		{
			if (current->pNext->pNext == nullptr)
			{
				delete current->pNext;
				current->pNext = nullptr;
			}
			else {
				Node* temp = current->pNext->pNext;
				delete current->pNext;
				current->pNext = temp;
			}
		}
		else if (counter <= size + 1)
		{
			cout << "Такой элемент не найден в очереди" << endl;
			break;
		}
		current = current->pNext;
		counter++;

	}
	return *this;
}


std::ostream& operator<<(std::ostream& out, const List& obj)
{
	Node* current = obj.head;
	out << "Элементы очереди:" << endl;
	while (current != nullptr)
	{
		out << current->data << " ";
		current = current->pNext;
	}
	out << endl;

	return out;
}

std::istream& operator>>(std::istream& in, List& obj)
{
	int index;
	if (obj.head == nullptr) { in >> index; obj.head = new Node(index); }


	else {
		Node* current = obj.head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		in >> index;
		current->pNext = new Node(index);
	}
	obj.size++;
	return in;

}

List& operator*(List& obj, int number3)
{
	Node* current = obj.head;
	int counter = 0;
	while (current->pNext != nullptr)
	{
		current->data *= number3;
		current = current->pNext;
		//counter++;
	}
	current->data *= number3;
	return obj;
}





