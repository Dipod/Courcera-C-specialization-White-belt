/*
 Итак, теперь у нас с вами есть полноценный тип для представления обыкновенных дробей:
 класс Rational интегрирован в язык с помощью перегрузки операторов и не позволяет выполнять
 некорректные операции за счёт выбрасывания исключений.
 Давайте на основе класса Rational создадим простой калькулятор для обыкновенных дробей.

 Вам надо написать программу, которая считывает из стандартного ввода одну строку в формате
 ДРОБЬ_1 операция ДРОБЬ_2. ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое, а Y — целое неотрицательное число.
 операция — это один из символов '+', '-', '*', '/'.

 Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью,
 ваша программа должна вывести в стандартный вывод сообщение "Invalid argument".
 Если считанная операция — это деление на ноль, выведите в стандартный вывод сообщение "Division by zero".
 В противном случае выведите результат операции.

 Пример
 stdin		stdout
 1/2 + 1/3	5/6
 1/2 + 5/0	Invalid argument
 4/5 / 0/8	Division by zero
 */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <exception>

using namespace std;

int lcm(const int &first, const int &second) {
	return (first / __gcd(first, second)) * second;
}

class Rational {
public:
	Rational() {
		m_numerator = 0;
		m_denominator = 1;
	}

	Rational(const int &numerator, const int &denominator) {
		if (denominator == 0) {
			throw invalid_argument("Invalid argument");
		}
		if (numerator == 0) {
			m_numerator = 0;
			m_denominator = 1;
			return;
		}

		int divisor = __gcd(numerator, denominator);
		m_numerator = numerator / divisor;
		m_denominator = denominator / divisor;

		if (m_denominator < 0) {
			m_numerator = -m_numerator;
			m_denominator = -m_denominator;
		}
	}

	int Numerator() const {
		return m_numerator;
	}

	int Denominator() const {
		return m_denominator;
	}

private:
	int m_numerator;
	int m_denominator;
};

bool operator==(const Rational &lhs, const Rational &rhs) {
	return (lhs.Numerator() == rhs.Numerator()
			&& lhs.Denominator() == rhs.Denominator());
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
	} else {
		int new_denominator = lcm(lhs.Denominator(), rhs.Denominator());
		int new_numerator = (new_denominator / lhs.Denominator())
				* lhs.Numerator()
				+ (new_denominator / rhs.Denominator()) * rhs.Numerator();
		return Rational(new_numerator, new_denominator);
	}
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
	} else {
		int new_denominator = lcm(lhs.Denominator(), rhs.Denominator());
		int new_numerator = (new_denominator / lhs.Denominator())
				* lhs.Numerator()
				- (new_denominator / rhs.Denominator()) * rhs.Numerator();
		return Rational(new_numerator, new_denominator);
	}
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.Numerator() * rhs.Numerator(),
			lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}

	return Rational(lhs.Numerator() * rhs.Denominator(),
			lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream &stream, Rational &fraction) {
	int numerator = fraction.Numerator(), denominator = fraction.Denominator();
	char separator = ' ';

	stream >> numerator >> separator >> denominator;

	if (!stream.fail() && separator == '/') {
		fraction = Rational(numerator, denominator);
	}

	return stream;
}

ostream& operator<<(ostream &stream, const Rational &fraction) {
	stream << fraction.Numerator() << '/' << fraction.Denominator();
	return stream;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		return lhs.Numerator() < rhs.Numerator();
	} else {
		int new_denominator = lcm(lhs.Denominator(), rhs.Denominator());
		return (new_denominator / lhs.Denominator()) * lhs.Numerator()
				< (new_denominator / rhs.Denominator()) * rhs.Numerator();
	}
}

int main() {

	Rational lhs, rhs;
	char operation;

	try {
		cin >> lhs >> operation >> rhs;
	} catch (invalid_argument &ex) {
		cout << ex.what();
		return 0;
	}

	if (cin.fail()) {
		cout << "Invalid argument";
		return 0;
	}

	switch (operation) {
	case '/':
		try {
			cout << lhs / rhs;
		} catch (domain_error &ex) {
			cout << ex.what();
		}
		break;
	case '*':
		cout << lhs * rhs;
		break;
	case '-':
		cout << lhs - rhs;
		break;
	case '+':
		cout << lhs + rhs;
		break;
	default:
		cout << "Invalid argument";
		break;
	}

	return 0;
}
