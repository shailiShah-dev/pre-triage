/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 12th July 2021
*/

/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "IOAble.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const IOAble& D) {
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, IOAble& D) {
		D.read(istr);
		return istr;
	}
}