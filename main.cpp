#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "Rabochiy.h"
#include "Sotrudnik.h"
#define CIN_FLUSH while(cin.peek()!=10)cin.ignore();cin.ignore()

using namespace std;

void MENU_PAYMENT()
{
	cout << "������ � ������� Payment" << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - �������� ���������� � ���������� ����" << endl;
	cout << "3 - �������� ���������� �����" << endl;
	cout << "4 - ��������� �������������" << endl;
	cout << "5 - ����������� �����������" << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� ��� ����������� �� ������" << endl;
	cout << "8 - ����� �� �����" << endl;
	cout << "9 - ������ � ��������� ����" << endl;
	cout << "10 - ������ � �������� ����" << endl;
	cout << "11 - ������ �� ���������� �����" << endl;
	cout << "12 - ������ �� ��������� �����" << endl;
	cout << "0 - ��������� � ������ ���� �������" << endl;
}

void MENU_SOTRUDNIK()
{
	cout << "������ � ������� Sotrudnik" << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - �������� ���������� � ���������� ����" << endl;
	cout << "3 - �������� ���������� �����" << endl;
	cout << "4 - ��������� �������������" << endl;
	cout << "5 - ����������� �����������" << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� ��� ����������� �� ������" << endl;
	cout << "8 - ����� �� �����" << endl;
	cout << "9 - ������ � ��������� ����" << endl;
	cout << "10 - ������ � �������� ����" << endl;
	cout << "11 - ������ �� ���������� �����" << endl;
	cout << "12 - ������ �� ��������� �����" << endl;
	cout << "0 - ��������� � ������ ���� �������" << endl;
}

void MENU_RABOCHIY()
{
	cout << "������ � ������� Rabochiy" << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - �������� ���������� � ���������� ����" << endl;
	cout << "3 - �������� ���������� �����" << endl;
	cout << "4 - ��������� �������������" << endl;
	cout << "5 - ����������� �����������" << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� ��� ����������� �� ������" << endl;
	cout << "8 - ����� �� �����" << endl;
	cout << "9 - ������ � ��������� ����" << endl;
	cout << "10 - ������ � �������� ����" << endl;
	cout << "11 - ������ �� ���������� �����" << endl;
	cout << "12 - ������ �� ��������� �����" << endl;
	cout << "0 - ��������� � ������ ���� �������" << endl;
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
		cout << "�������� ��� �������:" << endl;
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
					cout << "����� summa" << endl;
					cout << "��������: " << obj_Payment->summa() << endl;
					cout << "�������� ()" << endl;
					te = obj_Payment->operator()();
					cout << te << endl;
					break;

				case 2:
					cout << "����� ����� ������� ������� �� ����� ������ ���������: " << obj_Payment->otchisl() << " ������" << endl;
					break;

				case 3:
					cout << "���������� � ���������� ���� �� ����� ������ ���������: " << obj_Payment->podoh() << " ������" << endl;
					break;

				case 4:
					str = obj_Payment->show();  cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str;
					break;

				case 5:
				{	Payment *obj_Payment1 = new Payment(*obj_Payment);
				str = obj_Payment1->show();
				cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str; delete obj_Payment1;
				break;
				}

				case 6:
					cout << "1 - ��������� �����" << endl << "2 - ��������� �����" << endl;
					cin >> num;
					if (num == 1) {
						cout << "�� ������� ������ ��������� �����?  ";
						cin >> te;
						*obj_Payment = *obj_Payment + te;
						cout << obj_Payment->operator()() << endl;
					}
					if (num == 2) {
						cout << "�� ������� ������ ��������� �����?  ";
						cin >> te;
						*obj_Payment = *obj_Payment - te;
						cout << obj_Payment->operator()() << endl;
					}
					break;

				case 7:
					cout << "1 - ��������� ��� ����������� �� ������" << endl << "2 - ��������� ��� ����������� �� ������" << endl;
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
					cout << "����� summa" << endl;
					cout << "��������: " << obj_Payment->summa() << endl;
					cout << "�������� ()" << endl;
					te = obj_Sotrudnik->operator()();
					cout << te << endl;
					break;

				case 2:
					cout << "����� ����� ������� ������� �� ����� ������ ���������: " << obj_Sotrudnik->otchisl() << " ������" << endl;
					break;

				case 3:
					cout << "���������� � ���������� ���� �� ����� ������ ���������: " << obj_Sotrudnik->podoh() << " ������" << endl;
					break;

				case 4:
					str = obj_Sotrudnik->show();  cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str;
					break;

				case 5:
				{	Sotrudnik *obj_Sotrudnik1 = new Sotrudnik(*obj_Sotrudnik);
				str = obj_Sotrudnik1->show();
				cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str; delete obj_Sotrudnik1;
				break;
				}

				case 6:
					cout << "1 - ��������� �����" << endl << "2 - ��������� �����" << endl;
					cin >> num;
					if (num == 1) {
						cout << "�� ������� ������ ��������� �����?  ";
						cin >> te;
						*obj_Sotrudnik = *obj_Sotrudnik + te;
						cout << obj_Sotrudnik->operator()() << endl;
					}
					if (num == 2) {
						cout << "�� ������� ������ ��������� �����?  ";
						cin >> te;
						*obj_Sotrudnik = *obj_Sotrudnik - te;
						cout << obj_Sotrudnik->operator()() << endl;
					}
					break;

				case 7:
					cout << "1 - ��������� ��� ����������� �� ������" << endl << "2 - ��������� ��� ����������� �� ������" << endl;
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
					cout << "����� summa" << endl;
					cout << "��������: " << obj_Rabochiy->summa() << endl;
					cout << "�������� ()" << endl;
					te = obj_Rabochiy->operator()();
					cout << te << endl;
					break;

				case 2:
					cout << "����� ����� ������� ������� �� ����� ������ ���������: " << obj_Rabochiy->otchisl() << " ������" << endl;
					break;

				case 3:
					cout << "���������� � ���������� ���� �� ����� ������ ���������: " << obj_Rabochiy->podoh() << " ������" << endl;
					break;

				case 4:
					str = obj_Rabochiy->show();  cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str;
					break;

				case 5:
				{	Payment *obj_Rabochiy1 = new Payment(*obj_Rabochiy);
				str = obj_Rabochiy1->show();
				cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str; delete obj_Rabochiy1;
				break;
				}

				case 6:
					cout << "1 - ��������� �����" << endl << "2 - ��������� �����" << endl;
					cin >> num;
					if (num == 1) {
						cout << "�� ������� ������ ��������� �����?  ";
						cin >> te;
						*obj_Rabochiy = *obj_Rabochiy + te;
						cout << obj_Rabochiy->operator()() << endl;
					}
					if (num == 2) {
						cout << "�� ������� ������ ��������� �����?  ";
						cin >> te;
						*obj_Rabochiy = *obj_Rabochiy - te;
						cout << obj_Rabochiy->operator()() << endl;
					}
					break;

				case 7:
					cout << "1 - ��������� ��� ����������� �� ������" << endl << "2 - ��������� ��� ����������� �� ������" << endl;
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