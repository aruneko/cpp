#include <iostream>
#include <new>
using namespace std;

int main() {
	int n, *d; 
	cout << "自然数を入力してください：";
	cin >> n;

	try {
		d = new int[n];
	} catch (bad_alloc& e) {
		cout << "オブジェクトの生成に失敗しました\n";
		cout << e.what() << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		*(d + i) = i;
	}

	for (int i = 0; i < n; i++) {
		cout << i[d] << " ";
	}
	cout << endl;

	delete [] d;
}
