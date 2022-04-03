/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 24th July 2021
*/

/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include"TriagePatient.h"
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient() :Patient(nextTriageTicket) {
	   symptoms = nullptr;
	   nextTriageTicket++;
   }

   char TriagePatient::type()const {
	   return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& os) const {
	   Patient::csvWrite(os);
	   os << "," << symptoms;
	   return os;
   }

   istream& TriagePatient::csvRead(istream& in) {
	   delete[] symptoms;
	   Patient::csvRead(in);
	   in.ignore();
	   string str;
	   getline(in, str, '\n');
	   int len = str.length();
	   symptoms = new char[len + 1];
	   strcpy(symptoms, str.c_str());
	   symptoms[len] = '\0';
	   nextTriageTicket = number() + 1;
	   return in;
   }

   ostream& TriagePatient::write(ostream& os)const {
	   if (fileIO())
		   csvWrite(os);
	   else
	   {
		   os << "TRIAGE" << endl;
		   Patient::write(os);
		   os << "\nSymptoms: " << symptoms << endl;
	   }
	   return os;
   }

   istream& TriagePatient::read(istream& in) {
	   if (fileIO())
		   csvRead(in);
	   else {
		   string str;
		   delete[] symptoms;
		   Patient::read(in);
		   cout << "Symptoms: ";
		   in.ignore();
		   getline(in, str, '\n');
		   int len = str.length();
		   symptoms = new char[len + 1];
		   strcpy(symptoms, str.c_str());
		   symptoms[len] = '\0';
	   }
	   return in;
   }
   
   TriagePatient::~TriagePatient() {
	   delete[]symptoms;
	}

}