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
  cout << T << " " << F << endl;

  int maxZ = min(T, F);
  long long maxv = 0;
  long long b = 1;
  for(int j = 0; j <= 13; j++) {
    for(int i = 0; i < 32; i++) {
      long long a = (long long)1 << i;
      if(a * b > m) {
        continue;
      }
      int Z = min(i + T, j + F);
      if(Z > maxZ) {
        maxZ = Z;
        maxv = a * b;
      }
      if(Z == maxZ && maxv < a * b) {
        maxv = a * b;
      }
    }
    b *= 5;
  }
  cout << "maxZ: " << maxZ << ", maxv:" << maxv << endl;
  cout << (maxZ == 0 ? n * m : n * maxv * (m / maxv)) << endl;
}

int main() {
  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }
}
