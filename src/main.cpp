/*
 Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string> и возвращающую множество значений этого словаря:
 set<string> BuildMapValuesSet(const map<int, string>& m) {
 // ...
 }

 Пример

 set<string> values = BuildMapValuesSet({
 {1, "odd"},
 {2, "even"},
 {3, "odd"},
 {4, "even"},
 {5, "odd"}
 });

 for (const string& value : values) {
 cout << value << endl;
 }

 Вывод

 even
 odd

 Пояснение

 В этой задаче на проверку вам надо прислать файл с реализацией функции BuildMapValuesSet.
 Этот файл не должен содержать функцию main. Если в нём будет функция main, вы получите ошибку компиляции.
 */

#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m);

int main() {
	set<string> values = BuildMapValuesSet( { { 1, "odd" }, { 2, "even" }, { 3,
			"odd" }, { 4, "even" }, { 5, "odd" } });

	for (const string &value : values) {
		cout << value << endl;
	}

	return 0;
}
