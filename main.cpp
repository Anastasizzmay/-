#include "interface.cpp"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Interface<int> book;
	book.objectSelectionMenu();
	return 0;
}