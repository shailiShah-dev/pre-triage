/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 24th July 2021
*/

/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.cpp
Version 2.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/23  Preliminary release
2020/07/24  A new function named set_name added
2020/07/24  condition added in csvRead function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iomanip>
#include<string>
#include"utils.h"
#include"Patient.h"
#include"Ticket.h"
#include"Time.h"
namespace sdds {
	Patient::Patient(int number, bool value):tic(number) {
		name = nullptr;
		ohip = 0;
		flag = value;
	}

	Patient::~Patient() {
		delete[] name;
	}

	void Patient::set_name(string str1) {
		int len = strlen(str1.c_str());
		delete[] name;
		name = new char[len + 1];
		strcpy(name, str1.c_str());
		name[len] = '\0';
	}
	
	bool Patient::fileIO()const {
		return flag;
	}
	void Patient::fileIO(bool value) {
		flag = value;
	}
	bool Patient::operator==(char ch)const {
		return type() == ch ? true : false;
	}
	bool Patient::operator==(const Patient& pat)const {
		return this->type() == pat.type() ? true : false;
	}
	void Patient::setArrivalTime() {
		tic.resetTime();
	}
	Patient::operator Time()const {
		return tic.operator sdds::Time();
	}
	int Patient::number()const {
		return tic.number();
	}

	ostream& Patient::csvWrite(ostream& os) const {
		os << type() << "," << name << "," << ohip << ",";
		tic.csvWrite(os);
		return os;
	}
	
	istream& Patient::csvRead(istream& in) {
		string str;
		if (fileIO()) {
			getline(in, str, ',');
			set_name(str);
			in >> ohip;
			in.ignore(1000, ',');
			tic.csvRead(in);
		}
		else {
			cout << "Name: ";
			getline(in, str, '\n');
			set_name(str);
			cout << "OHIP: ";
			in >> ohip;
			in.ignore();
		}
		return in;
	}

	ostream& Patient::write(ostream& os)const {
		os << tic << endl;
		int len = strlen(name);
		if(len>25)
			os<<string(&name[0]).substr(0,25)<< ", OHIP: " << ohip;
		else
		os << left << name << ", OHIP: " << ohip;
		return os;
	}

	istream& Patient::read(istream& in) {
		cout << "Name: ";
		string str;
		getline(in, str, '\n');
		set_name(str);
		cout << "OHIP: ";
		ohip = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);
		return in;
	}
		
}