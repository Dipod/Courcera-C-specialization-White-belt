/*Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.*/

#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v);

int main() {

	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);

	for (auto &item : numbers) {
		cout << item << ' ';
	}
	return 0;
}
