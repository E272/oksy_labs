#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <fstream>

class Payment {
	/*char * FIO;
	float oklad;
	int dayv;
	int monv;
	int yearv;
	double ot;
	double p;
	double s;
	*/
public:
	static int proch;
	Payment();
	Payment(char *fio, float okl, int day, int month, int year);
	Payment(const Payment &a);
	~Payment();
	virtual int summa();
	int otchisl();
	int podoh();
	virtual char* show();
	friend Payment operator+(Payment a, int k);
	friend Payment operator-(Payment a, int k);
	Payment& operator++();
	Payment operator++(int);
	Payment& operator--();
	Payment operator--(int);
	int operator()();
	Payment& operator=(const Payment &a);
	friend std::istream& operator>> (std::istream& is, Payment &a);
	friend std::ostream& operator<< (std::ostream& os, Payment &a);
	friend std::ifstream& operator>> (std::ifstream& is, Payment &a);
	friend std::ofstream& operator<< (std::ofstream& os, Payment &a);
	std::ifstream& input(std::ifstream& is);
	std::ofstream& output(std::ofstream& os);

protected:
	char * FIO;
	float oklad;
	int dayv;
	int monv;
	int yearv;
	double ot;
	double p;
	double s;
};
