#ifndef _BLYAD_H
#define _BLYAD_H
#include "Class.h"

class Sotrudnik : public Payment
{
private:
	int dob;
	char* Position;

public:
	Sotrudnik();

	Sotrudnik(char* fio, int okl, int dob, char* prof, int day, int month, int year);

	char* show() override;


	friend std::istream& operator>> (std::istream& is, Sotrudnik &a);
	friend std::ostream& operator<< (std::ostream& os, Sotrudnik &a);
	friend std::ifstream& operator>> (std::ifstream& is, Sotrudnik &a);
	friend std::ofstream& operator<< (std::ofstream& os, Sotrudnik &a);
	std::ifstream& input(std::ifstream& is);
	std::ofstream& output(std::ofstream& os);

	Sotrudnik& operator=(const Sotrudnik &a);

	~Sotrudnik();
};
#endif