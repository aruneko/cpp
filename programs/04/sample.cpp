#include <iostream>
using namespace std;

int main() {
	int i(5);
	double d(6.9);
	char c('a');

	cout << "変数i = " << i << "; "
		<< "iは" << sizeof(i) << "byteです" << endl;
	cout << "変数d = " << d << "; "
		<< "dは" << sizeof(d) << "byteです" << endl;
	cout << "変数c = " << c << "; "
		<< "cは" << sizeof(c) << "byteです" << endl;

	cout << "i + d = " << i + d << "; "
		<< sizeof(i + d) << "byteです" << endl;
	cout << "i + (int)c = " << i + (int)c << "; "
		<< sizeof(i + (int)c) << "byteです" << endl;
	cout << "i + static_cast<int>(d) = " << i + static_cast<int>(d) << "; "
		<< sizeof(i + static_cast<int>(d)) << "byteです" << endl;
}
