#ifndef TXT_EDITOR_H
#define TXT_EDITOR_H

#include<iostream>

class TxtEditor
{
public:
	TxtEditor();
	void addText(std::string text);
	int deleteText(int k);
	std::string cursorLeft(int k);
	std::string cursorRight(int k);

	friend std::ostream& operator<<(std::ostream& stream, const TxtEditor& text);

private:
	int cursorPos;
	std::string txt;
};

#endif