#include "ErrorState.h"
#include <cstring>

namespace AMA {
   // Constructor:
	ErrorState::ErrorState(const char* errorMessage) {
      eMessage = nullptr;
      message(errorMessage);
	}
   // Destructor:
	ErrorState::~ErrorState() {
		delete[] eMessage;
	}

   // Clear all error messages
	void ErrorState::clear() {
		eMessage = nullptr;
	}

   // Query to check state of the object
	bool ErrorState::isClear() const {
		if (eMessage == nullptr) {
			return true;
		}
		return false;
	}

   // Modifier that allocates memory and sets error message to the argument
	void ErrorState::message(const char* str) {
      if (str == nullptr) {
         eMessage = nullptr;
      }
      else {
         int size = strlen(str);
         eMessage = new (std::nothrow) char[size];
         strncpy(eMessage, str, size);
         eMessage[size] = '\0';
      }
	}

   // Query to return the error message
	const char* ErrorState::message() const {
		return eMessage;
	}

   // Helper function:
	std::ostream& operator<<(std::ostream& ostr, const ErrorState& obj) {
		if (obj.message() != nullptr) {
			ostr << obj.message();
		}
		return ostr;
	}
}