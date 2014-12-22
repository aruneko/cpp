#include <iostream>
using namespace std;

int main() {
	int n;

	cout << "自然数を入力してください：";
	cin >> n;

	int x[n];

	for (int i = 0; i < n; i++) {
		x[i] = i;
	}

	for (auto t : x) {
		cout << t << endl;
	}

	cout << endl;

	for (auto &t : x) {
		t += 10; 
	}

	for (auto &t : x) {
		cout << t << endl;
	}
}
