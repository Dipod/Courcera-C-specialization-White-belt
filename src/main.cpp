/*На вход вашей программы в стандартном потоке ввода подаются действительные
 * коэффициенты A, B и C уравнения Ax² + Bx + C = 0.
 * Выведите все его различные действительные корни в поток вывода в любом порядке,
 * при этом разделяя корни пробелами. Гарантируется, что хотя бы один из коэффициентов уравнения
 * не равен нулю.*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double a, b, c;
	cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
			cout << "";
		} else if (c == 0){
			cout << 0;
		} else {
			cout << -c / b;
		}
	} else {
		double discr = b * b - 4 * a * c;

		if (discr < 0) {
			cout << "";
		} else if (discr == 0) {
			cout << -b / (2 * a);
		} else {
			double x1 = (-b + sqrt(discr)) / (2 * a);
			double x2 = (-b - sqrt(discr)) / (2 * a);
			cout << x1 << ' ' << x2;
		}
	}

	return 0;
}
