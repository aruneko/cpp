#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int main() {
  random_device rd; 
  mt19937 mt(rd());
  int r[10] = {};

	for (auto &t: r) {
		t = mt() % 1000;
	}

  sort(r, r + sizeof(r)/r[0]);

	for (auto &t: r) {
		cout << t << endl;
	}
}
