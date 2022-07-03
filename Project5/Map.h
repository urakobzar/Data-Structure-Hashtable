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

/// @brief Функция создания Словаря
/// @param map Переменная структуры Словарь
void MapCreate(Map* map);

/// @brief Функция инициализации Словаря
/// @param map Переменная структуры Словарь
void MapInitializate(Map* map);

/// @brief Функция добавление пары Ключ-Значение
/// @param map Переменная структуры Словарь
/// @param key Добавляемый Ключ
/// @param value Добавляемое Значение
void MapAddElement(Map* map, string key, string value);

/// @brief Функция удаления по Ключу
/// @param map Переменная структуры Словарь
/// @param key Удаляемый Ключ, введенный пользователем
void MapDeleteElement(Map* map, string key);

/// @brief Функция поиска по Ключу в Словаре
/// @param map Переменная структуры Словарь
/// @param key Ключ, по которому идет поиск
/// @return Возвращает или пару Ключ - Значение
/// Или уведомление об отсутсвии пары
string MapSearch(Map* map, string key);

/// @brief Функция поиска по Ключу в Хэш-Таблице
/// @param map Переменная структуры Словарь
/// @param key Ключ, по которому идет поиск
/// @return Возвращает или пару Ключ - Значение
/// Или уведомление об отсутсвии пары
string SearchTable(Map* map, string key);

/// @brief Функция для решения коллизий
/// @param map Переменная структуры Словарь
/// @param hash Хэш, расчитанный Хэш-Функцией
/// @param key Введенный пользователем Ключ
/// @param value Введенное пользователем Значение
void MapCollizionSolve(Map* map, int hash, string key, string value);

/// @brief Функция для расчёта Хэша
/// @param map Переменная структуры Словарь
/// @param key Введенный пользователем Ключ
/// @return Возвращает индекс, под которым будет запись пары Ключ-Значение
int MapHashCalculate(Map* map, string key);

/// @brief Функция увеличения размера Словаря
/// @param map Переменная структуры Словарь
void MapResize(Map* map);

/// @brief Удаление Словаря
/// @param map Переменная структуры Словарь
void MapDelete(Map* map);
