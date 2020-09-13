#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s) {

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

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
	for (auto s : words) {
		if (IsPalindrom(s) && s.size() >= minLength) {
			result.push_back(s);
		}
	}
	return result;
}
