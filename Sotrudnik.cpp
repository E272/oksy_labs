#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "Sotrudnik.h"

using namespace std;

Sotrudnik::Sotrudnik():Payment()
{
	dob = 0;
	Position = new char;
}

Sotrudnik::Sotrudnik(char* fio, int okl, int doba, char* posi, int day, int month, int year):Payment(fio, okl, day, month, year)
{
	dob = doba;
	oklad += dob;
	int size = strlen(posi);
	Position = new char(size + 1);
	strcpy(Position, posi);
	Position[size] = '\0';
}

char* Sotrudnik::show()
{
	int i;
	
	char *okl = new char[1000000];
	char *v = new char[11];
	char *vr = new char[11];
	char *otc = new char[100000];
	char *pod = new char[100000];
	char *sum = new char[1000000];
	char *dobv = new char[16];

	int len_str = 0;
	int a = dob;
	int k = 1;
	int j = 0;

		if (a == 0)
		{
			dobv[j] = '0';
			j++;
		}

		while (a != 0) {
			a /= 10;
			k *= 10;
		}
		k /= 10;

		while (k != 0) {
			a = dob;
			char x = (a / k % 10) + 48;
			k /= 10;
			dobv[j] = x;
			j++;
		}
		dobv[j++] = '\0';

	/*Зарплата*/
	Sotrudnik::summa();

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
	int razm = strlen(FIO) + strlen(okl) + strlen(vr) + strlen(otc) + strlen(pod) + strlen(sum) + strlen(Position) + strlen(dobv) + 8;
	char *bufer = new char[razm];
	memset(bufer, '\0', razm);
	
	strcpy(bufer, FIO);
	
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, okl);
	
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, dobv);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, Position);

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
	delete[]dobv;
	
	return bufer;
}

std::istream& operator >> (std::istream& is, Sotrudnik& a) {
	char *c = new char[100];
	cout << "Введите ФИО-";
	is.getline(c, 100, '\n');
	cout << "Введите оклад-";
	int o;
	is >> o;
	cout << "Введите надбавку";
	int db;
	is >> db;
	
		is.clear();
			is.ignore();

	cout << "Введите должность-"; 
	char* pos = new char[100];
	is.getline(pos, 100);

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
	a.dob = db;
	delete[]a.Position;
	a.Position = pos;
	return is;
}
std::ostream& operator << (std::ostream& os, Sotrudnik& a) {
	char *c;
	c = a.show();
	os << c;
	delete c;
	return os;
}
std::ifstream& operator >> (std::ifstream& is, Sotrudnik& a) {
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

	int db;
	is >> db;

	char* pos = new char[100];
	is >> pos;

	int d, m, y;
	do {
		is >> d >> m >> y;
		if (0 >= d && d >= 32) cout << "Неверный формат времени!" << endl;
		if (0 >= m && m >= 13) cout << "Неверный формат месяца!" << endl;
		if (y >= 2018) cout << "Неверный формат года!" << endl;
	} while (0 >= d && d >= 32 && 0 >= m && m >= 13 && y >= 2018);
	//Sotrudnik *t = new Sotrudnik(c, o, db, pos, d, m, y);
	//a = *t;
	a.yearv = y;
	a.monv = m;
	a.dayv = d;
	delete[]a.FIO;
	a.FIO = c;
	a.oklad = o;
	a.dob = db;
	delete[]a.Position;
	a.Position = pos;
	delete[]sr;
	delete[]n;
	delete[]sn;
	return is;
}
std::ofstream& operator << (std::ofstream& os, Sotrudnik& a) {
	char *c;
	c = a.show();
	os << c << endl;
	delete[] c;
	return os;
}

std::ifstream& Sotrudnik::input(std::ifstream& is) {
	int len;
	is.read((char*)&len, sizeof(int));
	delete[]FIO;
	FIO = new char[len + 1];
	is.read(FIO, len * sizeof(char));
	FIO[len] = 0;
	is.read((char*)&oklad, sizeof(float));
	is.read((char*)&len, sizeof(int));
	delete[] Position;
	Position = new char[len + 1];
	is.read(Position, len * sizeof(char));
	Position[len] = 0;
	is.read((char*)&dob, sizeof(int));
	is.read((char*)&dayv, sizeof(int));
	is.read((char*)&monv, sizeof(int));
	is.read((char*)&yearv, sizeof(int));
	return is;
}

std::ofstream& Sotrudnik::output(std::ofstream& os) {
	int len = strlen(FIO);
	os.write((char*)&len, sizeof(int));
		os.write(FIO, len*sizeof(char));
	os.write((char*)&oklad, sizeof(float));
	len = strlen(Position);
	os.write((char*)&len, sizeof(int));
	os.write((char*)Position, len*sizeof(char));
	os.write((char*)&dob, sizeof(int));
	os.write((char*)&dayv, sizeof(int));
	os.write((char*)&monv, sizeof(int));
	os.write((char*)&yearv, sizeof(int));
	return os;
}

Sotrudnik& Sotrudnik::operator=(const Sotrudnik &a)
{
	return *this;
}

Sotrudnik::~Sotrudnik()
{
	delete[] Position;
}