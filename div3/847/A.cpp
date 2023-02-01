#include <iostream>

using namespace std;

const string PI = "3141592653589793238462643383279";

void solve() {
  string s;
  cin >> s;

  for(int i = 0; i < s.size(); i += 1) {
    if(s[i] != PI[i]) {
      cout << i << endl;
      return;
    }
  }
  cout << s.size() << endl;
}

int main() {
  int T;

  cin >> T;
  while(T-- > 0) {
    solve();
  }

  return 0;
}
