/*
* Name: Shaili Bharatkumar Shah
* ID: 139046205
* mail: sbshah6@myseneca.ca
* Date of completion: 23rd July 2021
*/

/* Citation and Sources...
Final Project Milestone 3
Module: Ticket
Filename: Ticket.h
Version 1.0
Author	Shaili Shah
Revision History
-----------------------------------------------------------

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
      Ticket(int number);
      operator Time()const;
      int number()const;
      void resetTime();
      std::ostream& csvWrite(std::ostream& ostr)const;
      std::istream& csvRead(std::istream& istr);
      std::ostream& write(std::ostream& ostr )const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SDDS_TICKET_H_
