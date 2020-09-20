/*
 Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

 При получении на вход года, который меньше года рождения:

 методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
 методы ChangeFirstName и ChangeLastName должны игнорировать запрос.

 Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

 Пример

 Код

 int main() {
 Person person("Polina", "Sergeeva", 1960);
 for (int year : {1959, 1960}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 person.ChangeFirstName(1965, "Appolinaria");
 person.ChangeLastName(1967, "Ivanova");
 for (int year : {1965, 1967}) {
 cout << person.GetFullNameWithHistory(year) << endl;
 }

 return 0;
 }

 Вывод

 No person
 Polina Sergeeva
 Appolinaria (Polina) Sergeeva
 Appolinaria (Polina) Ivanova (Sergeeva)
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string &first_name, const string &last_name, const int &year) {
		first_name_changes[year] = first_name;
		last_name_changes[year] = last_name;
		birth_year = year;
	}

	void ChangeFirstName(const int &year, const string &first_name) {
		if (year >= birth_year) {
			first_name_changes[year] = first_name;
		}
	}

	void ChangeLastName(const int &year, const string &last_name) {
		if (year >= birth_year) {
			last_name_changes[year] = last_name;
		}
	}

	string GetFullName(const int &year) const {

		if (year < birth_year) {
			return "No person";
		}

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

		if (year < birth_year) {
			return "No person";
		}

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
	int birth_year;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : { 1959, 1960 }) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : { 1965, 1967 }) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
