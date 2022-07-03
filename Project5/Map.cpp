#include <string>
#include "Node.h"
#include "Map.h"


void MapCreate(Map* map)
{
	map->Buffer = map->BasicBuffer;
	map->Array = new Node[map->Buffer];
	MapInitializate(map);
	map->Length = 0;
}

void MapInitializate(Map* map)
{
	for (int index = 0; index < map->Buffer; index++)
	{
		map->Array[index] = *new Node;
		map->Array[index].Key = "";
		map->Array[index].Value = "";
		map->Array[index].Next = nullptr;
	}
}

void MapAddElement(Map* map, string key, string value)
{
	int hash = MapHashCalculate(map, key);
	if (map->Array[hash].Key.empty())
	{
		map->Array[hash].Key = key;
		map->Array[hash].Value = value;
		map->Length++;
	}
	else
	{
		MapCollizionSolve(map, hash, key, value);
	}
	if (map->Length == map->Buffer)
	{
		MapResize(map);
	}
}

void MapDeleteElement(Map* map, string key)
{
	int index = MapHashCalculate(map, key);
	if (map->Array[index].Next == nullptr)
	{
		map->Array[index].Key = "";
		map->Array[index].Value = "";
		map->Length--;
		return;
	}
	Node* previousNode = nullptr;
	Node* currentNode = &map->Array[index];
	while (currentNode->Key != key)
	{
		previousNode = currentNode;
		currentNode = currentNode->Next;
	}
	if (previousNode == nullptr)
	{
		currentNode = map->Array[index].Next;
		map->Array[index].Next = currentNode->Next;
		map->Array[index].Key = currentNode->Key;
		map->Array[index].Value = currentNode->Value;
	}
	else
	{
		previousNode->Next = currentNode->Next;
	}
}

string MapSearch(Map* map, string key)
{
	int index = MapHashCalculate(map, key);
	if (map->Array[index].Key != key)
	{
		return "Not exist";
	}
	else
	{
		return map->Array[index].Value;
	}
}

string SearchTable(Map* map, string key)
{
	int index = MapHashCalculate(map, key);
	Node* currentNode = new Node;
	currentNode = &map->Array[index];
	while (currentNode != nullptr)
	{
		if (currentNode->Key == key)
		{
			return currentNode->Value;
		}
		currentNode = currentNode->Next;
	}
	return "Not exist";
}

void MapCollizionSolve(Map* map, int hash, string key, string value)
{
	Node* currentNode = new Node;
	currentNode = &map->Array[hash];
	while (currentNode != nullptr)
	{
		if (currentNode->Key == key)
		{
			if (currentNode->Value == value)
			{
				return;
			}
		}
		currentNode = currentNode->Next;
	}
	Node* newNode = new Node;
	currentNode = &map->Array[hash];
	while (currentNode->Next != nullptr)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = newNode;
	newNode->Key = key;
	newNode->Value = value;
	newNode->Next = nullptr;
}

int MapHashCalculate(Map* map, string key)
{
	int hash = 0;
	int argument = map->Buffer - 1;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + int(key[i]) * argument) % map->Buffer;
	}
	return hash;
}

void MapResize(Map* map)
{
	map->Buffer = map->Buffer * map->GrowthFactor;
	Node* oldArray = map->Array;
	int oldLength = map->Length;
	map->Length = 0;
	map->Array = new Node[map->Buffer];
	Node* node = new Node;
	MapInitializate(map);
	for (int index = 0; index < oldLength; index++)
	{	
		node = &oldArray[index];
		if (!node->Key.empty())
		{
			while (node != nullptr)
			{
				MapAddElement(map, node->Key, node->Value);
				node = node->Next;
			}
		}
	}
	delete[] oldArray;
}

void MapDelete(Map* map)
{
	delete[] map->Array;
}
