#ifndef TXT_EDITOR_H
#define TXT_EDITOR_H

#include <iostream>
#include <cstddef>  // size_t
#include <cstring>  // strlen, strcpy

struct String {
public:
	String(const char* str = "");
	String(size_t n, char c);
	~String();

	String(const String& other);
	String& operator=(const String& other);
	String operator[](int i);

	void append(const String& other);

	friend std::ostream& operator<<(std::ostream& stream, const String& text);
private:
	size_t size;
	char* str;
	int startInd;
	bool flag;
};

#endif