#include "Sotrudnik.h"

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
	vr[i] = '/';
	_itoa(monv, v, 10);
	strcat(vr, v);
	memset(v, '\0', 11);
	for (i = 0; vr[i] != '\0' && i < 11; i++);
	vr[i] = '/';
	_itoa(yearv, v, 10);
	strcat(vr, v);
	int razm = strlen(FIO) + strlen(okl) + strlen(vr) + strlen(otc) + strlen(pod) + strlen(sum) + strlen(Position) + strlen(dobv) + 8;
	char *bufer = new char[razm];
	memset(bufer, '\0', razm);
	
	strcpy(bufer, FIO);

	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, Position);
	
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, vr);
	
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, okl);
	
	for (i = 0; bufer[i] != '\0' && i < razm; i++);
	bufer[i] = ' ';
	strcat(bufer, dobv);

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