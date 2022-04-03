/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 24th July 2021
*/

/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.h
Version 2.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/23  Preliminary release
2020/07/24  A new function named set_name added
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include"IOAble.h"
#include"Ticket.h"
#include"Time.h"
namespace sdds {
	class Patient :public IOAble {
		Time* T;
		char* name;
		int ohip;
		Ticket tic;
		bool flag;
		void set_name(string str1);
	public:
		Patient(int number=0,bool value=false);
		Patient(const Patient& pat) = delete;
		Patient& operator=(const Patient& pat) = delete;
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool);
		bool operator==(char)const;
		bool operator==(const Patient& pat)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;

		virtual ostream& csvWrite(ostream& os) const;
		virtual istream& csvRead(istream& in) ;
		virtual ostream& write(ostream& os)const;
		virtual istream& read(istream& in);

	};
}
#endif