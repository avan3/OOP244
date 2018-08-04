#include "Perishable.h"

namespace AMA {
   // Constructor:
   // Initialize the perishable date object to safe empty state and product type to P
   Perishable::Perishable() : Product('P') { 
      expiryDate = Date();
   }

   // Modifier that stores the info of the product and the expiry date of the perishable into a file
   std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
      Product::store(file, false);
      file << ',';
      file << expiry();
      if (newLine == true) {
         file << "\n";
      }
      return file;
   }

   // Loads the information stored in the file 
   std::fstream& Perishable::load(std::fstream& file) {
      char junk;
      Product::load(file);
      file >> junk;
      this->expiryDate.read(file);
      file >> junk;
      return file;
   }

   // Writes to the output device the product information with the expiry date either linearly or not
   std::ostream& Perishable::write(std::ostream& os, bool linear) const {
      Product::write(os, linear);
      if (this->isClear() || this->isEmpty() == true) {
         if (linear == true) {
            os << expiry();
         }
         else {
            os << "\n Expiry date: " << expiry();
         }
      }
      return os;
   }
   
   // Reads from user input the product information and the expiry date
   std::istream& Perishable::read(std::istream& is) {
      Date tmp;
      Product::read(is);
      if (is.good()) {
         std::cout << " Expiry date (YYYY/MM/DD): ";
         tmp.read(is);
         if (tmp.bad() == true) {
            is.setstate(std::ios::failbit);
            switch (tmp.errCode()) {
               case CIN_FAILED: 
                  this->message("Invalid Date Entry");
                  break;
               case YEAR_ERROR:
                  this->message("Invalid Year in Date Entry");
                  break;
               case MON_ERROR:
                  this->message("Invalid Month in Date Entry");
                  break;
               case DAY_ERROR:
                  this->message("Invalid Day in Date Entry");
                  break;
            }
         }
         else {
            expiryDate = tmp;
         }
      }
      return is;
   }

   // Query to return the expiry date of the object
   const Date& Perishable::expiry() const {
      return expiryDate;
   }
}