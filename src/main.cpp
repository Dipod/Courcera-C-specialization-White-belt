/*Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
 * и дописывает все строки из первого вектора в конец второго.
 * После выполнения функции вектор source должен оказаться пустым.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination);

int main() {

	vector<string> source = { "a", "b", "c" };
	vector<string> destination = { "z" };

	MoveStrings(source, destination);

	for (auto &item : destination) {
		cout << item << ' ';
	}
	return 0;
}
