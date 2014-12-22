#include <iostream>
using namespace std;

int main() {
	int x, y;

	do {
		cin >> x >> y;
		cin.clear();
		cin.ignore();
	} while (x <= 0 || y <= 0);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << "#";
		}
		cout << endl;
	}
}
