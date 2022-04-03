#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include"cstring"
#include "utils.h"

using namespace std;
namespace sdds {
	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		int len = strlen(MenuContent);
			m_text = new char[len + 1];
			strcpy(m_text, MenuContent);
			m_text[len] = '\0';
			m_noOfSel = NoOfSelections;
		
	}

	Menu::~Menu() {
		delete[] m_text;
	}

	void Menu::display()const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		Selection=getInt(0,m_noOfSel,"> ","Invalid option ");
		return Selection;

	}

	Menu::Menu(const Menu& m) {
		
		m_noOfSel = m.m_noOfSel;
		if (m.m_text ) {
			
			int len = strlen(m.m_text);
			m_text = new char[len+1];
			strcpy(m_text, m.m_text);
			m_text[len] = '\0';
		}

	}

}

