#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> st; 

  st.push(0);
  st.push(1);
  st.push(2);

  for (int i = 0, l = st.size(); i < l; i++) {
    cout << st.top() << endl;
    st.pop();
  }
}
