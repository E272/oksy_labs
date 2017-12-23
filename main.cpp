#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "Rabochiy.h"
#include "Sotrudnik.h"
#define CIN_FLUSH while(cin.peek()!=10)cin.ignore();cin.ignore()

using namespace std;

void MENU_PAYMENT()
{
	cout << "Работа с классом Payment" << endl;
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
	cout << "11 - Запись из текстового файла" << endl;
	cout << "12 - Запись из бинарного файла" << endl;
	cout << "0 - Вернуться к выбору типа объекта" << endl;
}

void MENU_SOTRUDNIK()
{
	cout << "Работа с классом Sotrudnik" << endl;
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
	cout << "11 - Запись из текстового файла" << endl;
	cout << "12 - Запись из бинарного файла" << endl;
	cout << "0 - Вернуться к выбору типа объекта" << endl;
}

void MENU_RABOCHIY()
{
	cout << "Работа с классом Rabochiy" << endl;
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
	cout << "11 - Запись из текстового файла" << endl;
	cout << "12 - Запись из бинарного файла" << endl;
	cout << "0 - Вернуться к выбору типа объекта" << endl;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char *c = new char[180];
	char* str = nullptr;
	Payment *obj_Payment = new Payment;
	Sotrudnik *obj_Sotrudnik = new Sotrudnik;
	Rabochiy *obj_Rabochiy = new Rabochiy;
	int num, pr, te;
	pr = 0;

	while (1 > 0)
	{
		cout << "Выберите тип объекта:" << endl;
		cout << "1. Payment" << endl;
		cout << "2. Sotrudnik" << endl;
		cout << "3. Rabochiy" << endl;
		cout << "0. EXIT" << endl;
		cout << ">>";
		cin >> num;
		system("cls");

		switch (num)
		{
		case 1:
			MENU_PAYMENT();
			while (1 > 0)
			{
				cout << ">>";
				cin >> num;

				switch (num)
				{
				case 1:
					cout << "Метод summa" << endl;
					cout << "Зарплата: " << obj_Payment->summa() << endl;
					cout << "Операция ()" << endl;
					te = obj_Payment->operator()();
					cout << te << endl;
					break;

				case 2:
					cout << "Общая сумма изъятых налогов за время работы составила: " << obj_Payment->otchisl() << " рублей" << endl;
					break;

				case 3:
					cout << "Отчисления в пенсионный фонд за время работы составили: " << obj_Payment->podoh() << " рублей" << endl;
					break;

				case 4:
					str = obj_Payment->show();  cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str;
					break;

				case 5:
				{	Payment *obj_Payment1 = new Payment(*obj_Payment);
				str = obj_Payment1->show();
				cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str; delete obj_Payment1;
				break;
				}

				case 6:
					cout << "1 - Увеличить оклад" << endl << "2 - Уменьшить оклад" << endl;
					cin >> num;
					if (num == 1) {
						cout << "На сколько хотите увеличить оклад?  ";
						cin >> te;
						*obj_Payment = *obj_Payment + te;
						cout << obj_Payment->operator()() << endl;
					}
					if (num == 2) {
						cout << "На сколько хотите уменьшить оклад?  ";
						cin >> te;
						*obj_Payment = *obj_Payment - te;
						cout << obj_Payment->operator()() << endl;
					}
					break;

				case 7:
					cout << "1 - Увеличить год поступления на работу" << endl << "2 - Уменьшить год поступления на работу" << endl;
					cin >> num;
					if (num == 1) {
						obj_Payment->operator++();
						cout << obj_Payment->show() << endl;
					}
					if (num == 2) {
						obj_Payment->operator--();
						cout << obj_Payment->show() << endl;
					}
					break;

				case 8:
					cout << *obj_Payment;
					break;

				case 9:
				{
					ofstream outtex("Text.txt", ios::out);
					outtex << *obj_Payment;
					outtex.close();
					break;
				}

				case 10:
				{
					ofstream outbin("Bin.bin", ios::binary);
					obj_Payment->output(outbin);
					outbin.close();
					break;
				}

				case 11:
				{
					ifstream intext("Text.txt", ios::in);
					intext >> *obj_Payment;
					intext.close();
					break;
				}

				case 12:
				{
					ifstream inbin("Bin.bin", ios::binary);
					obj_Payment->input(inbin);
					inbin.close();
					break;
				}

				case 0:
					pr = -1;
					break;
				}
				if (pr == -1)
				{
					pr = 0;
					break;
				}
			}
			break;

		case 2:
			MENU_SOTRUDNIK();
			while (1 > 0)
			{
				cout << ">>";
				cin >> num;

				switch (num)
				{
				case 1:
					cout << "Метод summa" << endl;
					cout << "Зарплата: " << obj_Payment->summa() << endl;
					cout << "Операция ()" << endl;
					te = obj_Sotrudnik->operator()();
					cout << te << endl;
					break;

				case 2:
					cout << "Общая сумма изъятых налогов за время работы составила: " << obj_Sotrudnik->otchisl() << " рублей" << endl;
					break;

				case 3:
					cout << "Отчисления в пенсионный фонд за время работы составили: " << obj_Sotrudnik->podoh() << " рублей" << endl;
					break;

				case 4:
					str = obj_Sotrudnik->show();  cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str;
					break;

				case 5:
				{	Sotrudnik *obj_Sotrudnik1 = new Sotrudnik(*obj_Sotrudnik);
				str = obj_Sotrudnik1->show();
				cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str; delete obj_Sotrudnik1;
				break;
				}

				case 6:
					cout << "1 - Увеличить оклад" << endl << "2 - Уменьшить оклад" << endl;
					cin >> num;
					if (num == 1) {
						cout << "На сколько хотите увеличить оклад?  ";
						cin >> te;
						*obj_Sotrudnik = *obj_Sotrudnik + te;
						cout << obj_Sotrudnik->operator()() << endl;
					}
					if (num == 2) {
						cout << "На сколько хотите уменьшить оклад?  ";
						cin >> te;
						*obj_Sotrudnik = *obj_Sotrudnik - te;
						cout << obj_Sotrudnik->operator()() << endl;
					}
					break;

				case 7:
					cout << "1 - Увеличить год поступления на работу" << endl << "2 - Уменьшить год поступления на работу" << endl;
					cin >> num;
					if (num == 1) {
						obj_Sotrudnik->operator++();
						cout << obj_Sotrudnik->show() << endl;
					}
					if (num == 2) {
						obj_Sotrudnik->operator--();
						cout << obj_Sotrudnik->show() << endl;
					}
					break;

				case 8:
					cout << *obj_Sotrudnik;
					break;

				case 9:
				{
					ofstream outtexsotr("TextSotr.txt", ios::out);
					outtexsotr << *obj_Sotrudnik;
					outtexsotr.close();
					break;
				}

				case 10:
				{
					ofstream outbinsotr("BinSotr.bin", ios::binary);
					obj_Sotrudnik->output(outbinsotr);
					outbinsotr.close();
					break;
				}

				case 11:
				{
					ifstream intextsotr("TextSotr.txt", ios::in);
					intextsotr >> *obj_Sotrudnik;
					intextsotr.close();
					break;
				}

				case 12:
				{
					ifstream inbinsotr("BinSotr.bin", ios::binary);
					obj_Sotrudnik->input(inbinsotr);
					inbinsotr.close();
					break;
				}

				case 0:
					pr = -1;
					break;
				}
				if (pr == -1)
				{
					pr = 0;
					break;
				}
			}
			break;

		case 3:
			MENU_RABOCHIY();
			while (1 > 0)
			{
				cout << ">>";
				cin >> num;

				switch (num)
				{
				case 1:
					cout << "Метод summa" << endl;
					cout << "Зарплата: " << obj_Rabochiy->summa() << endl;
					cout << "Операция ()" << endl;
					te = obj_Rabochiy->operator()();
					cout << te << endl;
					break;

				case 2:
					cout << "Общая сумма изъятых налогов за время работы составила: " << obj_Rabochiy->otchisl() << " рублей" << endl;
					break;

				case 3:
					cout << "Отчисления в пенсионный фонд за время работы составили: " << obj_Rabochiy->podoh() << " рублей" << endl;
					break;

				case 4:
					str = obj_Rabochiy->show();  cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str;
					break;

				case 5:
				{	Payment *obj_Rabochiy1 = new Payment(*obj_Rabochiy);
				str = obj_Rabochiy1->show();
				cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << str << endl; delete[] str; delete obj_Rabochiy1;
				break;
				}

				case 6:
					cout << "1 - Увеличить оклад" << endl << "2 - Уменьшить оклад" << endl;
					cin >> num;
					if (num == 1) {
						cout << "На сколько хотите увеличить оклад?  ";
						cin >> te;
						*obj_Rabochiy = *obj_Rabochiy + te;
						cout << obj_Rabochiy->operator()() << endl;
					}
					if (num == 2) {
						cout << "На сколько хотите уменьшить оклад?  ";
						cin >> te;
						*obj_Rabochiy = *obj_Rabochiy - te;
						cout << obj_Rabochiy->operator()() << endl;
					}
					break;

				case 7:
					cout << "1 - Увеличить год поступления на работу" << endl << "2 - Уменьшить год поступления на работу" << endl;
					cin >> num;
					if (num == 1) {
						obj_Rabochiy->operator++();
						cout << obj_Rabochiy->show() << endl;
					}
					if (num == 2) {
						obj_Rabochiy->operator--();
						cout << obj_Rabochiy->show() << endl;
					}
					break;

				case 8:
					cout << *obj_Rabochiy;
					break;

				case 9:
				{
					ofstream outtexrab("TextRab.txt", ios::out);
					outtexrab << *obj_Rabochiy;
					outtexrab.close();
					break;
				}

				case 10:
				{
					ofstream outbinrab("BinRab.bin", ios::binary);
					obj_Rabochiy->output(outbinrab);
					outbinrab.close();
					break;
				}

				case 11:
				{
					ifstream intextrab("TextRab.txt", ios::in);
					intextrab >> *obj_Rabochiy;
					intextrab.close();
					break;
				}

				case 12:
				{
					ifstream inbinrab("BinRab.bin", ios::binary);
					obj_Rabochiy->input(inbinrab);
					inbinrab.close();
					break;
				}

				case 0:
					pr = -1;
					break;
				}
				if (pr == -1)
				{
					pr = 0;
					break;
				}
			}
				break;

		case 0:
			pr = -1;
			break;
			}

			if (pr == -1)
				break;

			
		}
		system("pause");

		delete obj_Payment;
		delete obj_Sotrudnik;
		delete obj_Rabochiy;
}