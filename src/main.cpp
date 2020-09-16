/*
 Дан набор строк. Найдите количество уникальных строк в этом наборе.
 Формат ввода

 Сначала вводится количество строк N, затем — сами N строк, разделённые символом перевода строки.
 Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.

 Формат вывода

 Выведите единственное целое число — количество уникальных строк в данном наборе.

 Пример

 Ввод

 6
 first
 second
 first
 third
 second
 second

 Вывод

 3
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int N = 0;
	string input = "";
	set<string> unique_strings;
	cin >> N;

	while (N > 0) {
		cin >> input;
		unique_strings.insert(input);
		N--;
	}

	cout << unique_strings.size();

	return 0;
}
