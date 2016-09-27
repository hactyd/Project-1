// Hamza Chaudhry, Niloofar Oliaei
// Dr. Mohammad Kuhail
// September 27, 2016
// Project 1B Polynomials

#pragma once
#include "Polynomial.h"

using namespace std;

class Menu {
private:
	list<Polynomial> _polynomials;
	Polynomial _poly;

public:
	Menu();
	~Menu();
	Polynomial UserInput();
	void DisplayMenu();
	Polynomial AddPolynomials();
};
