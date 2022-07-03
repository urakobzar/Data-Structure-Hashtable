#include <string>
#include "Node.h"
#include "HashTable.h"


void Create(HashTable* hashTable)
{
	hashTable->Buffer = hashTable->BasicBuffer;
	hashTable->Array = new Node[hashTable->Buffer];
	Initializate(hashTable);
	hashTable->Length = 0;
}

void Initializate(HashTable* hashTable)
{
	for (int index = 0; index < hashTable->Buffer; index++)
	{
		hashTable->Array[index] = *new Node;
		hashTable->Array[index].Key = "";
		hashTable->Array[index].Value = "";
		hashTable->Array[index].Next = nullptr;
	}
}

void AddElement(HashTable* hashTable, string key, string value)
{
	int hash = HashCalculate(hashTable, key);
	if (hashTable->Array[hash].Key.empty())
	{
		hashTable->Array[hash].Key = key;
		hashTable->Array[hash].Value = value;
		hashTable->Length++;
	}
	else
	{
		CollizionSolve(hashTable, hash, key, value);
	}
	if (hashTable->Length == hashTable->Buffer)
	{
		Resize(hashTable);
	}
}

int HashCalculate(HashTable* hashTable, string key)
{
	int hash = 0;
	int argument = hashTable->Buffer - 1;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + int(key[i]) * argument) % hashTable->Buffer;
	}
	return hash;
}

void CollizionSolve(HashTable* hashTable, int hash, string key, string value)
{
	Node* newNode = new Node;
	Node* currentNode = new Node;
	currentNode = &hashTable->Array[hash];
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
	currentNode = &hashTable->Array[hash];
	while (currentNode->Next != nullptr)
	{
		currentNode = currentNode->Next;
	}
	currentNode->Next = newNode;
	newNode->Key = key;
	newNode->Value = value;
	newNode->Next = nullptr;
}

void Resize(HashTable* hashTable)
{
	hashTable->Buffer = hashTable->Buffer * hashTable->GrowthFactor;
	Node* oldArray = hashTable->Array;
	int oldLength = hashTable->Length;
	hashTable->Length = 0;
	hashTable->Array = new Node[hashTable->Buffer];
	Node* node = new Node;
	Initializate(hashTable);
	for (int index = 0; index < oldLength; index++)
	{
		node = &oldArray[index];
		if (!node->Key.empty())
		{
			while (node != nullptr)
			{
				AddElement(hashTable, node->Key, node->Value);
				node = node->Next;
			}
		}
	}
	delete[] oldArray;
}

string SearchTable(HashTable* hashTable, string key)
{
	int index = HashCalculate(hashTable, key);
	Node* currentNode = new Node;
	currentNode = &hashTable->Array[index];
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

void DeleteElement(HashTable* hashTable, string key)
{
	int index = HashCalculate(hashTable, key);
	if (hashTable->Array[index].Next == nullptr)
	{
		hashTable->Array[index].Key = "";
		hashTable->Array[index].Value = "";
		hashTable->Length--;
		return;
	}
	Node* previousNode = nullptr;
	Node* currentNode = &hashTable->Array[index];
	while (currentNode->Key != key)
	{
		previousNode = currentNode;
		currentNode = currentNode->Next;
	}
	if (previousNode == nullptr)
	{
		currentNode = hashTable->Array[index].Next;
		hashTable->Array[index].Next = currentNode->Next;
		hashTable->Array[index].Key = currentNode->Key;
		hashTable->Array[index].Value = currentNode->Value;
	}
	else
	{
		previousNode->Next = currentNode->Next;
	}
}

void Delete(HashTable* hashTable)
{
	delete[] hashTable->Array;
}