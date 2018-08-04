#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

namespace AMA {
	class ErrorState {
	private:
		char * eMessage;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear();
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream& ostr, const ErrorState& obj);
}
#endif