#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);

  cout << vec.size() << endl;

  vec.resize(50);
  cout << vec.size() << endl;

  vec[38] = 29; 
  cout << vec[38] << endl;
}
