#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <fstream>
#include <cstring>
#include "ErrorState.h"
#include "iProduct.h"

namespace AMA {
   const int max_sku_length = 7;
   const int max_unit_length = 10;
   const int max_name_length = 75;
   const double taxRate = 0.13;
   class Product : public iProduct {
   private:
      char productType;
      char productSku[max_sku_length+1];
      char productDesc[max_unit_length+1];
      char * productName;
      int qtyOnHand;
      int qtyNeed;
      double productPrice;
      bool taxable;
      ErrorState errCode; 
   protected:
      void name(const char*);
      const char* name() const;
      const char* sku() const;
      const char* unit() const;
      bool taxed() const;
      double price() const;
      double cost() const;
      void message(const char*);
      bool isClear() const;
   public:
      Product(char pType = 'N');
      Product(const char*, const char*, const char*, int qty = 0, bool tax = true, double bPrice = 0.0, int nQty = 0);
      Product(const Product&);
      Product& operator=(const Product&);
      ~Product();
      std::fstream& store(std::fstream& file, bool newLine=true) const;
      std::fstream& load(std::fstream& file);
      std::ostream& write(std::ostream& os, bool linear) const;
      std::istream& read(std::istream& is);
      bool operator==(const char*) const;
      double total_cost() const; // Where do you get total cost?
      void quantity(int);
      bool isEmpty() const;
      int qtyNeeded() const;
      int quantity() const;
      bool operator>(const char*) const;
      bool operator>(const iProduct&) const;
      int operator+=(int);
   };
   std::ostream& operator<<(std::ostream&, const iProduct&);
   std::istream& operator>>(std::istream&, iProduct&);
   double operator+=(double&, const iProduct&);
}
#endif