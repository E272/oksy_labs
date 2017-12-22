#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include "Class.h"
#include <fstream>

using namespace std;

int Payment::proch = 12;

Payment::Payment() {
	FIO = new char;
	oklad = 0;
	ot = 0;
	ot = 0;
	p = 0;
	s = 0;
	dayv = 0;
	monv = 0;
	yearv = 0;
}
Payment::Payment(char *fio, float okl, int day, int month, int year) {
	int r = strlen(fio);
	FIO = new char[r + 1];
	strcpy(FIO, fio);
	FIO[r] = 0;
	oklad = okl;
	ot = 0;
	p = 0;
	s = 0;
	dayv = day;
	monv = month;
	yearv = year;
}
Payment::Payment(const Payment &a) {
	int r = strlen(a.FIO);
	FIO = new char[r + 1];
	strcpy(FIO, a.FIO);
	oklad = a.oklad;
	ot = a.ot;
	p = a.p;
	s = a.s;
	dayv = a.dayv;
	monv = a.monv;
	yearv = a.yearv;
	cout << "Конструктор копирования сработал" << endl;
}
Payment::~Payment() {
	delete[]FIO;
}
int Payment::otchisl() {
	struct tm* now;
	time_t t;
	time(&t);
	now = localtime(&t);
	now->tm_mon++;
	now->tm_year += 1900;
	ot = oklad / 100;
	cout << "Отчисления в пенсионный фонд в месяц: " << ot << " рублей" << endl;
	int r;
	r = (now->tm_year - yearv) * 12 + (now->tm_mon - monv);
	return r*ot;
	//	delete now;
}
int Payment::podoh() {
	p = oklad / 100 * proch;
	cout << "Подоходный налог в месяц: " << p << " рублей" << endl;
	struct tm* now;
	time_t t;
	time(&t);
	now = localtime(&t);
	now->tm_mon++;
	now->tm_year += 1900;
	int r;
	r = (now->tm_year - yearv) * 12 + (now->tm_mon - monv);
	return r*p;
	//	delete now;
}
int Payment::summa() {
	s = oklad - oklad / 100 - oklad / 100 * 12;
	return s;
}
char* Payment::show() {
	int i;
	char *okl = new char[1000000];
	char *v = new char[11];
	char *vr = new char[11];
	char *otc = new char[100000];
	char *pod = new char[100000];
	char *sum = new char[1000000];

	/*Зарплата*/
	Payment::summa();

	/*Отчисления*/
	struct tm* now;
	time_t t;
	time(&t);
	now = localtime(&t);
	now->tm_mon++;
	now->tm_year += 1900;
	ot = oklad / 100;

	/*Подоходный налог*/
	p = oklad / 100 * proch;

	memset(okl, '\0', 11);
	memset(v, '\0', 11);
	memset(vr, '\0', 11);
	memset(otc, '\0', 11);
	memset(pod, '\0', 11);
	memset(sum, '\0', 11);
	_itoa(oklad, okl, 10);
	_itoa(ot, otc, 10);
	_itoa(p, pod, 10);
	_itoa(s, sum, 10);
	_itoa(dayv, v, 10);
	strcat(vr, v);
	memset(v, '\0', 11);
	for (i = 0; vr[i] != '\0' && i < 11; i++);
	vr[i] = '/';
	_itoa(monv, v, 10);
	strcat(vr, v);
	memset(v, '\0', 11);
	for (i = 0; vr[i] != '\0' && i < 11; i++);
	vr[i] = '/';
	_itoa(yearv, v, 10);
	strcat(vr, v);
	int razm = strlen(FIO) + strlen(okl) + strlen(vr) + strlen(otc) + strlen(pod) + strlen(sum) + 6;
	char *bufer = new char[razm];
	memset(bufer, '\0', razm);
	strcpy(bufer, FIO);
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, vr);
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, okl);
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, sum);
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, otc);
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, pod);

	//cout << "ФИО, дата принятия на работу, оклад сотрудника, зарплата, отчисления в пенсионный фонд, подоходный налог" << endl << bufer << endl;
	delete[]okl;
	delete[]v;
	delete[]vr;
	delete[]otc;
	delete[]pod;
	delete[]sum;
	//delete[]bufer;
	return bufer;
}
Payment operator+(Payment a, int k) {
	Payment dh = a;
	dh.oklad = a.oklad + k;
	return dh;
}
Payment operator-(Payment a, int k) {
	Payment dh = a;
	dh.oklad = a.oklad - k;
	return dh;
}
Payment& Payment::operator++() {
	yearv++;
	return *this;
}
Payment Payment::operator++(int) {
	Payment b = *this;
	yearv++;
	return b;
}
Payment& Payment::operator--() {
	yearv--;
	return *this;
}
Payment Payment::operator--(int) {
	Payment b = *this;
	yearv--;
	return b;
}
int Payment::operator()() {
	s = oklad - oklad / 100 - oklad / 100 * 12;
	return s;
}
Payment& Payment::operator=(const Payment &a) {
	int r = strlen(a.FIO);
	FIO = new char[r + 1];
	strcpy(FIO, a.FIO);
	oklad = a.oklad;
	ot = a.ot;
	p = a.p;
	s = a.s;
	dayv = a.dayv;
	monv = a.monv;
	yearv = a.yearv;
	return *this;
}

std::istream& operator >> (std::istream& is, Payment& a) {
	char *c = new char[100];
	if (cin.peek()) {
		is.ignore();
	}
	is.getline(c, 100, '\n');
	int o;
	is >> o;
	int d, m, y;
	do {
		is >> d >> m >> y;
		if (0 >= d && d >= 32) cout << "Неверный формат времени!" << endl;
		if (0 >= m && m >= 13) cout << "Неверный формат месяца!" << endl;
		if (y >= 2018) cout << "Неверный формат года!" << endl;
	} while (0 >= d && d >= 32 && 0 >= m && m >= 13 && y >= 2018);
	Payment *t = new Payment(c, o, d, m, y);
	a = *t;
	delete t;
	delete[] c;
	return is;
}
std::ostream& operator << (std::ostream& os, Payment& a) {
	char *c;
	c = a.show();
	os << c << endl;
	delete c;
	return os;
}
std::ifstream& operator >> (std::ifstream& is, Payment& a) {
	char *sr = new char[20];
	char *n = new char[20];
	char *sn = new char[20];
	is >> sr >> n >> sn;
	char *c = new char[70];
	strcpy(c, sr);
	strcat(c, " ");
	strcat(c, n);
	strcat(c, " ");
	strcat(c, sn);
	int o;
	is >> o;
	int d, m, y;
	do {
		is >> d >> m >> y;
		if (0 >= d && d >= 32) cout << "Неверный формат времени!" << endl;
		if (0 >= m && m >= 13) cout << "Неверный формат месяца!" << endl;
		if (y >= 2018) cout << "Неверный формат года!" << endl;
	} while (0 >= d && d >= 32 && 0 >= m && m >= 13 && y >= 2018);
	Payment *t = new Payment(c, o, d, m, y);
	a = *t;
	delete t;
	delete[]c;
	delete[]sr;
	delete[]n;
	delete[]sn;
	return is;
}
std::ofstream& operator << (std::ofstream& os, Payment& a) {
	char *c;
	c = a.show();
	os << c << endl;
	delete[] c;
	return os;
}

std::ifstream& Payment::input(std::ifstream& is) {
	int len;
	is.read((char*)&len, sizeof(int));
	delete FIO;
	FIO = new char[len + 1];
	is.read((char*)FIO, len * sizeof(char));
	is.read((char*)&oklad, sizeof(float));
	is.read((char*)&dayv, sizeof(int));
	is.read((char*)&monv, sizeof(int));
	is.read((char*)&yearv, sizeof(int));
	return is;
}

std::ofstream& Payment::output(std::ofstream& os) {
	int len = strlen(FIO);
	len++;
	os.write((char*)&len, sizeof(int));
	for (int i=0; i<len; i++)
		os.write((char*)&FIO[i], sizeof(char));
		os.write((char*)&oklad, sizeof(float));
		os.write((char*)&dayv, sizeof(int));
		os.write((char*)&monv, sizeof(int));
		os.write((char*)&yearv, sizeof(int));
	return os;
}