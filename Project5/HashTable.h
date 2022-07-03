#pragma once
#include "Node.h"

struct HashTable
{
	Node* Array;	
	int Length;
	const int BasicBuffer = 8;
	int Buffer;
	const double GrowthFactor = 1.5;
};

/// @brief ������� �������� ���-�������
/// @param hashTable ���������� ��������� ���-�������
void Create(HashTable* hashTable);

/// @brief ������� ������������� ���-�������
/// @param hashTable ���������� ��������� ���-�������
void Initializate(HashTable* hashTable);

/// @brief ������� ���������� ���� ����-��������
/// @param hashTable ���������� ��������� ���-�������
/// @param key ��������� ������������� ����
/// @param value ��������� ������������� ��������
void AddElement(HashTable* hashTable, string key, string value);

/// @brief ������� ��� ������� ����
/// @param hashTable ���������� ��������� ���-�������
/// @param key ��������� ������������� ����
/// @return ���������� ������, ��� ������� ����� ������ ���� ����-��������
int HashCalculate(HashTable* hashTable, string key);

/// @brief ������� ��� ������� ��������
/// @param hashTable ���������� ��������� ���-�������
/// @param hash ���, ����������� ���-��������
/// @param key ��������� ������������� ����
/// @param value ��������� ������������� ��������
void CollizionSolve(HashTable* hashTable, int hash, string key, string value);

/// @brief ������� ���������� ������� ���-�������
/// @param hashTable ���������� ��������� ���-�������
void Resize(HashTable* hashTable);

/// @brief ������� �������� �������� �� ���-�������
/// @param hashTable ���������� ��������� ���-�������
/// @param key ��������� ����, ��������� �������������
void DeleteElement(HashTable* hashTable, string key);

/// @brief ������� ������ �� ����� � ���-�������
/// @param hashTable ���������� ��������� ���-�������
/// @param key ����, �� �������� ���� �����
/// @return ���������� ��� ���� ���� - ��������
/// ��� ����������� �� ��������� ����
string SearchTable(HashTable* hashTable, string key);

/// @brief ������� �������� ���-�������
/// @param hashTable ���������� ��������� ���-�������
void Delete(HashTable* hashTable);
