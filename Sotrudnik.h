#pragma once
#include "Class.h"

/*
����� �������� ���������� �����������. 
�������� ����: ���������, �������� �� ����-����� (V)
����������� ����� ������� ����� �������� � ������ ������ ������; (X)
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