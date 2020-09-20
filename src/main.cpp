/*
 Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:

 class Person {
 public:
 void ChangeFirstName(int year, const string& first_name) {
 // добавить факт изменения имени на first_name в год year
 }
 void ChangeLastName(int year, const string& last_name) {
 // добавить факт изменения фамилии на last_name в год year
 }
 string GetFullName(int year) {
 // получить имя и фамилию по состоянию на конец года year
 }
 string GetFullNameWithHistory(int year) {
 // получить все имена и фамилии по состоянию на конец года year
 }
 private:
 // приватные поля
 };

 В отличие от метода GetFullName,
 метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию к концу данного года,
 но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке.
 Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же,
 второе изменение при формировании истории нужно игнорировать.

 Для лучшего понимания формата см. примеры.

 Пример 1

 Код

 int main() {
 Person person;

 person.ChangeFirstName(1900, "Eugene");
 person.ChangeLastName(1900, "Sokolov");
 person.ChangeLastName(1910, "Sokolov");
 person.ChangeFirstName(1920, "Evgeny");
 person.ChangeLastName(1930, "Sokolov");
 cout << person.GetFullNameWithHistory(1940) << endl;

 return 0;
 }

 Вывод

 Evgeny (Eugene) Sokolov

 Пример 2

 Код

 int main() {
 Person person;

 person.ChangeFirstName(1965, "Polina");
 person.ChangeLastName(1967, "Sergeeva");
 for (int year : {1900, 1965, 1990}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 person.ChangeFirstName(1970, "Appolinaria");
 for (int year : {1969, 1970}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 person.ChangeLastName(1968, "Volkova");
 for (int year : {1969, 1970}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 person.ChangeFirstName(1990, "Polina");
 person.ChangeLastName(1990, "Volkova-Sergeeva");
 cout << person.GetFullNameWithHistory(1990) << endl;

 person.ChangeFirstName(1966, "Pauline");
 cout << person.GetFullNameWithHistory(1966) << endl;

 person.ChangeLastName(1960, "Sergeeva");
 for (int year : {1960, 1967}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 person.ChangeLastName(1961, "Ivanova");
 cout << person.GetFullNameWithHistory(1967) << endl;

 return 0;
 }

 Вывод

 Incognito
 Polina with unknown last name
 Polina Sergeeva
 Polina Sergeeva
 Appolinaria (Polina) Sergeeva
 Polina Volkova (Sergeeva)
 Appolinaria (Polina) Volkova (Sergeeva)
 Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
 Pauline (Polina) with unknown last name
 Sergeeva with unknown first name
 Pauline (Polina) Sergeeva
 Pauline (Polina) Sergeeva (Ivanova, Sergeeva)

 Пример 3

 Код

 int main() {
 Person person;

 person.ChangeFirstName(1965, "Polina");
 person.ChangeFirstName(1965, "Appolinaria");

 person.ChangeLastName(1965, "Sergeeva");
 person.ChangeLastName(1965, "Volkova");
 person.ChangeLastName(1965, "Volkova-Sergeeva");

 for (int year : {1964, 1965, 1966}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 return 0;
 }

 Вывод

 Incognito
 Appolinaria Volkova-Sergeeva
 Appolinaria Volkova-Sergeeva

 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
	void ChangeFirstName(const int &year, const string &first_name) {
		first_name_changes[year] = first_name;
	}

	void ChangeLastName(const int &year, const string &last_name) {
		last_name_changes[year] = last_name;
	}

	string GetFullName(const int &year) const {
		string first_name = GetName(year, first_name_changes);
		string last_name = GetName(year, last_name_changes);

		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}

		if (first_name.empty()) {
			return last_name + " with unknown first name";
		}

		if (last_name.empty()) {
			return first_name + " with unknown last name";
		}

		return first_name + ' ' + last_name;
	}
	string GetFullNameWithHistory(const int &year) const {
		string first_name = GetName(year, first_name_changes);
		string last_name = GetName(year, last_name_changes);

		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}

		if (first_name.empty()) {
			return last_name
					+ GetNameHistory(year, last_name_changes, last_name)
					+ " with unknown first name";
		}

		if (last_name.empty()) {
			return first_name
					+ GetNameHistory(year, first_name_changes, first_name)
					+ " with unknown last name";
		}

		return first_name + GetNameHistory(year, first_name_changes, first_name)
				+ ' ' + last_name
				+ GetNameHistory(year, last_name_changes, last_name);
	}

private:

	string GetName(const int &year,
			const map<int, string, greater<int>> &name_changes) const {

		string name = "";
		for (const auto &item : name_changes) {
			if (item.first <= year) {
				name = item.second;
				break;
			}
		}
		return name;
	}

	string GetNameHistory(const int &year,
			const map<int, string, greater<int>> &name_changes,
			string name) const {

		vector<string> names;
		for (const auto &item : name_changes) {
			if (item.first <= year && name != item.second) {
				name = item.second;
				names.push_back(name);
			}
		}

		if (names.size() == 0) {
			return "";
		} else {
			string result = " (";
			for (const auto &name : names) {
				result += name + ", ";
			}
			result.pop_back();
			result.back() = ')';
			return result;
		}
	}

	map<int, string, greater<int>> first_name_changes;
	map<int, string, greater<int>> last_name_changes;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeFirstName(1965, "Appolinaria");

	person.ChangeLastName(1965, "Sergeeva");
	person.ChangeLastName(1965, "Volkova");
	person.ChangeLastName(1965, "Volkova-Sergeeva");

	for (int year : { 1964, 1965, 1966 }) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
