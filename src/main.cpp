/*
 Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения.
 Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.

 Формат ввода

 Первая строка содержит одно целое число N от 0 до 10000 — число студентов.

 Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию очередного студента,
 и три целых числа от 0 до 1000000000 — день, месяц и год рождения.

 Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.

 Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, и целое число от 0 до 1000000000 — номер студента
 (нумерация начинается с 1).

 Формат вывода

 Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.

 Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.

 Для остальных запросов выведите bad request.

 Пример ввода

 3
 Ivan Ivanov 1 1 1901
 Petr Petrox 2 2 1902
 Alexander Sidorov 3 3 1903
 3
 name 1
 date 3
 mark 5

 Пример вывода

 Ivan Ivanov
 3.3.1903
 bad request



 Correct output:

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
	string first_name;
	string last_name;
	unsigned int day_of_birth;
	unsigned int month_of_birth;
	unsigned int year_of_birth;

	void PrintName() const {
		cout << first_name + ' ' + last_name;
	}

	void PrintDate() const {
		string result = to_string(day_of_birth) + '.'
				+ to_string(month_of_birth) + '.' + to_string(year_of_birth);
		cout << result;
	}
};

int main() {

	int n;
	cin >> n;

	vector<Student> students(n);

	for (auto &student : students) {
		cin >> student.first_name >> student.last_name >> student.day_of_birth
				>> student.month_of_birth >> student.year_of_birth;
	}

	int m;
	cin >> m;
	string command;
	int i;
	while (m > 0) {
		cin >> command;
		cin >> i;
		i--;
		if (command == "name") {
			if (i >= 0 && i < students.size()) {
				students[i].PrintName();
				cout << endl;
			} else {
				cout << "bad request" << endl;
			}

		} else if (command == "date") {
			if (i >= 0 && i < students.size()) {
				students[i].PrintDate();
				cout << endl;
			} else {
				cout << "bad request" << endl;
			}
		} else {
			cout << "bad request" << endl;
		}
		m--;
	}

	return 0;
}
