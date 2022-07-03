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

/// @brief Функция создания Хэш-Таблицы
/// @param hashTable Переменная структуры Хэш-Таблица
void Create(HashTable* hashTable);

/// @brief Функция инициализации Хэш-Таблицы
/// @param hashTable Переменная структуры Хэш-Таблица
void Initializate(HashTable* hashTable);

/// @brief Функция добавления пары Ключ-Значение
/// @param hashTable Переменная структуры Хэш-Таблица
/// @param key Введенный пользователем Ключ
/// @param value Введенное пользователем Значение
void AddElement(HashTable* hashTable, string key, string value);

/// @brief Функция для расчёта Хэша
/// @param hashTable Переменная структуры Хэш-Таблица
/// @param key Введенный пользователем Ключ
/// @return Возвращает индекс, под которым будет запись пары Ключ-Значение
int HashCalculate(HashTable* hashTable, string key);

/// @brief Функция для решения коллизий
/// @param hashTable Переменная структуры Хэш-Таблица
/// @param hash Хэш, расчитанный Хэш-Функцией
/// @param key Введенный пользователем Ключ
/// @param value Введенное пользователем Значение
void CollizionSolve(HashTable* hashTable, int hash, string key, string value);

/// @brief Функция увеличения размера Хэш-Таблицы
/// @param hashTable Переменная структуры Хэш-Таблица
void Resize(HashTable* hashTable);

/// @brief Функция удаления элемента из Хэш-Таблицы
/// @param hashTable Переменная структуры Хэш-Таблица
/// @param key Удаляемый Ключ, введенный пользователем
void DeleteElement(HashTable* hashTable, string key);

/// @brief Функция поиска по Ключу в Хэш-Таблице
/// @param hashTable Переменная структуры Хэш-Таблица
/// @param key Ключ, по которому идет поиск
/// @return Возвращает или пару Ключ - Значение
/// Или уведомление об отсутсвии пары
string SearchTable(HashTable* hashTable, string key);

/// @brief Функция удаления Хэш-Таблицы
/// @param hashTable Переменная структуры Хэш-Таблица
void Delete(HashTable* hashTable);
