#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <vector>

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
	{
		const set<Rational> rs = { { 1, 2 }, { 1, 25 }, { 3, 4 }, { 3, 4 }, { 1,
				2 } };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational> { { 1, 25 }, { 1, 2 }, { 3, 4 } }) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[ { 1, 2 }];
		++count[ { 1, 2 }];

		++count[ { 2, 3 }];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
