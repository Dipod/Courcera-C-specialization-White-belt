#include <string>

bool IsPalindrom(std::string s) {

	int end = s.size() - 1;

	if (end == -1) {
		return true;
	}

	int begin = 0;
	while (begin < end) {
		if (s[begin] == s[end]) {
			begin++;
			end--;
		} else {
			return false;
		}
	}

	return true;

}
