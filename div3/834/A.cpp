#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  auto check = [](string t) {
    int n = t.size();
    if(n % 3) return false;
    string p = "Yes";
    for(int i = 0; i < n; i += 3) {
      for(int j = 0; j < 3; j++) {
        if(t[i + j] != p[j]) return false;
      }
    }
    return true;
  };

  bool good = false;
  string pre[3] = {"", "Y", "Ye"}, suf[3] = {"", "es", "s"};
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(check(pre[i] + s + suf[j])) {
        good = true;
        break;
      }
    }
  }
  cout << (good ? "YES" : "NO") << endl;
}

int main() {
  int T;
  cin >> T;
  
  while(T-- > 0) {
    solve();
  }

  return 0;
}

