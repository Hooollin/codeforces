#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    sum += t;
  }
  cout << (sum % 2 ? "NO" : "YES") << endl;
}

int main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
