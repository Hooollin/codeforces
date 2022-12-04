#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  auto num_factors = [](int n, int f) {
    int cnt = 0;
    while(n % f == 0) {
      n /= f;
      ++cnt;
    }
    return cnt;
  };
  int T = num_factors(n, 2), F = num_factors(n, 5);

  int k = 1;
  while(T < F && k * 2 <= m) {
    ++T;
    k *= 2;
  }
  
  while(F < T && k * 5 <= m) {
    ++F;
    k *= 5;
  }

  while(k * 10 <= m) {
    ++T, ++F;
    k *= 10;
  }

  if(k == 1) {
    cout << n * m << endl;
    return;
  }

  cout << (n * k * (m / k)) << endl;
}

int main() {
  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }
}
