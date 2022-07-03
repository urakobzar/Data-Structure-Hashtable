#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Map.h"
#include "Common.h"

using namespace std;

enum MenuAction
{
	AddItem = 1,
	DeleteItem = 2,
	SearchItem = 3,
	ExitItem = 4
};

enum DeleteAction
{
	DeleteMapItem = 1,
	DeleteTableItem = 2,
};

enum SearchAction
{
	SearchMapItem = 1,
	SearchTableItem = 2,
};

/// @brief Функция вывода на экран Хэш-Таблицы и Словаря
/// @param map Переменная структуры Словарь
void PrintMapAndTable(Map* map)
{
	cout << "\nMAP\n";
	cout<<"	Key	   Value	\n";
	for (int index = 0; index < map->Buffer; index++)
	{
		if (!map->Array[index].Key.empty())
		{
			cout << "[	" << map->Array[index].Key;
			cout << "	-  " << map->Array[index].Value;
			cout << "		]\n";
		}
	}
	Node* currentNode = new Node;
	cout << "\nHASH TABLE\n\n";
	cout << "Index	|	Key		|	Value	\n";
	for (int index = 0; index < map->Buffer; index++)
	{
		currentNode = &map->Array[index];
		if (map->Array[index].Key.empty())
		{
			cout << "___________________________";
			cout << "___________________________\n";
			cout << index << "	|			|		\n";
		}
		else
		{
			cout << "___________________________";
			cout << "___________________________\n";
			cout << index << "	|	";
			cout << currentNode->Key << "		|	";
			cout << currentNode->Value << "	\n";
			while (currentNode->Next != nullptr)
			{
				if (currentNode->Next != nullptr)
				{
					currentNode = currentNode->Next;
					cout << "___________________________";
					cout << "___________________________\n";
					cout << " >" << "	|	";
					cout << currentNode->Key << "		|	";
					cout << currentNode->Value << "	\n";
				}
			}
		}
	}
}

int main()
{
	bool menuExit = false;
	Map* map = new Map;
	MapCreate(map);
	while (!menuExit)
	{
		if (map->Length != 0)
		{
			PrintMapAndTable(map);
		}
		cout << "\n\nPlease select your action\n";
		cout << " 1) Insert (key - value)\n";
		cout << " 2) Remove (key)\n";
		cout << " 3) Find (key)\n";
		cout << " 4) Program exit\n";
		int menuNumber = ReadingCorrectValue();
		switch (menuNumber)
		{
			case AddItem:
			{		
				cout << "\nPlease enter Key: ";
				string key = ReadingCorrectLine();
				cout << endl;
				cout << "Please enter Value: "; 
				string value = ReadingCorrectLine();
				cout << endl;
				MapAddElement(map, key, value);	
				system("pause");
				break;
			}
			case DeleteItem:
			{
				if (map->Length == 0)
				{
					cout << "\nHash-Table and Map are empty\n\n";
					system("pause");
					break;
				}
				cout << "\n\nPlease select your action\n";
				cout << " 1) Delete in the Map\n";
				cout << " 2) Delete in the Table\n";
				cout << " Enter any other number to go to the main menu\n";
				int menuNumber = ReadingCorrectValue();
				switch (menuNumber)
				{
					case DeleteMapItem:
					{
						cout << "\nPlease enter Key: ";
						string key = ReadingCorrectLine();
						cout << endl;
						if (MapSearch(map, key) != "Not exist")
						{
							MapDeleteElement(map, key);
						}
						else
						{
							cout << "The Map does not contain this Key\n";
						}
						break;
					}
					case DeleteTableItem:
					{
						cout << "\nPlease enter Key: ";
						string key = ReadingCorrectLine();
						cout << endl;
						if (SearchTable(map, key) != "Not exist")
						{
							MapDeleteElement(map, key);
						}
						else
						{
							cout << "The Table does not contain this Key\n";
						}
						break;
					}
					default:
					{
						cout << "\n(You have decided to return to the main menu)\n";
						break;
					}
				}
				system("pause");
				break;
			}
			case SearchItem:
			{
				if (map->Length == 0)
				{
					cout << "\nHash-Table and Map are empty\n\n";
					system("pause");
					break;
				}
				cout << "\n\nPlease select your action\n";
				cout << " 1) Search in the Map\n";
				cout << " 2) Search in the Table\n";
				cout << " Enter any other number to go to the main menu\n";
				int menuNumber = ReadingCorrectValue();
				switch (menuNumber)
				{
					case SearchMapItem:
					{
						cout << "\nPlease enter Key: ";
						string key = ReadingCorrectLine();
						cout << endl;
						if (MapSearch(map, key) == "Not exist")
						{
							cout << "\nThe Key was not found\n";
						}
						else
						{
							cout << "KEY - VALUE:\n";
							cout << "[ " << key << " - " << MapSearch(map, key) << " ]\n";
						}
						break;
					}
					case SearchTableItem:
					{
						cout << "\nPlease enter Key: ";
						string key = ReadingCorrectLine();
						cout << endl;
						if (SearchTable(map, key) == "Not exist")
						{
							cout << "\nThe Key was not found\n";
						}
						else
						{
							cout << "KEY - VALUE:\n";
							cout << "[ " << key << " - " << SearchTable(map, key) << " ]\n";
						}
						break;
					}
					default:
					{
						cout << "\n(You have decided to return to the main menu)\n";
						break;
					}
				}	
				system("pause");
				break;
			}
			case ExitItem:
			{
				MapDelete(map);
				menuExit = true;
				system("pause");
				break;
			}
			default:
			{
				cout << "\nUnfortunately, You made a mistake\n";
				cout << "(Make a choice from the suggested options)\n";
				system("pause");
				break;
			}
		}
	}
	delete map;
	return 0;
}
