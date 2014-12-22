#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	if (n > 0) {
		if (!(n % 3)) {
			cout << n << "は3で割り切れます" << endl;
		} else {
			cout << n << "は3で割り切れません" << endl;
		}
	} else {
		cout << "入力値が不正です" << endl;
	}
}
