/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 24th July 2021
*/

/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include <iostream>
#include"Patient.h"
namespace sdds {
	class TriagePatient :public Patient {
		char* symptoms;
	public:
		TriagePatient();
		virtual char type()const;
		virtual ostream& csvWrite(ostream& os) const;
		virtual istream& csvRead(istream& in);
		virtual ostream& write(ostream& os)const;
		virtual istream& read(istream& in);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


