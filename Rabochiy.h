#pragma once
#include "Class.h"

class Rabochiy : public Payment
{
private:
	char* Proffesion;
	int pay_for_hour;
	int hour_per_month;

public:
	Rabochiy();

	int summa() override;



};