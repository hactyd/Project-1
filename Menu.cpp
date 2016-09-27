// Hamza Chaudhry, Niloofar Oliaei
// Dr. Mohammad Kuhail
// September 27, 2016
// Project 1B Polynomials

#include "Menu.h"

Menu::Menu() {
	list<Polynomial> _polynomials = list<Polynomial>();
}

//Function for displaying menu:
void Menu::DisplayMenu() {
	
	cout << endl << " Welcome to the Polynomial adder!" << endl << endl << endl;
	cout << "enter a polynomial ex: Ax^n - Bx^n + c " << endl;
	cout << "No paranthesis allowed!" << endl << endl;
	cout << endl << endl;
	_polynomials.push_back(UserInput());
	cout << endl << "Enter a polynomial: " << endl;

	//A loop that lets the user add as many polynomials as they want to the list 
	bool another = true;
	while (another) {
		_polynomials.push_back(UserInput());
		cout << "Would you like to type another polynomial?" << endl;
		cout << "Enter Y/N: ";

		string input;
		getline(cin, input);
		if (input == "Y" || input == "y" || input == "yes" || input == "Yes")
			another = true;
		else {
			another = false;
		}
	}

	//Displays and calls functions to add polynomials
	cout << endl;
	_poly = AddPolynomials();
	while (_poly.GetSplitCount() < _poly.GetPolynomial().size() * 2) //parses based on size of poly string to insure all terms are checked
		_poly.PolynomialSplitter();
	cout << "The result: [ ";
	_poly.Print();
	cout << " ] " << endl;
}

Menu::~Menu() {
	_polynomials.clear();
}

Polynomial Menu::AddPolynomials() { //Calls functions to combine polynomials that the user entered by iterating through the list

	string CombinedString;
	for (list<Polynomial>::iterator i = _polynomials.begin(); i != _polynomials.end(); i++) {
		if (i->GetPolynomial() == "") //skips empty items
			continue;
		i->PolynomialSplitter();
		CombinedString.append(i->Output2String());
		CombinedString.append("+");
		cout << " [ ";
		i->Print();
		cout << " ] ";
		if (i._Ptr->_Next == _polynomials.end()._Ptr)
			break;
		cout << " [ + ] "; 
	}
	cout << endl << endl;;
	Polynomial tempPoly = Polynomial(CombinedString);
	tempPoly.PolynomialSplitter();

	return tempPoly;
}
Polynomial Menu::UserInput() { 
	//makes the user to enter a polynomial and stores it

	string poly;
	cout << "Please enter a polynomial: ";
	getline(cin, poly);

	Polynomial tempPoly = Polynomial(poly);
	cout << endl << "You entered: ";
	while (tempPoly.GetSplitCount() < poly.size()) 
		//this calls the parse method several times
		tempPoly.PolynomialSplitter();
	tempPoly.Print();
	cout << endl;
	return tempPoly;
}
