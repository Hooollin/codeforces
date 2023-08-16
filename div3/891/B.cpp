#include <iostream>
#include <string>

using namespace std;

void solve() {
  string t, ans;
  cin >> t;
  int carry = 0;
  int n = t.size();
  int check_start = -2;
  for (int i = 0; i < n; i++) {
    if (t[i] >= '5') {
      check_start = i - 1;
      break;
    }
  }
  if (check_start == -2) {
    cout << t << endl;
    return;
  }
  while (check_start >= 0 && t[check_start] >= '4') {
    --check_start;
  }
  if (check_start < 0) {
    cout << 1 << string(n, '0') << endl;
    return;
  }
  cout << t.substr(0, check_start) << (char)(t[check_start] + 1)
       << string(n - check_start - 1, '0') << endl;
}
int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
