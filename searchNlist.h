/*
  Name: Shaili Bharatkumar Shah
  Email: sbshah6@myseneca.ca
  Student ID: 139046205
  Date of completion: 26th July 2021
*/

#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H

#include<iostream>
#include"Collection.h"

using namespace std;

namespace sdds {
	template<typename T, typename V>
	bool search(Collection<T>& collection, T arr[], int len, V check)
	{
		bool valid = false;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == check)
			{
				collection.add(arr[i]);
				valid = true;
			}
		}
		return valid;
	}

	template<typename T>
	void listArrayElements(const char* heading, const T arr[], int len)
	{
		cout << heading << endl;
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << ": " << arr[i] << endl;
		}
	}
}

#endif // !SDDS_SEARCHNLIST_H

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/