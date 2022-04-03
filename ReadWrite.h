/*
  Name: Shaili Bharatkumar Shah
  Email: sbshah6@myseneca.ca
  Student ID: 139046205
  Date of completion: 26th July 2021
*/

// Workshop 9:
// ReadWrite.h
// 2021-06-03
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class ReadWrite {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
      virtual ~ReadWrite() {
      }
   };
   std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
   std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
