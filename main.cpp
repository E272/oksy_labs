#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "Class.h"
#include "Rabochiy.h"
#include "Sotrudnik.h"
#define CIN_FLUSH while(cin.peek()!=10)cin.ignore();cin.ignore()

using namespace std;

void MENU()
{

}

int main() {
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
		cout << "�������� ������ �������� �������:" << endl;
		cout << "1. � ������� ���������� �����" << endl;
		cout << "2. � ������� ��������� �����" << endl;
		cout << "3. ���� � ����������" << endl;
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
	cout << "0 - �����" << endl;
	for (; 1 > 0;) {
		cout << endl << ">> ";
		cin >> a;
		switch (a) {
		case 1:
			cout << "����� summa" << endl;
			cout << "��������: " << emp->summa() << endl;
			cout << "�������� ()" << endl;
			qwe = emp->operator()();
			cout << qwe << endl;
			break;
		case 2: cout << "����� ����� ������� ������� �� ����� ������ ���������: " << emp->otchisl() << " ������" << endl; break;
		case 3: cout << "���������� � ���������� ���� �� ����� ������ ���������: " << emp->podoh() << " ������" << endl; break;
		case 4: str = emp->show();  cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str; break;
		case 5: { Payment *emp1 = new Payment(*emp);  str = emp1->show(); cout << "���, ���� �������� �� ������, ����� ����������, ��������, ���������� � ���������� ����, ���������� �����" << endl << str << endl; delete[] str; delete emp1;  break; }
		case 6:
			cout << "1 - ��������� �����" << endl << "2 - ��������� �����" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�� ������� ������ ��������� �����?  ";
				cin >> qwe;
				*emp = *emp + qwe;
				cout << emp->operator()() << endl;
			}
			if (d == 2) {
				cout << "�� ������� ������ ��������� �����?  ";
				cin >> qwe;
				*emp = *emp - qwe;
				cout << emp->operator()() << endl;
			}
			break;
		case 7:
			cout << "1 - ��������� ��� ����������� �� ������" << endl << "2 - ��������� ��� ����������� �� ������" << endl;
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
			cout << "����� �������� ���" << endl;
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

	

	return 0;
}