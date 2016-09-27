// Hamza Chaudhry, Niloofar Oliaei
// Dr. Mohammad Kuhail
// September 27, 2016
// Project 1B Polynomials

#pragma once
#include <iostream>
#include <string>
using namespace std;
class Term 
{
private:
	double  coefficient, exponent;
	char var, sign;
	bool _FirstorNot;

public:
	Term(double exp = 1, double coeff = NULL, char var = '-');
	~Term();
	double GetExp();
	void SetExp(double exp);
	double GetCoefficient();
	void SetCoefficient(double coeff);
	char GetVar();
	void SetVar(char v);
	char GetSigns();
	void SetSigns(char sign);
	bool DoubleNegativeorNot();
	bool FirstorNot();
	void SetFirst();

	
	

	Term& operator=(const Term& rhs);
	friend bool operator>(const Term& lhs, const Term& rhs);
	friend bool operator<(const Term& lhs, const Term& rhs);
	friend bool operator==(const Term& lhs, const Term& rhs);
	friend Term& operator+(const Term lhs, const Term&rhs);
	friend Term& operator-(const Term lhs, const Term&rhs);
	friend Term& operator*(const Term lhs, const Term&rhs);
	friend Term& operator/(const Term lhs, const Term&rhs);
	friend std::ostream& operator<<(std::ostream& out, Term& rhs);
	friend std::istream& operator>>(std::istream& in, Term& rhs);

};
