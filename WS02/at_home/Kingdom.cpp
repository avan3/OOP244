/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 23, 2018
// Author Andrew Van
// Description
// OOP244 Section B
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

// TODO: the sict namespace
using namespace std;
// TODO:definition for display(...) 
namespace sict {
   void display(const Kingdom &kingdom) {
      cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
   }
   void display(const Kingdom * kingdom, int size) {
      int i;
      int total = 0;
      cout << "------------------------------" << endl;
      cout << "Kingdoms of SICT" << endl;
      cout << "------------------------------" << endl;
      for (i = 0; i < size; i++) {
         total += kingdom[i].m_population;
         cout << i + 1 << ".";
         display(kingdom[i]);
      }
      cout << "------------------------------" << endl;
      cout << "Total population of SICT: " << total << endl;
   }
}
