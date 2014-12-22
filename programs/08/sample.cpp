#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 = "Hello ";
	string str2("World");
	
	cout << str1 + str2 << "\n";
	printf("%s\n", (str1 + str2).c_str());

	string str3;
	getline(cin, str3);
	cout << "str3 = " << str3 << "\n";
	cout << "str3の長さは" << str3.size() << "です" << endl;
}
