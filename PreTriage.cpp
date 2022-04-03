/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 3rd August 2021
*/

/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include<cstring>
#include"PreTriage.h"
#include"utils.h"
#include"CovidPatient.h"
#include"TriagePatient.h"
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) :m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
		if (m_dataFilename != nullptr) delete[]m_dataFilename;
		int len = strlen(dataFilename);
		m_dataFilename = new char[len + 1];
		strcpy(m_dataFilename, dataFilename);
		m_dataFilename[len] = '\0';
		load();
	}
	PreTriage::~PreTriage() {
		int i = 0;
		ofstream csv_file(m_dataFilename);
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: ";
		m_averCovidWait.write(csv_file);
		csv_file << ",";
		m_averCovidWait.write(cout) << endl;
		cout << "   Triage: ";
		m_averTriageWait.write(csv_file) << endl;
		m_averTriageWait.write(cout) << endl;
		cout << "Saving m_lineup..." << endl;
		while (i < m_lineupSize)
		{
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout) << endl;
			m_lineup[i]->csvWrite(csv_file) << endl;
			i++;
		}
		for (i = 0; i < m_lineupSize; i++) delete m_lineup[i];
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		cout << "done!\n";
	}
	const Time PreTriage::getWaitTime(const Patient& p)const {
		int count = 0;
		unsigned avg;
		for (int i = 0; i < m_lineupSize; i++)
			if (p.type() == m_lineup[i]->type())
				count++;
		if (p.type() == 'C')
			avg = count * m_averCovidWait.operator int();
		else
			avg = count * m_averTriageWait.operator int();

		return avg;
	}
	void PreTriage::setAverageWaitTime(const Patient& p) {
		if (p.type() == 'C') {
			m_averCovidWait = ((getTime() - int(Time(p))) + int(m_averCovidWait) * (p.number() - 1)) / p.number();
		}
		else if (p.type() == 'T')
			m_averTriageWait = ((getTime() - int(Time(p))) + int(m_averTriageWait) * (p.number() - 1)) / p.number();
	}
	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	int PreTriage::indexOfFirstInLine(char type) const {
		int index = -2;
		for (int i = 0; i < m_lineupSize && index == -2; i++) {
			if (m_lineup[i]->type() == type) {
				index = i;
			}
		}
		if (index == -2)
			index = -1;
		return index;
	}
	void PreTriage::load() {
		char ch;
		bool valid = false;
		cout << "Loading data..." << endl;
		Patient* pat = nullptr;
		ifstream input(m_dataFilename);
		input >> m_averCovidWait;
		input.ignore();
		input >> m_averTriageWait;
		input.ignore(1000, '\n');

		for (int i = 0; i < maxNoOfPatients && input.peek() != EOF; i++) {
			input >> ch;
			input.ignore();
			if (ch == 'C') {
				valid = true;
				pat = new CovidPatient();

			}
			else if (ch == 'T') {
				valid = true;

				pat = new TriagePatient();
			}
			if (valid) {
				pat->fileIO(true);
				pat->read(input);
				pat->fileIO(false);
				m_lineup[i] = pat;
				m_lineupSize++;
			}
		}
		if (m_lineupSize >= 100) {
			cout << "Warning: number of records exceeded 100" << endl;
			cout << m_lineupSize << " Records imported...\n" << endl;
		}
		else if (m_lineupSize == 0)
			cout << "No data or bad data file!\n" << endl;
		else
			cout << m_lineupSize << " Records imported...\n" << endl;
	}
	void PreTriage::reg() {
		int terminate = 0;
		if (m_lineupSize == maxNoOfPatients)
			cout << "Line up full!" << endl;
		else {
			int select = m_pMenu.operator>>(select);
			if (select == 1) {
				m_lineup[m_lineupSize] = new CovidPatient;
			}
			else if (select == 2) {
				m_lineup[m_lineupSize] = new TriagePatient;
			}
			else if (select == 0)
				terminate = 1;
			if (!terminate) {
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: \n";
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(cin);
				cout << "\n******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************\n\n";
			}
			m_lineupSize++;
		}
	}
	void PreTriage::admit() {
		int select = m_pMenu.operator>>(select);
		int index = -1;
		if (select != 0) {
			if (select == 1)
				index = indexOfFirstInLine('C');
			else if (select == 2)
				index = indexOfFirstInLine('T');
			if (index != -1) {
				cout << "\n******************************************\n";
				m_lineup[index]->fileIO(false);
				cout << "Calling for ";
				m_lineup[index]->write(cout);
				cout << "******************************************\n\n";
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}

		}
	}
	void PreTriage::run(void) {
		int valid;
		do {
			int select = m_appMenu.operator>>(select);
			if (select == 1) {
				reg();
				valid = 1;
			}
			else if (select == 2) {
				admit();
				valid = 1;
			}
			else
				valid = 0;
		} while (valid);
	}
}