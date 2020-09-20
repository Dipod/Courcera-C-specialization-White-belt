/*
 Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и ToString для получения строки.
 Пример
 Код

 int main() {
 ReversibleString s("live");
 s.Reverse();
 cout << s.ToString() << endl;

 s.Reverse();
 const ReversibleString& s_ref = s;
 string tmp = s_ref.ToString();
 cout << tmp << endl;

 ReversibleString empty;
 cout << '"' << empty.ToString() << '"' << endl;

 return 0;
 }

 Вывод

 evil
 live
 ""

 */

#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		s = "";
	}

	ReversibleString(const string &new_s) {
		s = new_s;
	}

	void Reverse() {
		int begin = 0, end = s.size() - 1;
		while (begin < end) {
			auto tmp = s[begin];
			s[begin] = s[end];
			s[end] = tmp;
			begin++;
			end--;
		}
	}

	string ToString() const {
		return s;
	}

private:
	string s;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString &s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}
