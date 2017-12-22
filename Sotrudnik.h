#pragma once
#include "Class.h"

class Sotrudnik : public Payment
{
private:
	int dob;
	char* Position;

public:
	Sotrudnik(int dob, char* prof);

	int summa() override;

	int otchisl() override;

	int podoh() override;

	char* show() override;

};