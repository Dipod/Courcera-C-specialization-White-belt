/*Дана строка.
 * Найдите в этой строке второе вхождение буквы f и выведите индекс этого вхождения.
 * Если буква f в данной строке встречается только один раз, выведите число -1,
 * а если не встречается ни разу, выведите число -2.
 * Индексы нумеруются с нуля.*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	unsigned int occurenceIterator = 0;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'f') {
			occurenceIterator++;
		}
		if (occurenceIterator == 2) {
			cout << i;
			return 0;
		}
	}

	if (occurenceIterator == 0) {
		cout << -2;
	} else if (occurenceIterator == 1) {
		cout << -1;
	}

	return 0;
}
