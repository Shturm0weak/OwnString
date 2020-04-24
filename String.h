#pragma once
#include <iostream>

namespace Custom {

	class String {
	private:
		char* buffer = nullptr;
		unsigned int length = 0;

	public:
		String(const char* text);
		~String();

		inline unsigned int Length() { return length; }

		friend std::ostream& operator<<(std::ostream& os, const String& text);

		friend std::ostream& operator<<(std::ostream& os, const String* text);

		friend std::istream& operator>>(std::istream& os, String& text);

		friend std::istream& operator>>(std::istream& os, String* text);

		String& operator + (String& string);

		String& operator + (const char* buffer);

		void operator += (const char* buffer);

		void operator += (String& string);

		bool Empty();

		void Clear();

		unsigned int Find(char symbol);

		bool Swap(unsigned int from, unsigned int to);

		bool Replace(char symbol, unsigned int position);

		bool Erase(unsigned int position);

		char Front();

		char Back();
	};

}