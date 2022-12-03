#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long n, c, d;
  cin >> n >> c >> d;
  
  vector<int> A;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end(), greater<int>());

  auto check = [&](int k) {
    k = k + 1;
    //cout << "k: " << k << endl;
    int mod = d % k, rnd = d / k;
    long long tot = 0;
    //cout << "mod, rnd: "<< mod << " " << rnd << endl;
    for(int i = 0; i < min((long long)k, n); i++) {
      int extra = i < mod;
      tot += (long long)(rnd + extra) * A[i];
      //cout << i << ": " << tot << endl;
      if(tot >= c) {
        return true;
      }
    }
    return false;
  };

  int l = 0, r = (int)d + 1;
  
  int ans = 0;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(check(mid)) {
      ans = mid;
      l = mid + 1;
    }else {
      r = mid - 1;
    }
  }
  if(ans == 0 && A[0] * d < c) {
    cout << "Impossible" << endl;
    return;
  }
  if(ans == d + 1) {
    cout << "Infinity" << endl;
    return;
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
