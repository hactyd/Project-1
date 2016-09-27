// Hamza Chaudhry, Niloofar Oliaei
// Dr. Mohammad Kuhail
// September 27, 2016
// Project 1B Polynomials

#include "Term.h"

Term::Term(double exp, double coeff, char var) {
	coefficient = coeff;
	var = var;
	exponent = exp;
	sign = '+';
	_FirstorNot = false; //whether this is the first polynomial in the list or not
	if (exponent == 0) {
		var = '-';
		exponent = 1;
	}
}

Term::~Term() {
	//destructor
}
Term& Term::operator=(const Term& rhs) {
	if (&rhs != this) {
		coefficient = rhs.coefficient;
		var = rhs.var;
		exponent = rhs.exponent;
		sign = rhs.sign;
		_FirstorNot = rhs._FirstorNot;
	}
	return *this;
}
//Overloading operators
Term& operator-(const Term lhs, const Term& rhs)
{
	Term new_term = Term(lhs.coefficient - rhs.coefficient, lhs.var, lhs.exponent);
	return new_term;
}
Term& operator+(const Term lhs, const Term& rhs)
{
	Term new_term = Term(lhs.coefficient + rhs.coefficient, lhs.var, lhs.exponent);
	return new_term;
}
Term& operator/(const Term lhs, const Term& rhs)
{
	Term new_term = Term(lhs.coefficient / rhs.coefficient, lhs.var, lhs.exponent / rhs.exponent);
	return new_term;
}

Term& operator*(const Term lhs, const Term& rhs)
{
	Term new_term = Term(lhs.coefficient * rhs.coefficient, lhs.var, lhs.exponent * rhs.exponent);
	return new_term;
}

std::ostream& operator<<(std::ostream& out, Term& rhs) {
	if (!rhs.DoubleNegativeorNot() && !rhs.FirstorNot()) {
		//so there are no double negatives in the output
		if (rhs.coefficient>0) 
			//no plus sign for negative positives
			out << rhs.sign;
	}
	if ((rhs.coefficient != 1 || rhs.var == '-') && rhs.coefficient != NULL) { 
		out << rhs.GetCoefficient();
	}
	if (rhs.var != '-') {
		out << rhs.GetVar();
	}
	if (rhs.exponent != 1 && rhs.exponent != 0) { 
		out << "^" << rhs.exponent;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Term& rhs) {
	in >> rhs.coefficient >> rhs.var >> rhs.exponent;
	return in;
}

bool operator>(const Term& lhs, const Term& rhs) {
	if (lhs.exponent > rhs.exponent) {
		return true;
	}
	else if (lhs.exponent < rhs.exponent) {
		return false;
	}
	else {
		if (lhs.coefficient > rhs.coefficient) {
			if (lhs.var == rhs.var)
				return true;
			else if (lhs.var == '-' && rhs.var != '-')
				return false;
			else
				return true;
		}
		else if (lhs.coefficient == rhs.coefficient) {
			if (lhs.var == rhs.var)
				return false;
			else if (lhs.var != '-' && rhs.var == '-')
				return true;
			else
				return false;
		}
		else {
			if (lhs.var != '-' && rhs.var == '-')
				return true;
		}
	}
	return false;
}

bool operator<(const Term& lhs, const Term& rhs) {
	if (lhs.exponent > rhs.exponent) {
		return false;
	}
	else if (lhs.exponent < rhs.exponent) {
		return true;
	}
	else {
		if (lhs.coefficient > rhs.coefficient) {
			if (lhs.var == rhs.var)
				return false;
			else if (lhs.var == '-' && rhs.var != '-')
				return true;
			else
				return false;
		}
		else if (lhs.coefficient == rhs.coefficient) {
			if (lhs.var == rhs.var)
				return false;
			else if (lhs.var != '-' && rhs.var == '-')
				return false;
			else
				return true;
		}
		else {
			if (lhs.var != '-' && rhs.var == '-')
				return false;
		}
	}
	return false;
}

bool operator==(const Term& lhs, const Term& rhs) {
	if (lhs.exponent == rhs.exponent && lhs.var == rhs.var)
		return true;
	return false;
}

//Getters and Setters

void Term::SetCoefficient(double coeff) {
	if (sign == '-')
		coefficient = coeff*-1;
	else
		coefficient = coeff;
}

void Term::SetVar(char var) {
	var = var;
}

void Term::SetExp(double exp) { 
	//sets exponent 
	exponent = exp;
	if (exp == 0) {
		var = '-';
		exponent = 1;
	}
}
char Term::GetSigns() {
	return sign;
}

void Term::SetSigns(char sign) {
	sign = sign;
}

double Term::GetCoefficient() {
	return coefficient;
}

double Term::GetExp() {
	return exponent;
}

char Term::GetVar() {
	return var;
}



bool Term::DoubleNegativeorNot() {
	if (coefficient < 0 && sign == '-')
		return true;
	else
		return false;
}

bool Term::FirstorNot() {
	return _FirstorNot;
}

void Term::SetFirst() {
	_FirstorNot = true;
}
