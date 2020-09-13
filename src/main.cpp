/*Напишите функцию, которая:
 * называется IsPalindrom
 * возвращает bool
 * принимает параметр типа string и возвращает, является ли переданная строка палиндромом
 *
 * Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является палиндромом.*/

#include <iostream>
#include <string>
#include "../include/IsPalindrom.h"

int main() {
	std::string s;
	std::cin >> s;
	std::cout << IsPalindrom(s);
	return 0;
}
