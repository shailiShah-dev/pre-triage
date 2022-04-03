/*
  Name: Shaili Bharatkumar Shah
  Email: sbshah6@myseneca.ca
  Student ID: 139046205
  Date of completion: 26th July 2021
*/

// Workshop 9:
// ReadWrite.cpp
// 2021-06-03
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/