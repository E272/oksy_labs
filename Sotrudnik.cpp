#include "Sotrudnik.h"

Sotrudnik::Sotrudnik(int dob, char* posi):Payment(FIO, oklad, dayv, monv, yearv)
{
	dob = dob;
	int size = strlen(posi);
	Position = new char(size + 1);
	strcpy(Position, posi);
	Position[size] = '\0';
}

int Sotrudnik::summa()
{
	s = oklad + dob - (oklad + dob) / 100 - (oklad + dob) / 100 * 12;

	return s;
}

char* Sotrudnik::show()
{
	char* str = nullptr;



	return str;
}