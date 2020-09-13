/*Дано два целых числа A и B (A <= B, A >= 1, B <= 30000). Выведите через пробел все чётные числа от A до B (включительно).*/

#include <iostream>
using namespace std;

int main() {

	unsigned short int A, B;

	cin >> A >> B;

	for (unsigned short int i = A; i <= B; i++) {
		if (i % 2 == 0) {
			cout << i;
			if (i != B) {
				cout << ' ';
			}
		}
	}

	return 0;
}
