// Hamza Chaudhry, Niloofar Oliaei
// Dr. Mohammad Kuhail
// September 27, 2016
// Project 1B Polynomials

#include "Polynomial.h"
#include <sstream>


using namespace std;

Polynomial::~Polynomial() {
	Clear();
}

void Polynomial::PolynomialSplitter() {
	double d;

	for (int i = 0; i <= polynomial.length(); i++) {
		if (polynomial[i] == ' ') //handles whitespace
			continue;

		Term temp_term;
		if (!signs.empty()) { 
			temp_term.SetSigns(signs.top());
			signs.pop();
		}
		if (isdigit(polynomial[i])) { //sets coefficient 
			d = GetDigits(polynomial, i);
			temp_term.SetCoefficient(d);
		}
		if (CharorNot(polynomial[i])) { //sets variable
			if (temp_term.GetCoefficient() == NULL)
				temp_term.SetCoefficient(1);
			temp_term.SetVar(polynomial[i]);
			i++;
		}
		if (polynomial[i] == '^') { //if there is an exponent 
			bool positive = true;
			i++;
			if (!isdigit(polynomial[i])) { //if it's an operator, set sign for exponent
				positive = false;
				i++;
			}
			d = GetDigits(polynomial, i); //get the number of the exponent
			if (!positive)
				d = d*-1;
			temp_term.SetExp(d);
		}
		if (SignorNot(polynomial[i])) { //if there is an operator, add it to the stack
			signs.push(polynomial[i]);
		}
		if (temp_term.GetCoefficient() != 0)
			termStack.push(temp_term); //add the term to the stack
	}

	termList1 = CombineLikeTerms(); //combine common terms
	termList1.sort();
	polynomial = Output2String();
	termList1.back().SetFirst(); //The last item is set as first because it's actually the first term that gets outputted
	Count++;
}

double Polynomial::GetDigits(string s, int &i) { //will loop until all of the digits in a group are acquired
	double a, d = 0;
	int count = 0;
	while (isdigit(s[i])) {
		istringstream ss(&s[i]);
		ss >> a;
		d += a;
		i++;
		count++;
		if (count > 1)
			d -= a;
	}

	return d;
}

list<Term> Polynomial::CombineLikeTerms() { //The main function that decides which polynomials should be added together
	list<Term> new_terms = list<Term>();
	while (termStack.empty()) { //if the stack isn't empty pop the first two items
		Term i = termStack.top();
		termStack.pop();
		if (!termStack.empty()) {
			Term j = termStack.top();
			termStack.pop();

			if (j == i) { //if the two terms are alike, combine them and push the result to the top of the stack and loop again
				termStack.push(TermCombiner(i, j, '+')); //addes the terms
				continue;
			}
			else {
				new_terms.push_back(i); //add the first term to a list and push the second one back in the stack
				termStack.push(j);
			}
		}
		else {
			new_terms.push_back(i);
		}
	}
	return new_terms;
}

Term Polynomial::TermCombiner(const Term& a, const Term& b, char oper) { 
	//combines two terms together
	Term new_term;
	if (oper == '+')
		//all terms are just added togther, but this function supports the other operations as well
		new_term = a + b;
	else if (oper == '-')
		new_term = a - b;
	else if (oper == '*')
		new_term = a * b;
	else
		new_term = a / b;
	return new_term;
}

bool Polynomial::CharorNot(char c) { 
	//checks if there is a variable
	if (c == 'x' || c == 'X')
		return true;
	return false;
}

bool Polynomial::SignorNot(char c) { 
	//returns true if the character is an operator
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void Polynomial::Print() { 
	//iterates through list and prints results to standard output
	for (list<Term>::reverse_iterator i = termList1.rbegin(); i != termList1.rend(); i++) {
		if ((*i).GetCoefficient() != 0)
			cout << *i;
	}
}


//Get set etc

void Polynomial::SetPolynomial(string s) {
	Clear();
	polynomial = s;
}

string Polynomial::GetPolynomial() {
	return polynomial;
}

int Polynomial::GetSplitCount() {
	return Count;
}

string Polynomial::Output2String() { //returns the output of the class as a string
	stringstream out;
	for (list<Term>::reverse_iterator i = termList1.rbegin(); i != termList1.rend(); i++) {
		if ((*i).GetCoefficient() != 0)
			out << *i;
	}
	return out.str();
}

//overloads

Polynomial& Polynomial::operator=(Polynomial& rhs) {
	if (this != &rhs) {

		while (!termStack.empty())
			termStack.pop();
		while (!signs.empty())
			signs.pop();
		termList1.clear();

		termList1 = rhs.termList1;
		termStack = rhs.termStack;
		signs = rhs.signs;
		polynomial = rhs.polynomial;

	}
	return *this;
}
//other
void Polynomial::Clear() {
	while (!termStack.empty())
		termStack.pop();
	while (!signs.empty())
		signs.pop();
	termList1.clear();
}
