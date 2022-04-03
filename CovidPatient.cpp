/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 24th July 2021
*/

/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#include"CovidPatient.h"
#include<iostream>
#include<cstring>
#include<string>
namespace sdds {
   int nextCovidTicket = 1;
   
   CovidPatient::CovidPatient():Patient(nextCovidTicket) {
	   nextCovidTicket++;
   }

   char CovidPatient::type()const {
	   return 'C';
   }

   istream& CovidPatient::csvRead(istream& in) {
	   Patient::csvRead(in);
	   nextCovidTicket = number() + 1;
	   in.ignore();
	   return in;
	}

	 ostream& CovidPatient::write(ostream& os)const {
	   if (fileIO())
		   Patient::csvWrite(os);
	   else
	   {
		   os << "COVID TEST" << endl;
		   Patient::write(os) << endl;
	   }
	   return os;
   }

	 istream& CovidPatient::read(istream& in) {
		 if (fileIO())
			 csvRead(in);
		 else
			 Patient::csvRead(in);
		 return in;
	 }
   
}