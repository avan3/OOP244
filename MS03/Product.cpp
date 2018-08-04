#include "Product.h"

namespace AMA {
   void Product::name(const char* n) {
      productName = new char[max_name_length+1];
      strncpy(productName, n, max_name_length);
      productName[max_name_length] = '\0';
   }
   
   const char* Product::name() const {
      if (productName == '\0') { // May need to change this to isEmpty()
         return nullptr;
      }
      return productName;
   }

   const char* Product::sku() const {
      return productSku;
   }

   const char* Product::unit() const {
      return productDesc;
   }

   bool Product::taxed() const {
      return taxable;
   }

   double Product::price() const {
      return productPrice;
   }

   double Product::cost() const {
      if (taxed() == true) {
         return price() + (taxRate*price());
      }
      return price();
   }

   void Product::message(const char* eMessage) {
      errCode.message(eMessage);
   }

   bool Product::isClear() const {
      return errCode.isClear();
   }

   // Public Member Functions:
   Product::Product(char pType) {
      productType = pType;
      // Empty State:
      productName = '\0';
   }

   Product::Product(const char* sku, const char* pName, const char* unit, int hQty, bool tax, double bPrice, int nQty) {
      int size = strlen(sku);
      strncpy(productSku, sku, size);
      productSku[size] = '\0';
      size = strlen(unit);
      strncpy(productDesc, unit, size);
      productDesc[size] = '\0';
      name(pName);
      qtyOnHand = hQty;
      taxable = tax;
      productPrice = bPrice;
      qtyNeed = nQty;
   }

   Product::Product(const Product& src) {
      productName = nullptr;
      *this = src;
   }

   Product& Product::operator=(const Product& src) {
      if (this != &src) {
         qtyOnHand = src.quantity();
         qtyNeed = src.qtyNeeded();
         productPrice = src.price();
         taxable = src.taxed();
         delete [] productName;
         if (src.name() != nullptr) {
            name(src.name());
         }
         strncpy(productSku, src.sku(), max_sku_length);
         strncpy(productDesc, src.unit(), max_unit_length);
      }
	  return *this;
   }

   Product::~Product() {
      delete [] productName;
   }

   std::fstream& Product::store(std::fstream& file, bool newLine) const {
      if (file.is_open()) {
         file << productType << "," << productSku << "," << productName << ","
            << productDesc << "," << taxable << "," << productPrice << ","
            << qtyOnHand << "," << qtyNeed << ",";
      }
	   if (newLine == true) {
		   file << std::endl;
	   }
	   return file;
   }

   std::fstream& Product::load(std::fstream& file) {
	   Product tmp;
      char junk;
      if (file.is_open()) {
         file >> tmp.productType >> junk;
         file >> tmp.productSku >> junk;
         file >> tmp.productName >> junk;
         file >> tmp.productDesc >> junk;
         file >> tmp.taxable >> junk;
         file >> tmp.productPrice >> junk;
         file >> tmp.qtyOnHand >> junk;
         file >> tmp.qtyNeed;

         *this = tmp;
      }
	   return file;
   }

   std::ostream& Product::write(std::ostream& os, bool linear) const {
      if (linear == true) {
         os << std::fixed << std::setw(max_sku_length) << std::left << sku() << "|"
            << std::fixed << std::setw(20) << name() << "|"
            << std::fixed << std::right << std::setw(7) << std::setprecision(2) << cost() << "|"
            << std::fixed << std::setw(4) << quantity() << "|"
            << std::fixed << std::setw(10) << std::left << unit() << "|"
            << std::fixed << std::setw(4) << std::right << qtyNeeded() << "|";
      }
      else {
         os << "Sku: " << sku() << std::endl;
         os << "Name (no spaces): " << name() << std::endl;
         os << "Price: " << price() << std::endl;
         os << "Price after tax: " << cost() << std::endl;
         os << "Quantity on hand: " << quantity() << std::endl;
         os << "Quantity needed: " << qtyNeeded() << std::endl;
      }
	  return os;
   }

  std::istream& Product::read(std::istream& is) {
	   Product tmp;
      tmp.productName = new (std::nothrow) char[max_name_length+1];
      char taxed;
      std::cout << " Sku: ";
      is >> tmp.productSku;
      std::cout << " Name (no spaces): ";
      is >> tmp.productName;
      std::cout << " Unit: ";
      is >> tmp.productDesc;
      std::cout << " Taxed? (y/n): ";
      is >> taxed;
      if (taxed == 'y' || taxed == 'Y') {
			tmp.taxable = true;
      }
		else if (taxed == 'n' || taxed == 'N') {
			tmp.taxable = false;
		}
		else {
         this->message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}
      if (is.good()) {
         std::cout << " Price: ";
         is >> tmp.productPrice;
         if (is.fail()) {
            is.clear();
            is.ignore(2000, '\n');
            errCode.message("Invalid Price Entry");
         }
      }
      if (is.good()) {
         std::cout << " Quantity on hand: ";
         is >> tmp.qtyOnHand;
         if (is.fail()) {
            is.clear();
            is.ignore(2000, '\n');
            errCode.message("Invalid Quantity Entry");
         }
      }
      if (is.good()) {
         std::cout << " Quantity needed: ";
         is >> tmp.qtyNeed;
         if (is.fail()) {
            is.clear();
            is.ignore(2000, '\n');
            errCode.message("Invalid Quantity Needed Entry");
         }
      }
      if (this->isClear()) {
         *this = tmp;
      }
      delete [] tmp.productName;
      tmp.productName = nullptr;
	  return is;
   }

   bool Product::operator==(const char* str) const {
      if (sku() == str) {
         return true;
      }
      return false;
   }

   double Product::total_cost() const {
	   double total;
	   return total = cost() * quantity();
   }

   void Product::quantity(int no) {
      qtyOnHand = no;
   }

   bool Product::isEmpty() const {
      if (productName == '\0' || productName == nullptr) {
            return true;
      }
      return false;
   }

   int Product::qtyNeeded() const {
      return qtyNeed;
   }
   
   int Product::quantity() const {
      return qtyOnHand;
   }

   bool Product::operator>(const Product& src) const {
	   if (strcmp(this->name(), src.name()) > 0) {
		   return true;
	   }
	   return false;
   }

   bool Product::operator>(const char* sku) const {
	   if (strcmp(this->sku(), sku) > 0) {
		   return true;
	   }
	   return false;
   }

   int Product::operator+=(int unit) {
	   if (unit > 0) {
		   return qtyOnHand += unit;
	   }
	   return qtyOnHand;
	}

   // Helper Functions:
   std::ostream& operator<<(std::ostream& os, const Product& src) {
	   src.write(os, true);
	   return os;
   }

   std::istream& operator>>(std::istream& is, Product& src) {
	   src.read(is);
	   return is;
   }
   double operator+=(double& cost, const Product& src) {
	   return cost += src.total_cost();
   }
}