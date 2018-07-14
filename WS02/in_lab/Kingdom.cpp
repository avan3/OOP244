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
}
