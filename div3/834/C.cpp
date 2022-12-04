#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long l, r, x;
  cin >> l >> r >> x;

  long long a, b;
  cin >> a >> b;
  long long d = abs(b - a);

  if(d == 0) {
    cout << 0 << endl;
    return;
  }

  if(d >= x) {
    cout << 1 << endl;
    return;
  }
  
  if(a + x > r && a - x < l) {
    cout << -1 << endl;
    return;
  }

  if(a + x <= r && a - x >= l) {
    cout << 2 << endl;
    return;
  }

  if(a + x <= r) {
    if(abs(r - b) >= x) {
      cout << 2 << endl;
    }else{
      if(abs(l - b) >= x) {
        cout << 3 << endl;
      }else {
        cout << -1 << endl;
      }
    }
    return;
  }

  if(a - x >= l) {
    if(abs(l - b) >= x) {
      cout << 2 << endl;
    }else {
      if(abs(r - b) >= x) {
        cout << 3 << endl;
      }else {
        cout << -1 << endl;
      }
    }
    return;
  }

}

int main() {
  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }

  return 0;
}
