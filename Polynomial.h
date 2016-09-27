// Hamza Chaudhry, Niloofar Oliaei
// Dr. Mohammad Kuhail
// September 27, 2016
// Project 1B Polynomials

#pragma once
#include <List>
#include <stack>
#include "Term.h"

class Polynomial {
private:
	std::stack<Term> termStack;
	std::list<Term> termList1;
	std::string polynomial;
	std::stack<char> signs;
	int Count;

public:
	Polynomial(std::string poly = "") {
		termList1 = std::list<Term>();
		signs = std::stack<char>();
		termStack = std::stack<Term>();
		polynomial = poly;
		Count = 0;
	}
	~Polynomial();
	Polynomial& operator=(Polynomial &rhs);
	void PolynomialSplitter();
	Term TermCombiner(const Term& t1, const Term& t2, char oper);
	std::list<Term> CombineLikeTerms();
	bool CharorNot(char c);
	bool SignorNot(char c);
	double GetDigits(std::string s, int &i);
	void Print();
	std::string GetPolynomial();
	std::string Output2String();
	int GetSplitCount();
	void Clear();
	void SetPolynomial(std::string s);
};
