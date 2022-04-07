#include "arolf.h"
#include <iostream>
using namespace std;


Date::Date() : day(0), month(0), year(0) {}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}


Date& Date::operator++()
{
	switch (choice)
	{
	case 1:this->year++;  break;
	case 2:this->month++; break;
	case 3:this->day++;   break;
	default: break;
	}



	return *this;
}

Date& Date::operator--()
{
	switch (choice)
	{
	case 1:this->year--;  break;
	case 2:this->month--; break;
	case 3:this->day--;   break;
	default: break;
	}

	return *this;
}

void Date::ChoiceAction(int value)
{
	choice = value;
}



void Date::Inizilization(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;

}

void Date::GetDate()
{
	cout << "���:" << this->year << "  �����:" << this->month << "  ����:" << this->day << endl;
}



Date operator++(Date& obj, const int)
{
	int v; cout << "����� ������� ���� ��������� 1 - ����; 2 - �����; 3 - ���;" << endl; cin >> v;
	cout << "�� ������� ���������?" << endl; int number; cin >> number;
	switch (v)
	{
	case 1:obj.day += number;  break;
	case 2:obj.month += number; break;
	case 3:obj.year += number;  break;
	default: break;
	}

	return obj;
}

Date& Date::operator--(const int)
{
	int v; cout << "�� ��������� 1 ���� 2 ����� 3 ���" << endl; cin >> v;
	cout << "�� ������� ���������?" << endl; int number; cin >> number;
	switch (v)
	{
	case 1:day -= number;  break;
	case 2:month -= number; break;
	case 3:year -= number;  break;
	default: break;
	}

	return *this;
}

