#include <iostream>
using namespace std;

int main() {
	int x;

	cout << "整数を入力してください：";
	cin >> x;

	if (x > 0) {
		cout << "入力した数は正の数です" << endl;
	} else if (x == 0) {
		cout << "入力した数は0です" << endl;
	} else {
		cout << "入力した数は負の数です" << endl;
	}
}
