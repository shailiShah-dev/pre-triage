/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 12th July 2021
*/
/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 2.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_ABLE_H
#define SDDS_ABLE_H
#include <iostream>
#include<cstring>
using namespace std;
namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& os ) const=0 ;
		virtual istream& csvRead(istream& in)=0 ;
		virtual ostream& write(ostream& os)const=0;
		virtual istream& read(istream& in) = 0;
		virtual ~IOAble(){};
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& D);
	std::istream& operator>>(std::istream& istr, IOAble& D);
}
#endif // !SDDS_ABLE_H