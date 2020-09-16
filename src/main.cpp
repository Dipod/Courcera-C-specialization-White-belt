/*
 Два слова называются синонимами друг друга, если они имеют похожие значения.
 Реализуйте следующие операции над словарём синонимов:

 ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
 COUNT word — узнать количество синонимов слова word.
 CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
 Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.

 Замечание

 Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, если A - синоним B,
 а B - синоним C, то из этого НЕ следует, что A - синоним C.

 Формат ввода

 Сначала вводится количество запросов Q, затем Q строк с описаниями запросов.
 Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны.
 Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.

 Формат вывода

 Для каждого запроса в соответствующей строке выведите ответ на него:

 В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
 В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.

 Пример

 Ввод

 8
 ADD program code
 COUNT cipher
 ADD code cipher
 COUNT code
 COUNT program
 CHECK code program
 CHECK program cipher
 CHECK cpp java

 Вывод

 0
 2
 1
 YES
 NO
 NO
 */

#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class Synonyms {
private:
	map<string, set<string>> m_synonyms;
public:

	void add(const string &word1, const string &word2) {
		m_synonyms[word1].insert(word2);
		m_synonyms[word2].insert(word1);
	}

	void count(const string &word) {
		cout << m_synonyms[word].size() << endl;
	}

	void check(const string &word1, const string &word2) {
		cout << (m_synonyms[word1].count(word2) > 0 ? "YES" : "NO") << endl;
	}
};

int main() {

	string command = "", word1 = "", word2 = "";
	int Q = 0;
	Synonyms synonyms;

	cin >> Q;

	while (Q > 0) {
		cin >> command;
		if (command == "ADD") {
			cin >> word1 >> word2;
			synonyms.add(word1, word2);
		}
		if (command == "COUNT") {
			cin >> word1;
			synonyms.count(word1);
		}
		if (command == "CHECK") {
			cin >> word1 >> word2;
			synonyms.check(word1, word2);
		}
		Q--;
	}

	return 0;
}
