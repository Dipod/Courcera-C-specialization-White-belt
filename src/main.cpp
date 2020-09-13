/*На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	unsigned int N;
	vector<short int> result;

	cin >> N;

	while (N > 1) {
		result.push_back(N % 2);
		N /= 2;
	}

	result.push_back(N);

	bool beginOutoutFlag = false;
	for (int i = result.size() + 1; i >= 0; i--) {
		if (!beginOutoutFlag && result[i] == 1) {
			beginOutoutFlag = true;
		}
		if (beginOutoutFlag) {
			cout << result[i];
		}
	}
	return 0;
}
