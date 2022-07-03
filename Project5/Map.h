#pragma once
#include "Node.h"

struct Map
{
	Node* Array;
	int Length;
	const int BasicBuffer = 8;
	int Buffer;
	const double GrowthFactor = 1.5;
};

/// @brief ������� �������� �������
/// @param map ���������� ��������� �������
void MapCreate(Map* map);

/// @brief ������� ������������� �������
/// @param map ���������� ��������� �������
void MapInitializate(Map* map);

/// @brief ������� ���������� ���� ����-��������
/// @param map ���������� ��������� �������
/// @param key ����������� ����
/// @param value ����������� ��������
void MapAddElement(Map* map, string key, string value);

/// @brief ������� �������� �� �����
/// @param map ���������� ��������� �������
/// @param key ��������� ����, ��������� �������������
void MapDeleteElement(Map* map, string key);

/// @brief ������� ������ �� ����� � �������
/// @param map ���������� ��������� �������
/// @param key ����, �� �������� ���� �����
/// @return ���������� ��� ���� ���� - ��������
/// ��� ����������� �� ��������� ����
string MapSearch(Map* map, string key);

/// @brief ������� ������ �� ����� � ���-�������
/// @param map ���������� ��������� �������
/// @param key ����, �� �������� ���� �����
/// @return ���������� ��� ���� ���� - ��������
/// ��� ����������� �� ��������� ����
string SearchTable(Map* map, string key);

/// @brief ������� ��� ������� ��������
/// @param map ���������� ��������� �������
/// @param hash ���, ����������� ���-��������
/// @param key ��������� ������������� ����
/// @param value ��������� ������������� ��������
void MapCollizionSolve(Map* map, int hash, string key, string value);

/// @brief ������� ��� ������� ����
/// @param map ���������� ��������� �������
/// @param key ��������� ������������� ����
/// @return ���������� ������, ��� ������� ����� ������ ���� ����-��������
int MapHashCalculate(Map* map, string key);

/// @brief ������� ���������� ������� �������
/// @param map ���������� ��������� �������
void MapResize(Map* map);

/// @brief �������� �������
/// @param map ���������� ��������� �������
void MapDelete(Map* map);
