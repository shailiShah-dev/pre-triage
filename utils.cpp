/*
*  Name: Shaili Bharatkumar Shah
*  ID:139026405
*  Mail: sbshah6@myseneca.ca
*  Date of completion: 12th July 2021
*/

/* Citation and Sources...
Final Project Milestone 1
Module: 1
Filename: utils.cpp
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/19  Upgraded version
2020/07/19  Changed the getInt function's if condition
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(
        const char* prompt) {   // User entry prompt
        if (prompt) {
            cout << prompt;
        }

        int value;
        int valid = 0;
        do
        {
            cin >> value;

            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');

                valid = 0;
            }
            else if (cin.peek() == '\n')
            {
                valid = 1;

            }
            else {
                cout << "Enter only an integer, try again: ";
            }



        } while (valid == 0);
        return value;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
        int i = 0;
        int valid = 0;
        int value;
        do {
            if (!i)
                value = getInt(prompt);
            else
                value = getInt();

            if (!(value >= min && value <= max)) {

                cout << errorMessage;
                if (showRangeAtError)
                    cout << "[" << min << " <= value <= " << max << "]: ";

            }
            else
            {
                valid = 1;
            }
            i++;
        } while (!valid);
        return value;
    }

    char* getcstr(
        const char* prompt,   // User entry prompt
        std::istream& istr,  // the Stream to read from
        char delimiter    // Delimiter to mark the end of data
    ) {
        string str;
        if (prompt)
            cout << prompt;
        cin.clear();
        cin.ignore(1000, '\n');
        getline(istr, str, delimiter);
        int len = str.length();
        char* cstr = new char[len + 1];
        strcpy(cstr, str.c_str());
        return cstr;
    }




}

