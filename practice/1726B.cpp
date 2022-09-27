#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if(n > m) {
    cout << "NO" << endl;
    return;
  }
  if(n % 2 == 0 && m % 2 != 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  int ones = n;
  int left = 0;
  if(n % 2) {
    ones = n - 1;
    left = 1;
  }else{ 
    ones = n - 2;
    left = 2;
  }
  for(int i = 0; i < ones; i++) {
    cout << 1 << " ";
  }
  for(int i = 0; i < left; i++) {
    cout << ((m - ones) / left) << " ";
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  while(T-- > 0) {
    solve();
  }
}