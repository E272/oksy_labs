#ifndef _RAB_H
#define _RAB_H
#include "Class.h"

class Rabochiy : public Payment
{
private:
	char* Proffesion;
	int pay_for_hour;
	int hour_per_month;

public:
	Rabochiy();

	Rabochiy(char* fio, int okl, int pay, int hourp, char* prof, int day, int month, int year);

	char* show() override;


	friend std::istream& operator>> (std::istream& is, Rabochiy &a);
	friend std::ostream& operator<< (std::ostream& os, Rabochiy &a);
	friend std::ifstream& operator>> (std::ifstream& is, Rabochiy &a);
	friend std::ofstream& operator<< (std::ofstream& os, Rabochiy &a);
	std::ifstream& input(std::ifstream& is);
	std::ofstream& output(std::ofstream& os);

	Rabochiy& operator=(const Rabochiy &a);

	~Rabochiy();
};
#endif