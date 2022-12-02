#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  int maxv = 0, sec_maxv = 0;
  for(int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
    if(maxv <= v) {
      sec_maxv = maxv;
      maxv = v;
    }else if(sec_maxv <= v) {
      sec_maxv = v;
    }
  }
  for(int i = 0; i < n; i++) {
    if(arr[i] != maxv) cout << arr[i] - maxv << " ";
    else cout << arr[i] - sec_maxv << " ";
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
