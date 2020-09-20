/*
 В этом задании вам предстоит написать две небольшие программы.
 Каждый пункт - отдельная задача, решение отправляйте в поле с соответствующим номером.

 Часть 1

 Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
 Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

 Пример

 input.txt

 Keep calm
 and
 learn C++

 stdout

 Keep calm
 and
 learn C++

 Часть 2

 Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt .
 Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.

 Пример

 input.txt

 Keep calm
 and
 learn C++

 output.txt

 Keep calm
 and
 learn C++
 */

#include <fstream>

using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	string line;
	if (input.is_open()) {
		while (getline(input, line)) {
			output << line << endl;
		}
	}

	return 0;
}
