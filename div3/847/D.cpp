#include <iostream>
#include <map>

using namespace std;

void solve() {
  int n;
  cin >> n;

  map<int, int> mp;
  for(int i = 0; i < n; i += 1) {
    int v;
    cin >> v;
    mp[v] += 1;
  }

  mp[1000000005] = 0;
  int ans = 0;
  int prev = -1, now = 0;
  for(auto &p : mp) {
    int curr = p.first, count = p.second;
    if(prev == curr - 1) {
      if(now > count) {
        ans += now - count;
      }
      now = count;
    }else {
      ans += now;
      prev = curr;
      now = count;
    }
    prev = curr;
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
