#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "Rabochiy.h"

using namespace std;

Rabochiy::Rabochiy():Payment()
{
	Proffesion = new char;
	pay_for_hour = 0;
	hour_per_month = 0;
}

Rabochiy::Rabochiy(char* fio, int okl, int pay, int hourp, char* prof, int day, int month, int year) : Payment(fio, okl, day, month, year)
{
	pay_for_hour = pay;
	hour_per_month = hourp;
	oklad = pay_for_hour*hour_per_month;
	int size = strlen(prof);
	Proffesion = new char(size + 1);
	Proffesion[size] = '\0';
}

char* Rabochiy::show()
{
	int i;

	char *okl = new char[1000000];
	char *v = new char[11];
	char *vr = new char[11];
	char *otc = new char[100000];
	char *pod = new char[100000];
	char *sum = new char[1000000];
	char *payf = new char[16];
	char *houro = new char[16];

	int len_str = 0;
	int a = pay_for_hour;
	int k = 1;
	int j = 0;

	if (a == 0)
	{
		payf[j] = '0';
		j++;
	}

	while (a != 0) {
		a /= 10;
		k *= 10;
	}
	k /= 10;

	while (k != 0) {
		a = pay_for_hour;
		char x = (a / k % 10) + 48;
		k /= 10;
		payf[j] = x;
		j++;
	}
	payf[j++] = '\0';

	/*Зарплата*/
	Rabochiy::summa();

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
	vr[i] = ' ';
	_itoa(monv, v, 10);
	strcat(vr, v);
	memset(v, '\0', 11);
	for (i = 0; vr[i] != '\0' && i < 11; i++);
	vr[i] = ' ';
	_itoa(yearv, v, 10);
	strcat(vr, v);
	for (i = 0; vr[i] != '\0' && i < 11; i++);
	int razm = strlen(FIO) + strlen(okl) + strlen(vr) + strlen(otc) + strlen(pod) + strlen(sum) + strlen(Proffesion) + strlen(payf) + strlen(houro) +9;
	char *bufer = new char[razm];
	memset(bufer, '\0', razm);

	strcpy(bufer, FIO);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, okl);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, Proffesion);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, payf);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, houro);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, vr);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, sum);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, otc);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, pod);

	delete[]okl;
	delete[]v;
	delete[]vr;
	delete[]otc;
	delete[]pod;
	delete[]sum;
	delete[]payf;
	delete[]houro;

	return bufer;
}

std::istream& operator >> (std::istream& is, Rabochiy& a) {
	char *c = new char[100];
	cout << "Введите ФИО-";
	is.getline(c, 100, '\n');
	cout << "Введите оклад-";
	int o;
	is >> o;
	cout << "Введите плату за час-";
	int payf;
	is >> payf;
	cout << "Введите количество часов в месяц-";
	int houro;
	is >> houro;

	is.clear();
	is.ignore();

	cout << "Введите должность-";
	char* prof = new char[100];
	is.getline(prof, 100);

	cout << "Введите день/месяц/год-";
	int d, m, y;
	do {
		is >> d >> m >> y;
		if (0 >= d && d >= 32) cout << "Неверный формат времени!" << endl;
		if (0 >= m && m >= 13) cout << "Неверный формат месяца!" << endl;
		if (y >= 2018) cout << "Неверный формат года!" << endl;
	} while (0 >= d && d >= 32 && 0 >= m && m >= 13 && y >= 2018);
	a.yearv = y;
	a.monv = m;
	a.dayv = d;
	delete[]a.FIO;
	a.FIO = c;
	a.oklad = o;
	a.pay_for_hour = payf;
	a.hour_per_month = houro;
	delete[]a.Proffesion;
	a.Proffesion = prof;
	return is;
}
std::ostream& operator << (std::ostream& os, Rabochiy& a) {
	char *c;
	c = a.show();
	os << c;
	delete c;
	return os;
}
std::ifstream& operator >> (std::ifstream& is, Rabochiy& a) {
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

	char* prof = new char[100];
	is >> prof;

	int payf;
	is >> payf;

	int houro;
	is >> houro;

	int d, m, y;
	do {
		is >> d >> m >> y;
		if (0 >= d && d >= 32) cout << "Неверный формат времени!" << endl;
		if (0 >= m && m >= 13) cout << "Неверный формат месяца!" << endl;
		if (y >= 2018) cout << "Неверный формат года!" << endl;
	} while (0 >= d && d >= 32 && 0 >= m && m >= 13 && y >= 2018);
	a.yearv = y;
	a.monv = m;
	a.dayv = d;
	delete[]a.FIO;
	a.FIO = c;
	a.oklad = o;
	a.pay_for_hour = payf;
	a.hour_per_month = houro;
	delete[]a.Proffesion;
	a.Proffesion = prof;
	delete[]sr;
	delete[]n;
	delete[]sn;
	return is;
}
std::ofstream& operator << (std::ofstream& os, Rabochiy& a) {
	char *c;
	c = a.show();
	os << c << endl;
	delete[] c;
	return os;
}

std::ifstream& Rabochiy::input(std::ifstream& is) {
	int len;
	is.read((char*)&len, sizeof(int));
	delete[]FIO;
	FIO = new char[len + 1];
	is.read(FIO, len * sizeof(char));
	FIO[len] = 0;
	is.read((char*)&oklad, sizeof(float));
	is.read((char*)&len, sizeof(int));
	delete[] Proffesion;
	Proffesion = new char[len + 1];
	is.read(Proffesion, len * sizeof(char));
	Proffesion[len] = 0;
	is.read((char*)&pay_for_hour, sizeof(int));
	is.read((char*)&hour_per_month, sizeof(int));
	is.read((char*)&dayv, sizeof(int));
	is.read((char*)&monv, sizeof(int));
	is.read((char*)&yearv, sizeof(int));
	return is;
}

std::ofstream& Rabochiy::output(std::ofstream& os) {
	int len = strlen(FIO);
	os.write((char*)&len, sizeof(int));
	os.write(FIO, len * sizeof(char));
	os.write((char*)&oklad, sizeof(float));
	len = strlen(Proffesion);
	os.write((char*)&len, sizeof(int));
	os.write((char*)Proffesion, len * sizeof(char));
	os.write((char*)&pay_for_hour, sizeof(int));
	os.write((char*)&hour_per_month, sizeof(int));
	os.write((char*)&dayv, sizeof(int));
	os.write((char*)&monv, sizeof(int));
	os.write((char*)&yearv, sizeof(int));
	return os;
}

Rabochiy& Rabochiy::operator=(const Rabochiy &a)
{
	return *this;
}

Rabochiy::~Rabochiy()
{
	delete[] Proffesion;
}