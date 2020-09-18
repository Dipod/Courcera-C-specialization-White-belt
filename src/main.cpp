/*
 Условие

 В стандартном потоке дана одна строка,
 состоящая из N + 1 целых чисел.
 Первым числом идёт само число N.
 Далее следуют ещё N чисел, обозначим их за массив A.
 Между собой числа разделены пробелом.

 Отсортируйте массив А по модулю и выведите его в стандартный поток.

 Ограничения

 0 <= N <= 1000
 -1000000 <= A[i] <= 1000000

 Примеры

 stdin		stdout
 2 -4 3		3 -4
 3 1 -3 2	1 2 -3
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int N = 0, number = 0;
	vector<int> numbers;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number;
		numbers.push_back(number);
	}

	sort(begin(numbers), end(numbers), [](const int &x1, const int &x2) {
		return (x1 < 0 ? -x1 : x1) < (x2 < 0 ? -x2 : x2);
	});

	for (const auto &i : numbers) {
		cout << i << ' ';
	}

	return 0;
}
