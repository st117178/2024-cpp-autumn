#ifndef TXT_EDITOR_CPP
#define TXT_EDITOR_CPP

#include "Str-operator[].h"

String::String(const char* str) : startInd(0), flag(0) {
	size = strlen(str);
	this->str = new char[size + 1];
	for (size_t i = 0; i <= size; ++i)
		this->str[i] = str[i];
}

String::String(size_t n, char c) : size(n), str(0), startInd(0), flag(0)
{
	this->str = new char[size + 1];
	for (int i = 0; i < size; this->str[i] = c, ++i);
	str[size] = '\0';
}

String::~String()
{
	delete[] str;
}

String::String(const String& other) :size(other.size), startInd(other.startInd), flag(other.flag)
{
	str = new char[size + 1];
	strcpy(str, other.str);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] this->str;
		this->flag = other.flag;
		this->startInd = other.startInd;
		this->size = other.size;
		this->str = new char[this->size + 1];
		strcpy(this->str, other.str);
	}

	return *this;
}

void String::append(const String& other)
{
	size += other.size;
	char* new_str = new char[size + 1];
	strcpy(new_str, str);
	strcat(new_str, other.str);
	delete[] str;
	str = new_str;
}

std::ostream& operator<<(std::ostream& stream, const String& text)
{
	for (int i = 0; i < text.size; i++)
	{
		stream << text.str[i];
	}

	return stream;
}

String String::operator[](int i)
{
	if (flag)
	{
		if (startInd == i)
		{
			return "";
		}
		String newStr(i, 0);
		for (int k = 0; k < i - startInd; k++)
		{
			newStr.str[k] = this->str[k];
		}
		return newStr;

	}
	String newStr(this->size - i, 0);
	newStr.startInd = i;
	newStr.flag = true;
	for (int k = 0; k < this->size - i; k++)
	{
		newStr.str[k] = this->str[k + i];
	}

	int& j = i;
	return newStr;
}

#endif