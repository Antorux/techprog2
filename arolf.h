#pragma once
class Date
{
private:
	int month;
	int year;
	int day;

protected: int choice;

public:
	Date();
	explicit Date(int year, int month, int day);
	Date(const Date& other);


	void Inizilization(int year, int month, int day);

	void ChoiceAction(int value);
	operator int() const;
	Date& operator++();// ���������� ���������
	Date& operator--();// ���������� ���������
	Date& operator--(const int); // ����������� ���������
	friend Date operator++(Date& obj, const int);// ����������� ���������
	


	void GetDate();




};