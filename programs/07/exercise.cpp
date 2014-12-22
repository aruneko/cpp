#include <iostream>
using namespace std;

template <class T>
void mySwap(T &x, T &y) {
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int x, y;
	cin >> x >> y;
	mySwap(x, y); 
	cout << x << " " << y << endl;

	char a, b;
	cin >> a >> b;
	mySwap(a, b); 
	cout << a << " " << b << endl;
}
