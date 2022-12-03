#include <bits/stdc++.h>

using namespace std;

static int MAXV = 1000000007;

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  arr.push_back(MAXV);
  for(int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }
  arr.push_back(MAXV);
  
  int cnt = 0;

  for(int l = 1, r = 1; r < arr.size(); r++) {
    if(arr[l] != arr[r]) {
      if(arr[l] < arr[l - 1] && arr[r] > arr[r - 1]) ++cnt;
      l = r;
    }
  }

  cout << (cnt == 1 ? "YES" : "NO") << endl;
}

int main() {
  int T;
  cin >> T;
  while(T-- > 0) {
    solve();
  }
  return 0;
}
