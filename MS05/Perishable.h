#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Product.h"
#include "Date.h"

namespace AMA {
   class Perishable : public Product {
   private:
      Date expiryDate;
   public:
      Perishable();
      std::fstream& store(std::fstream& file, bool newLine=true) const;
      std::fstream& load(std::fstream& file);
      std::ostream& write(std::ostream& os, bool linear) const;
      std::istream& read(std::istream& is);
      const Date& expiry() const;
      
   };
}
#endif