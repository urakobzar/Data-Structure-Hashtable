#include <iostream>
#include <string>
#include "Common.h"

using namespace std;

int ReadingCorrectValue()
{
	int value;
	cout << "Enter your choice: ";
	while (true)
	{

		if (cin >> value)
		{
			break;
		}
		cout << "\nUnfortunately, You made a mistake\n";
		cout << "(The value you enter must be an integer)\n\n";
		cout << "Enter again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return value;
}

string ReadingCorrectLine()
{
	string line = "";
	while (true)
	{
		bool russianSymbol = false;
		getline(cin, line);
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] < 0)
			{
				russianSymbol = true;
			}
		}
		if (!russianSymbol && !line.empty())
		{
			break;
		}
		cout << "\nUnfortunately, You made a mistake\n";
		cout << "(Enter in English or enter numbers)\n\n";
		cout << "\nEnter again: ";
		line = "";
	}
	return line;
}
