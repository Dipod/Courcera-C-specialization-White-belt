/*У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца:
 * оплата счетов за электричество, абонентская плата за связь и пр.
 * Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:
 *
 * ADD i s
 * Назначить дело с названием s на день i текущего месяца.
 *
 * DUMP i
 * Вывести все дела, запланированные на день i текущего месяца.
 *
 * NEXT
 * Перейти к списку дел на новый месяц. При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся и
 * становится активным (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список.
 * После выполнения данной команды новый список дел и следующий месяц становятся текущими, а работа со старым списком дел прекращается.
 * При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:
 * 		если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
 * 		если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить
 * 		на последний день следующего месяца.
 *
 * Замечания
 *
 * Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца.
 * Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
 *
 * Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
 * Начальным текущим месяцем считается январь.
 * Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
 *
 * Формат ввода
 *
 * Сначала число операций Q, затем описания операций.
 *
 * Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания.
 * Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.
 *
 * Формат вывода
 *
 * Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом.
 * Порядок вывода дел в рамках каждой операции значения не имеет.
 *
 * Пример
 *
 * Ввод
 *
 * 12
 * ADD 5 Salary
 * ADD 31 Walk
 * ADD 30 WalkPreparations
 * NEXT
 * DUMP 5
 * DUMP 28
 * NEXT
 * DUMP 31
 * DUMP 30
 * DUMP 28
 * ADD 28 Payment
 * DUMP 28
 *
 * Вывод
 *
 * 1 Salary
 * 2 WalkPreparations Walk
 * 0
 * 0
 * 2 WalkPreparations Walk
 * 3 WalkPreparations Walk Payment
 *
 * Указание
 *
 * Для дописывания всех элементов вектора v2 в конец вектора v1 удобно использовать метод insert:
 * v1.insert(end(v1), begin(v2), end(v2));
 *
 * Кроме того, элементом вектора может быть любой тип, в том числе и другой вектор.
 * Например, vector<vector<int>> — это вектор, элементами которого являются вектора целых чисел (то есть двумерный массив).
 * Пример использования:
 *
 * vector<vector<int>> m(10); // Создаём вектор из десяти векторов целых чисел
 * m[0].push_back(5);  // Добавляем элементы в первый вектор
 * m[0].push_back(15);
 * cout << m[0][1]; // Выведет 15 — второй элемент первого вектора
 *
 * m[1].push_back(3);
 * for (int x : m[1]) {
 *     // Перебираем все элементы второго
 * }*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Schedule {
private:
	int m_currentMonth;
	vector<vector<vector<string>>> m_tasks;

	int nextMonth() {

		int nextMonth = m_currentMonth + 1;
		if (nextMonth == 12) {
			return 0;
		}
		return nextMonth;
	}

public:
	Schedule() {
		m_currentMonth = 0;
		m_tasks.resize(12);
		m_tasks[0].resize(31);
		m_tasks[1].resize(28);
		m_tasks[2].resize(31);
		m_tasks[3].resize(30);
		m_tasks[4].resize(31);
		m_tasks[5].resize(30);
		m_tasks[6].resize(31);
		m_tasks[7].resize(31);
		m_tasks[8].resize(30);
		m_tasks[9].resize(31);
		m_tasks[10].resize(30);
		m_tasks[11].resize(31);
	}

	void add(const int &day, const string &task) {
		m_tasks[m_currentMonth][day - 1].push_back(task);
	}

	void dump(const int &day) {
		cout << m_tasks[m_currentMonth][day - 1].size();
		for (const auto &task : m_tasks[m_currentMonth][day - 1]) {
			cout << ' ' << task;
		}
		cout << endl;
	}

	void next() {
		int nextMonth = this->nextMonth();
		int dayDelta = m_tasks[m_currentMonth].size()
				- m_tasks[nextMonth].size();
		int nextMonthSize = m_tasks[nextMonth].size();
		if (dayDelta == 0) {
			m_tasks[nextMonth] = m_tasks[m_currentMonth];
		} else if (dayDelta < 0) {
			m_tasks[nextMonth] = m_tasks[m_currentMonth];
			m_tasks[nextMonth].resize(nextMonthSize);
		} else {
			for (int i = 0; i < nextMonthSize; i++) {
				m_tasks[nextMonth][i] = m_tasks[m_currentMonth][i];
			}

			while (dayDelta > 0) {
				m_tasks[nextMonth][nextMonthSize - 1].insert(
						end(m_tasks[nextMonth][nextMonthSize - 1]),
						begin(
								m_tasks[m_currentMonth][nextMonthSize - 1
										+ dayDelta]),
						end(
								m_tasks[m_currentMonth][nextMonthSize - 1
										+ dayDelta]));
				dayDelta--;
			}
		}
		m_currentMonth = nextMonth;
	}

};

int main() {

	string command = "", task = "";
	int Q = 0, day = 0;
	Schedule taskTracker;

	cin >> Q;

	while (Q > 0) {
		cin >> command;
		if (command == "ADD") {
			cin >> day >> task;
			taskTracker.add(day, task);
		}
		if (command == "DUMP") {
			cin >> day;
			taskTracker.dump(day);
		}
		if (command == "NEXT") {
			taskTracker.next();
		}

		Q--;
	}

	return 0;
}
