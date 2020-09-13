/*Напишите функцию, которая:
 * называется PalindromFilter
 * возвращает vector<string>
 * принимает vector<string> words и int minLength и возвращает все строки из вектора words,
 * которые являются палиндромами и имеют длину не меньше minLength
 *
 * Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.*/

#include <iostream>
#include <vector>
#include "../include/PalindromFilter.h"

using namespace std;

int main() {
	vector<string> words = { "abacaba", "aba" };
	for (auto s : PalindromFilter(words, 5)) {
		cout << s << ' ';
	}
	return 0;
}
