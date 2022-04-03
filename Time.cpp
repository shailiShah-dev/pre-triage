/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 12th July 2021
*/

/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include<iomanip>
#include "Time.h"
#include "utils.h"

#define MINUTES 60
#define HOURS 24
using namespace std;
namespace sdds {

	Time& Time::setToNow() {
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		int mins,hours;
		mins = m_min % MINUTES;
		hours = m_min / MINUTES;
		
		ostr <<setw(2)<< setfill('0') << hours << ":" << setw(2) << setfill('0') << mins;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		int i, j = {};
		char ch = {};
		istr >> i >> ch >> j;
		if (ch != ':')
			istr.setstate(ios::failbit);
		else if (i < 0 || j < 0)
			istr.setstate(ios::failbit);
		else {
			m_min = (i * MINUTES) + j;
		}

		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		
		while (m_min < D.m_min) {
			m_min += (HOURS * MINUTES);
		}

		m_min -= D.m_min;

		return*this;
	}

	Time Time::operator-(const Time& D)const {
		Time obj;
		obj.m_min = this->m_min;

		while (obj.m_min < D.m_min) {
			obj.m_min += (HOURS * MINUTES);
		}

		obj.m_min -= D.m_min;

		return obj;
	}

	Time& Time::operator+=(const Time& D) {
		this->m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const {
		Time obj;
		obj.m_min = this->m_min + D.m_min;
		return obj;
	}

	Time& Time::operator=(unsigned int val) {
		this->m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val) {
		this->m_min *= val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const {
		Time obj;
		obj.m_min = this->m_min * val;
		return obj;
	}

	Time& Time::operator /= (unsigned int val) {
		this->m_min /= val;
		return *this;
	}

	Time Time::operator /(unsigned int val)const {
		Time obj;
		obj.m_min = this->m_min / val;
		return obj;
	}

	Time::operator int()const {
		int mins = m_min;
		return mins;
	}

	Time::operator unsigned int()const {
		unsigned mins = m_min;
		return mins;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D) {
		D.read(istr);
		return istr;
	}

}