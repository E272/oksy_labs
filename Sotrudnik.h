#pragma once
#include "Class.h"

/*
класс зарплата сотрудника предприятия. 
Добавить поля: должность, надбавка за долж-ность (V)
перегрузить метод расчета суммы зарплаты и другие методы класса; (X)
*/

class Sotrudnik : public Payment
{
private:
	int dob;
	char* Position;

public:
	Sotrudnik(int dob, char* prof);

	int summa() override;

	char* show() override;

};