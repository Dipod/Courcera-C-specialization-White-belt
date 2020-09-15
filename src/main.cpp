/*Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
 * Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того,
 * что очередь не продвигается.
 * Реализуйте обработку следующих операций над очередью:
 *     WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
 *     QUIET i: пометить i-го человека как успокоившегося;
 *     COME k: добавить k спокойных человек в конец очереди;
 *     COME -k: убрать k человек из конца очереди;
 *     WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 *
 * Изначально очередь пуста.
 *
 * Формат ввода
 *
 * Количество операций Q, затем описания операций.
 *
 * Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.
 *
 * Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.
 *
 * Формат вывода
 *
 * Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void worry(vector<bool> &queue) {

	int i = 0;
	cin >> i;
	queue[i] = true;

}

void quiet(vector<bool> &queue) {

	int i = 0;
	cin >> i;
	queue[i] = false;

}

void come(vector<bool> &queue) {

	int i = 0;
	cin >> i;
	queue.resize(queue.size() + i);

}

void worry_count(const vector<bool> &queue) {

	int counter = 0;

	for (const auto &person : queue) {
		if (person) {
			counter++;
		}
	}
	cout << counter << endl;
}

int main() {

	vector<bool> queue;
	string command;
	int Q = 0;

	cin >> Q;

	while (Q > 0) {
		cin >> command;
		if (command == "WORRY") {
			worry(queue);
		}
		if (command == "QUIET") {
			quiet(queue);
		}
		if (command == "COME") {
			come(queue);
		}
		if (command == "WORRY_COUNT") {
			worry_count(queue);
		}
		Q--;
	}

	return 0;
}
