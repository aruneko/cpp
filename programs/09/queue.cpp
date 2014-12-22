#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> qu; 

  qu.push(0);
  qu.push(1);
  qu.push(2);

  for (int i = 0, l = qu.size(); i < l; i++) {
    cout << qu.front() << endl;
    qu.pop();
  }
}
