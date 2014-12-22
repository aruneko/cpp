#include <iostream>
using namespace std;

int main() {
	int n;

	do {
		cout << "自然数を入力してください：";
		cin >> n;
		cin.clear();
		cin.ignore();
	} while (n <= 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "#";
		}
		cout << endl;
	}
}
