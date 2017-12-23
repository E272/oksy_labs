#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "Rabochiy.h"
#include "Sotrudnik.h"
#define CIN_FLUSH while(cin.peek()!=10)cin.ignore();cin.ignore()

using namespace std;

void MENU()
{

}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
/*	
	char *c = new char[100];
	char* str = nullptr;
	int qwe;
	int d;
	int day, month, year;
	int num;
	int pr = 0;
	Payment *emp = new Payment;

	ifstream intext("Text.txt", ios::in);
	if (!intext) {
		cerr << "Error: unable to write to Text.txt" << endl;
		exit(0);
	}

	ifstream inbin("Bin.bin", ios::binary);
	if (!inbin) {
		cerr << "Error: unable to write to Bin.bin" << endl;
		exit(0);
	}


	while (1 > 0)
	{
		cout << "Выберите способ создания объекта:" << endl;
		cout << "1. С помощью текстового файла" << endl;
		cout << "2. С помощью бинарного файла" << endl;
		cout << "3. Ввод с клавиатуры" << endl;
		cout << ">>";
		cin >> num;
		system("cls");

		switch (num)
		{
		case 1:
			intext >> *emp;
			break;

		case 2:
			emp->input(inbin);
			break;

		case 3:
			cin >> *emp;
			break;
		}

		if ((num == 1) || (num == 2) || (num == 3)) break;
	}

	intext.close();
	inbin.close();

	ofstream outtext("Text.txt", ios::out);
	if (!outtext) {
		cerr << "Error: unable to write to Text.txt" << endl;
		exit(0);
	}

	ofstream outbin("Bin.bin", ios::binary);
	if (!outbin) {
		cerr << "Error: unable to write to Bin.bin" << endl;
		exit(0);
	}

	int a;
	cout << "1 - Показать зарплату" << endl;
	cout << "2 - Показать отчисления в пенсионный фонд" << endl;
	cout << "3 - Показать подоходный налог" << endl;
	cout << "4 - Строковое представление" << endl;
	cout << "5 - Конструктор копирования" << endl;
	cout << "6 - Изменить оклад" << endl;
	cout << "7 - Изменить год поступления на работу" << endl;
	cout << "8 - Вывод на экран" << endl;
	cout << "9 - Запись в текстовый файл" << endl;
	cout << "10 - Запись в бинарный файл" << endl;
	cout << "0 - Выход" << endl;
	for (; 1 > 0;) {
		cout << endl << ">> ";
		cin >> a;
		switch (a) {
		case 1:
			cout << "Метод summa" << endl;
			cout << "Зарплата: " << emp->summa() << endl;
			cout << "Операция ()" << endl;
			qwe = emp->operator()();
			cout << qwe << endl;
			break;
		case 2: cout << "Общая сумма изъятых налогов за время работы составила: " << emp->otchisl() << " рублей" << endl; break;
		case 3: cout << "Отчисления в пенсионный фонд за время работы составили: " << emp->podoh() << " рублей" << endl; break;
		case 4: str = emp->show();  cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str; break;
		case 5: { Payment *emp1 = new Payment(*emp);  str = emp1->show(); cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str; delete emp1;  break; }
		case 6:
			cout << "1 - Увеличить оклад" << endl << "2 - Уменьшить оклад" << endl;
			cin >> d;
			if (d == 1) {
				cout << "На сколько хотите увеличить оклад?  ";
				cin >> qwe;
				*emp = *emp + qwe;
				cout << emp->operator()() << endl;
			}
			if (d == 2) {
				cout << "На сколько хотите уменьшить оклад?  ";
				cin >> qwe;
				*emp = *emp - qwe;
				cout << emp->operator()() << endl;
			}
			break;
		case 7:
			cout << "1 - Увеличить год поступления на работу" << endl << "2 - Уменьшить год поступления на работу" << endl;
			cin >> d;
			if (d == 1) {
				emp->operator++();
				cout << emp->show() << endl;
			}
			if (d == 2) {
				emp->operator--();
				cout << emp->show() << endl;
			}
			break;

		case 8:
			cout << *emp;
			break;

		case 9:
			outtext << *emp;
			break;

		case 10:
			emp->output(outbin);
			break;

		case 0: pr = -1; break; 
		default: 
			cout << "Такой операции нет" << endl;
			break;
		}
		if (pr == -1) break;
	}
	outtext << *emp;
	emp->output(outbin);
	delete emp;

	outtext.close();
	outbin.close();
*/

char* Fio = "Макаров Александр Владиленович";
int okl = 50000;
int dop = 25000;
int payo = 2000;
int houro = 216;
int day = 2;
int month = 2;
int year = 2012;
char* prof = "Программист";
char* posi = "Тимлид";


/*
Sotrudnik* obj1 = new Sotrudnik();
Sotrudnik* obj2 = new Sotrudnik();

ifstream intext("TextSotr.txt", ios::in);
intext >> *obj1;
intext.close();

cout << *obj1 << endl;
system("pause");

cin >> *obj1;

ofstream outbin("BinSotr.bin", ios::binary);
obj1->output(outbin);
outbin.close();

ifstream inbin("BinSotr.bin", ios::binary);
obj2->input(inbin);
inbin.close();


ofstream outtext("TextSotr.txt", ios::out);
outtext << *obj1;
outtext.close();

ifstream intext2("TextSotr.txt", ios::in);
intext2 >> *obj2;
intext2.close();

cout << *obj2 << endl; system("pause");


delete obj1;
delete obj2;
*/

Rabochiy* obj_rab1 = new Rabochiy();
Rabochiy* obj_rab2 = new Rabochiy();

obj_rab1 = new Rabochiy(Fio, okl, payo, houro, prof, day, month, year);
cout << *obj_rab1 << endl;
system("pause");
}