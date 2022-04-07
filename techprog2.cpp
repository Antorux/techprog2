#include "arolf.h"
#include "queue.h"
#include <iostream>
using namespace std;



void DateInizilization(Date& obj)
{
	int year, month, day;
	cout << "Введите год" << endl; cin >> year;
	cout << "Введите месяц" << endl; cin >> month;
	cout << "Введите день" << endl; cin >> day;
	obj.Inizilization(year, month, day);

}

void ShowDate(Date& obj)
{
	obj.GetDate();
}

int ChoiceDate()
{
	int choice;
	cout << "С какой датой вы хотите работать" << endl;
	cin >> choice; return choice;
}

void UnaryPrefixOperations(Date& obj)
{
	cout << "Какой операцией вы хотите воспользоваться?" << endl; int choice;
	cout << "1 - Префиксный инкремент (++item) (Увеличить одно из значний даты на 1)" << endl;
	cout << "2 - Префиксный дикремент (--item) (Уменшить одно из значний даты на 1)" << endl;
	cin >> choice;
	system("cls");
	int a;
	switch (choice)
	{
	case 1: cout << "Какое значение даты увеличить?" << endl;
		cout << "1 - Год" << endl << "2 - Месяц" << endl << "3 - День" << endl; cin >> a; obj.ChoiceAction(a);

		++obj;

		system("cls"); break;
	case 2: cout << "Какое значение даты уменьшить?" << endl;
		cout << "1 - Год" << endl << "2 - Месяц" << endl << "3 - День" << endl; cin >> a; obj.ChoiceAction(a);

		--obj;

		system("cls"); break;
	}



}


void UnaryPostfixOperator(Date& obj)
{
	cout << "Какой операцией вы хотите воспользоваться?" << endl; int choice;
	cout << "1 - Постфиксный инкремент (item++) (Увеличить одно из значний даты на заданное число)" << endl;
	cout << "2 - Постфиксный дикремент (item--) (Уменшить одно из значний даты на заданное число)" << endl;
	cin >> choice;
	system("cls");
	int a;
	//cout << "На сколько вы хотите изменить выбранное значение даты?" << endl; int number; cin >> number;
	switch (choice)
	{
	case 1: //cout << "Какое значение даты увеличить?" << endl;
		//cout << "1 - Год" << endl << "2 - Месяц" << endl << "3 - День" << endl; cin >> a; obj.ChoiceAction(a);

		obj++;

		system("cls"); break;

	case 2: //cout << "Какое значение даты уменьшить?" << endl;
		//cout << "1 - Год" << endl << "2 - Месяц" << endl << "3 - День" << endl; cin >> a; obj.ChoiceAction(a);

		obj--;

		system("cls"); break;
	}

}




void FirstTask(Date* DateList)
{
	int work = 1;
	int MenuSection;
	int DateListSection = 0;
	while (work)
	{
		cout << "<---------- Главное Меню ---------->" << endl;
		cout << "1: Ввод значений даты" << endl;
		cout << "2: Показать дату" << endl;
		cout << "3: Унарные префиксные  операции" << endl;
		cout << "4: Унарные постфиксные операции" << endl;
		cout << "5: Выбрать дату для работы" << endl;
		cout << "6: Перейти к выбору задания" << endl;
		cout << "7: Выход из программы" << endl;
		cin >> MenuSection;
		system("cls");
		switch (MenuSection)
		{
		case 1:DateInizilization(DateList[DateListSection]); break;
		case 2:ShowDate(DateList[DateListSection]); break;
		case 3:UnaryPrefixOperations(DateList[DateListSection]); break;
		case 4:UnaryPostfixOperator(DateList[DateListSection]); break;
		case 5:DateListSection = ChoiceDate();
		case 6:work = 0; break;
		case 7:exit(0); break;


		}
	}

}


void AdditionAndSubtractionOperations(List& obj)
{
	int choice; int del; int add;

	cout << "Какой операцией хотите воспользоваться? " << endl << "1 - Добавление элемента(перегрузка + )" << endl << "2 - Извлечение элемента(перегрузка -)" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1: cout << "Введите значние добавляемого элемента" << endl; cin >> add;

		obj + add;

		break;
	case 2: if (obj.IsEmptyCheck(obj))
	{
		cout << "Введите значение извлекаемого элемента" << endl;
		cin >> del;

		obj - del;
	}
		  else cout << "Очередь пуста" << endl;

		break;
	}


}
void EqualityAndInequalityOperations(List* QueList, int current)
{
	int selection; int a; int b;

	cout << "Какой операцией хотите воспользоваться? " << endl << "1 - Проверка на равенство(перегрузка == )" << endl << "2 - Проверка на неравенство(перегрузка != )" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1: cout << "C какой очередью сравнить текущую?" << endl; cin >> a;

		QueList[current] == QueList[a];
		system("pause");
		break;
	case 2: cout << "C какой очередью сравнить текущую?" << endl; cin >> b;

		QueList[current] != QueList[b];
		system("pause");


		break;
	}


}

int EnterChoice()
{
	cout << "С какой очередью хотите работать?" << endl;
	int choice = 0;
	cin >> choice;
	system("cls");
	return choice;
}
void ShowQueue(List& obj)
{
	if (obj.IsEmptyCheck(obj)) {

		cout << obj;
	}
	else cout << "Очередь пуста" << endl;
}

void AddingItem(List& obj)
{

	cout << "Введите элемент для добавления в очередь" << endl;
	cin >> obj;
	system("cls");

}

void MultiplicationOperations(List& obj)
{
	if (obj.IsEmptyCheck(obj)) {
		int multi;
		cout << "На какое число умножить все элементы очереди?" << endl; cin >> multi;

		obj* multi;
	}
	else cout << "Очередь пуста" << endl;
}

void EqualityOperations(List* QueList, int current)
{
	cout << "Какую очередь приравнять к текущей?" << endl; int select; cin >> select;

	QueList[select] = QueList[current];

}




void SecondTask(List* QueList)
{
	int work = 1;
	int MenuSection;
	int current = 0;

	while (work)
	{

		cout << "<---------- Главное Меню ---------->" << endl;
		cout << "1: Перегрузка операторов + и - " << endl;
		cout << "2: Перегрузка операторов сравнения на равенства и неравенства" << endl;
		cout << "3: Вывод очереди на экран (перегрузка оператора вывода)" << endl;
		cout << "4: Добавление элемента в очередь(перегрузка оператора ввода)" << endl;
		cout << "5: Перегрузка оператора умножения" << endl;
		cout << "6: Оператор равенства" << endl;
		cout << "7: Выбор очереди для работы" << endl;
		cout << "8: Возврат к выбору задания" << endl;
		cout << "9: Выход из программы" << endl;
		cin >> MenuSection;
		system("cls");
		switch (MenuSection)
		{
		case 1:AdditionAndSubtractionOperations(QueList[current]);
			break;
		case 2:EqualityAndInequalityOperations(QueList, current);
			break;
		case 3:ShowQueue(QueList[current]);
			break;
		case 4:AddingItem(QueList[current]);
			break;
		case 5:MultiplicationOperations(QueList[current]);
			break;
		case 6:EqualityOperations(QueList, current);
			break;
		case 7:current = EnterChoice();
			break;
		case 8: work = 0; break;
		case 9:exit(0); break;


		}
	}

}


int main()
{
	setlocale(LC_ALL, "Rus");
	int work = 1; int que = 1;
	Date* DateList = new Date[5];
	List* QueList = NULL;
	while (work) {
		cout << "Выберите с каким заданием вы будете работать?" << endl << "1 - Унарные операции" << endl << "2 - Бинарные операции" << endl;
		cout << "3 - Выход из программы" << endl;
		//cout << "Со сколькими датами вы хотите работать?" << endl; int n = 10; cin >> n;
		int choice; cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			FirstTask(DateList);
			break;
		case 2: cout << "Сколько очередей хотите использовать?" << endl; cin >> que; QueList = new List[que];
			SecondTask(QueList);
			break;

		case 3: exit(0);


		default:cout << "error";
			break;
		}

	}



}
