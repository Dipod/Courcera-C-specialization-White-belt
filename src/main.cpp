/*Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v,
 * в которой числа переставлены в обратном порядке.*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v);

int main() {

	vector<int> numbers = { 1, 5, 3, 4, 2 };
	vector<int> reversed = Reversed(numbers);

	for (auto &item : reversed) {
		cout << item << ' ';
	}
	return 0;
}
