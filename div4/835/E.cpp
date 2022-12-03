#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  
  vector<int> bits, zeros(n, 0), ones(n, 0);
  for(int i = 0; i < n; i++) {
    int b;
    cin >> b;

    bits.push_back(b);
  }

  for(int cnt = 0, i = n - 1; i >= 0; i--) {
    if(bits[i] == 0) ++cnt;
    zeros[i] = cnt;
  }
  for(int cnt = 0, i = 0; i < n; i++) {
    if(bits[i] == 1) ++cnt;
    ones[i] = cnt;
  }

  long long base = 0;
  for(int i = 0; i < n; i++) {
    if(bits[i] == 1) {
      base += zeros[i];
    }
  }

  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int diff = 0;
    if(bits[i] == 1) {
      diff = -zeros[i] + ones[i] - 1;
    }else {
      diff = -ones[i] + zeros[i] - 1;
    }
    ans = max(ans, base + diff);
    ans = max(ans, base);
  }

  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }
  return 0;
}
