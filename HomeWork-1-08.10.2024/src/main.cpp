#include "txt-editor.h"

int main(int argc, char* argv[])
{
	TxtEditor TextEditor;
	TextEditor.addText("Added Text");
	std::cout << TextEditor << std::endl;

	TextEditor.addText("Added NewText");
	std::cout << TextEditor << std::endl;

	TextEditor.addText("This text will be deleted");
	std::cout << TextEditor << std::endl;

	TextEditor.deleteText(25);
	std::cout << TextEditor << std::endl;

	std::cout << TextEditor.cursorLeft(7) << std::endl;

	TextEditor.addText("not ");
	std::cout << TextEditor << std::endl;

	std::cout << TextEditor.cursorRight(3) << std::endl;

	TextEditor.addText(" ");
	std::cout << TextEditor << std::endl;

	return 0;
};