#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m, s;
  cin >> m >> s;

  vector<int> B;
  for(int i = 0; i < m; i++) {
    int b;
    cin >> b;

    B.push_back(b);
  }
  sort(B.begin(), B.end());

  int maxv = 0;
  set<int> have;
  for(auto &v : B) {
    have.insert(v);
    maxv = max(maxv, v);
  }
  
  for(int i = 1; i < maxv; i++) {
      if(have.find(i) == have.end()) {
        s -= i;
      }
  }
  if(s < 0) {
    cout << "NO" << endl;
    return;
  }
  
  // (a + b) * (b - a + 1) = 2 * s;
  bool good = (s == 0);
  for(int b = maxv + 1; b < 2000; b++) {
    if((maxv + b + 1) * (b - maxv) == 2 * s) {
      good = true;
      break;
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
