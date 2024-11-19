#ifndef TXT_EDITOR_CPP
#define TXT_EDITOR_CPP

#include "txt-editor.h"

TxtEditor::TxtEditor()
{
	txt = "";
	cursorPos = 0;
}

std::ostream &operator<<(std::ostream &stream, const TxtEditor &text)
{
	stream << text.txt;
	return stream;
}

void TxtEditor::addText(std::string text)
{
	txt.insert(cursorPos, text);
	cursorPos = cursorPos + text.length();
}

int TxtEditor::deleteText(int k)
{
	if (cursorPos < k)
	{
		return 0;
	}

	int deletedEl = txt.length() - k;
	txt.erase(deletedEl);
	cursorPos = cursorPos - k;
	return k;
}

std::string TxtEditor::cursorLeft(int k)
{
	if (cursorPos < k)
	{
		return 0;
	}

	cursorPos = cursorPos - k;

	return txt.substr(0, cursorPos);
}

std::string TxtEditor::cursorRight(int k)
{
	if ((txt.length() - cursorPos) < k)
	{
		return 0;
	}

	cursorPos = cursorPos + k;

	return txt.substr(cursorPos);
}

int TxtEditor::getCursorPos()
{
	return cursorPos;
}

std::string TxtEditor::getTxt()
{
	return txt;
}

#endif