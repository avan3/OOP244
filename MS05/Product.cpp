#include <string>
#include "Product.h"

namespace AMA {
   // Modifier that allocates memory and sets the name of the object from the argument
   void Product::name(const char* n) {
      productName = new char[max_name_length+1];
      strncpy(productName, n, max_name_length);
      productName[max_name_length] = '\0';
   }

   // Query that returns the product name is there is one   
   const char* Product::name() const {
      if (this->isEmpty()) { // May need to change this to isEmpty()
         return nullptr;
      }
      return productName;
   }

   // Query to return the product Sku
   const char* Product::sku() const {
      return productSku;
   }

   // Query to return the product Unit
   const char* Product::unit() const {
      return productDesc;
   }

   // Query to return the taxable state of the product
   bool Product::taxed() const {
      return taxable;
   }

   // Query to return the product price
   double Product::price() const {
      return productPrice;
   }

   // Query to return the product cost with tax or without
   double Product::cost() const {
      if (taxed() == true) {
         return price() + (taxRate*price());
      }
      return price();
   }

   // Modifier to set the error message of the product object
   void Product::message(const char* eMessage) {
      errCode.message(eMessage);
   }

   // Query to check the state of the ErrorState object
   bool Product::isClear() const {
      return errCode.isClear();
   }

   // Public Member Functions:
   // Constructor that initializes the product type
   Product::Product(char pType) {
      productType = pType;
      // Empty State:
      productName = '\0';
   }

   // Constructor that initializes the product information 
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

   // Copy Constructor - Calls the copy assignment operator
   Product::Product(const Product& src) {
      productName = nullptr;
      *this = src;
   }

   // Copy assignment operator
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

   // Destructor:
   Product::~Product() {
      delete [] productName;
   }

   // Store the product information into a file
   std::fstream& Product::store(std::fstream& file, bool newLine) const {
      if (file.is_open()) {
         file << productType << "," << productSku << "," << productName << ","
            << productDesc << "," << taxable << "," << productPrice << ","
            << qtyOnHand << "," << qtyNeed;
      }
	   if (newLine == true) {
		   file << std::endl;
	   }
	   return file;
   }

   // Load the product information from the file and store into tmp object and then save to current object
   std::fstream& Product::load(std::fstream& file) {
	   Product tmp;
      tmp.productName = new (std::nothrow) char[max_name_length + 1];
      char junk;
      if (file.is_open()) {
         file.getline(tmp.productSku, max_sku_length, ',');
         file.getline(tmp.productName, max_name_length, ',');
         file.getline(tmp.productDesc, max_unit_length, ',');
         file >> tmp.taxable >> junk;
         file >> tmp.productPrice >> junk;
         file >> tmp.qtyOnHand >> junk;
         file >> tmp.qtyNeed;

         *this = tmp;
      }
      delete[] tmp.productName;
      tmp.productName = nullptr;
	   return file;
   }

   // Write to the output stream the product information linearly or not
   std::ostream& Product::write(std::ostream& os, bool linear) const {
      if (this->isClear()) {
         if (linear == true) {
            os << std::fixed << std::setfill(' ') << std::setw(max_sku_length) << std::left << sku() << "|"
               << std::fixed << std::setw(20) << name() << "|"
               << std::fixed << std::right << std::setw(7) << std::setprecision(2) << cost() << "|"
               << std::fixed << std::setw(4) << quantity() << "|"
               << std::fixed << std::setw(10) << std::left << unit() << "|"
               << std::fixed << std::setw(4) << std::right << qtyNeeded() << "|";
         }
         else {
            os << " Sku: " << sku() << std::endl;
            os << " Name (no spaces): " << name() << std::endl;
            os << " Price: " << price() << std::endl;
            if (taxed()) {
               os << " Price after tax: " << cost() << std::endl;
            }
            else {
               os << " Price after tax: N/A" << std::endl;
            }
            os << " Quantity on Hand: " << quantity()
               << " " << unit() << std::endl;
            os << " Quantity needed: " << qtyNeeded();
         }
      }
      else {
         os << errCode.message();
      }
	  return os;
   }

   // Read the user input about the product information
   std::istream& Product::read(std::istream& is) {
	   Product tmp;
      tmp.productName = new (std::nothrow) char[max_name_length+1];  // Allocate memory for the tmp product name
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
         is.clear();
			is.setstate(std::ios::failbit);
		}
      // Checks the state of input stream each time prior to receiving user input
      if (!is.fail()) {
         std::cout << " Price: ";
         is >> tmp.productPrice;
         if (is.fail()) {
            this->message("Invalid Price Entry");
         }
      }
      if (!is.fail()) {
         std::cout << " Quantity on hand: ";
         is >> tmp.qtyOnHand;
         if (is.fail()) {
            this->message("Invalid Quantity Entry");
         }
      }
      if (!is.fail()) {
         std::cout << " Quantity needed: ";
         is >> tmp.qtyNeed;
         if (is.fail()) {
            this->message("Invalid Quantity Needed Entry");
         }
      }
      if (!is.fail()) {
         this->message(tmp.errCode.message());
         *this = tmp;
      }
      delete [] tmp.productName; // Deallocate memory from tmp product name
      tmp.productName = nullptr; 
	is.ignore();
	  return is;
   }

   // Operator to check if the current object sku is the same as the argument
   bool Product::operator==(const char* str) const {
      if (sku() == str) {
         return true;
      }
      return false;
   }

   // Calculates and returns the total cost of the product
   double Product::total_cost() const {
	   double total;
	   return total = cost() * quantity();
   }

   // Modifier that sets the quantity on hand
   void Product::quantity(int no) {
      qtyOnHand = no;
   }

   // Query that checks if object is in safe empty state
   bool Product::isEmpty() const {
      if (productName == '\0' || productName == nullptr) {
            return true;
      }
      return false;
   }

   // Query that returns the quantity needed 
   int Product::qtyNeeded() const {
      return qtyNeed;
   }
   
   // Query that returns the quantity on hand
   int Product::quantity() const {
      return qtyOnHand;
   }

   // Operator:
   // Checks if the name is longer than the source
   bool Product::operator>(const iProduct& src) const {
	   if (strcmp(this->name(), src.name()) > 0) {
		   return true;
	   }
	   return false;
   }

   // Checks if the sku is longer than the source
   bool Product::operator>(const char* sku) const {
	   if (strcmp(this->sku(), sku) > 0) {
		   return true;
	   }
	   return false;
   }

   // Modifier that adds extra units to quantity on hand
   int Product::operator+=(int unit) {
	   if (unit > 0) {
		   return qtyOnHand += unit;
	   }
	   return qtyOnHand;
	}

   // Helper Functions:
   std::ostream& operator<<(std::ostream& os, const iProduct& src) {
	   src.write(os, true);
	   return os;
   }

   std::istream& operator>>(std::istream& is, iProduct& src) {
	   src.read(is);
	   return is;
   }
   double operator+=(double& cost, const iProduct& src) {
	   return cost += src.total_cost();
   }
}