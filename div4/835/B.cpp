#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T-- > 0) {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      char ch;
      cin >> ch;
      ans = max(ch - 'a' + 1, ans);
    }
    cout << ans << endl;
  }
  return 0;
}
