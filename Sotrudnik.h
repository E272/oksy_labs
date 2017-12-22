#ifndef _BLYAD_H
#define _BLYAD_H
#include "Class.h"

class Sotrudnik : public Payment
{
private:
	int dob;
	char* Position;

public:
	Sotrudnik(char* fio, int okl, int dob, char* prof, int day, int month, int year);

	char* show() override;




	Payment& operator=(const Payment &a);
};
#endif