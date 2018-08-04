#include "ErrorState.h"
#include <cstring>

namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			eMessage = '\0';
		}
		else {
			int size = strlen(errorMessage);
			eMessage = new (std::nothrow) char[size];
			strncpy(eMessage, errorMessage, size);
			eMessage[size] = '\0';
		}
	}

	ErrorState::~ErrorState() {
		delete[] eMessage;
	}

	void ErrorState::clear() {
		eMessage = '\0';
	}

	bool ErrorState::isClear() const {
		if (eMessage == '\0') {
			return true;
		}
		return false;
	}

	void ErrorState::message(const char* str) {
		delete[] eMessage;
		int size = strlen(str);
		eMessage = new (std::nothrow) char[size+1];
		strncpy(eMessage, str, size);
		eMessage[size] = '\0';
	}

	const char* ErrorState::message() const {
		return eMessage;
	}

	std::ostream& operator<<(std::ostream& ostr, const ErrorState& obj) {
		if (obj.message() != '\0') {
			ostr << obj.message();
		}
		return ostr;
	}
}