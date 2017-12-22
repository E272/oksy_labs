#pragma once
#include "Class.h"

/*
класс зарплата рабочего предприятия. 
Добавить поля: профессия, оплата 1 часа работы, 
количество часов за месяц 
перегрузить метод расчета суммы зарплаты и другие методы класса.
*/

class Rabochiy : public Payment
{
private:
	char* proffesion;
	int pay_for_hour;
	int hour_per_month;

public:
	Rabochiy();

	int summa() override;



};