/*
 Условие

 В стандартном потоке дана одна строка,
 состоящая из числа N и следующих за ним N строк S.
 Между собой число и строки разделены пробелом.

 Отсортируйте строки S в лексикографическом порядке по возрастанию,
 игнорируя регистр букв, и выведите их в стандартный поток вывода.

 Ограничения

 0 <= N <= 1000
 1 <= |S| <= 15
 Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]

 Примеры
 stdin		stdout
 2 q A		A q
 3 a C b	a b C

 Подсказка

 Обратите внимание на функцию tolower.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
#include <vector>

using namespace std;

string lowerString(const string &s) {
	string lowerS = "";
	locale loc;

	for (auto &c : s) {
		lowerS += tolower(c, loc);
	}

	return lowerS;
}

int main() {

	int N = 0;
	cin >> N;
	vector<string> strings(N);

	for (auto &s : strings) {
		cin >> s;
	}

	sort(begin(strings), end(strings),
			[](const string &left, const string &right) {
				return lowerString(left) < lowerString(right);
			});

	for (const auto &i : strings) {
		cout << i << ' ';
	}

	return 0;
}
