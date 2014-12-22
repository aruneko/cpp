#include <iostream>
using namespace std;

inline int max(int x, int y) {
	return (x > y) ? x : y;
}

int add(int x, int y = 2) {
	return x + y;
}

int add2(int x) {
	return x + 2;
}

double add2(double x) {
	return x + 2;
}

template <class T>
T add2T(T x) {
	return x + 2;
}

int main() {
	cout << "max(5,3) = " << max(5, 3) << "\n";
	cout << "add(5) = " << add(5) << "\n";
	cout << "add(5, 3) = " << add(5, 3) << "\n";
	cout << "add2(9) = " << add2(9) << "\n";
	cout << "add2(3.7) = " << add2(3.7) << "\n";
	cout << "add2T(4.6) = " << add2T(4.6) << "\n";
	cout << "add2T(6) = " << add2T(6) << "\n";
	cout << "Lamda(2 * 6) = " << [](int x){return x * 2;}(6) << endl;
}
