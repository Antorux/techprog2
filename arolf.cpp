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
	int number = 1;
	switch (choice)
	{
	case 1:this->year++;  break;
	case 2:year += number / 12;
		month += number % 12;
		if (month > 12)
		{
			month -= 12; year++;
		}
		 break;
	case 3:while (number > 0)
	{
		if (day + number <= 31)
		{
			day += number;
			number = 0;
		}
		else
		{
			number -= (31 - day + 1);
			day = 1;
			if (++month > 12)
			{
				month = 1;
				year++;
			}
		}

	};   break;
	default: break;
	}



	return *this;
}

Date& Date::operator--()
{
	int number = 1;
	switch (choice)
	{
	case 1:this->year--;  break;
	case 2:year -= number / 12;
		month -= number % 12;
		if (month < 1)
		{
			month += 12; year--;
		}; break;
	case 3:
		while (number > 0)
		{
			if (number < day)
			{
				day -= number;
				number = 0;
			}
			else
			{
				if (--month < 1)
				{
					month = 12;
					year--;
				}
				number -= day;
				day = 31;
			}
		};   break;
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
	cout << "Год:" << this->year << "  Месяц:" << this->month << "  День:" << this->day << endl;
}



Date operator++(Date& obj, const int)
{
	const int dayOst = 31 - obj.day;
	const int monthOst = 12 - obj.month;
	int v; cout << "Какое значние даты увеличить 1 - день; 2 - месяц; 3 - год;" << endl; cin >> v;
	cout << "На сколько увеличить?" << endl; int numberDay; int numberMonth; int numberYear;
	switch (v)
	{
	case 1:cin >> numberDay;
		while (numberDay > 0)
		{
			if (obj.day + numberDay <= 31)
			{
				obj.day += numberDay;
				numberDay = 0;
			}
			else
			{
				numberDay -= (31 - obj.day + 1);
				obj.day = 1;
				if (++obj.month > 12)
				{
					obj.month = 1;
					obj.year++;
				}
			}

		}
		break;
	case 2:cin >> numberMonth;
		obj.year += numberMonth / 12;
		obj.month += numberMonth % 12;
		if (obj.month > 12)
		{
			obj.month -= 12; obj.year++;
		}
		break;
	case 3:cin >> numberYear;
		obj.year += numberYear;  break;
	default: break;
	}
	return obj;
}

Date& Date::operator--(const int)
{
	int tempDay = day; int tempMonth = month;
	int v; cout << "Что уменьшить: 1 день 2 месяц 3 год" << endl; cin >> v;
	cout << "На сколько уменьшить?" << endl; int number; int numberDay; int numberMonth;
	switch (v)
	{
	case 1:cin >> numberDay;
		while (numberDay > 0)
		{
			if (numberDay < day)
			{
				day -= numberDay;
				numberDay = 0;
			}
			else
			{
				if (--month < 1)
				{
					month = 12;
					year--;
				}
				numberDay -= day;
				day = 31;
			}
		}
		break;
	case 2:cin >> numberMonth;
		year -= numberMonth / 12;
		month -= numberMonth % 12;
		if (month < 1)
		{
			month += 12; year--;
		}
		break;
	case 3:cin >> number;
		year -= number; break;
	default: break;
	}

	return *this;
}



