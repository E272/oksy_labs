#pragma once
#include "Class.h"

/*
����� �������� �������� �����������. 
�������� ����: ���������, ������ 1 ���� ������, 
���������� ����� �� ����� 
����������� ����� ������� ����� �������� � ������ ������ ������.
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