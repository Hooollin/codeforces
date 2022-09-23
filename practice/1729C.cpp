#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int freq[26];
  memset(freq, 0, sizeof(freq));
  for(auto &ch : s) {
    freq[ch - 'a']++;
  }
  int a = s.front() - 'a', b = s.back() - 'a';
  int ans = 0;
  vector<int> tails;
  if(a < b) {
    for(int i = a; i <= b; i++) {
      ans += freq[i];
      for(int j = 0; j < s.size(); j++) {
        if(s[j] - 'a' == i) {
          tails.emplace_back(j + 1);
        }
      }
    }
  } else {
    for(int i = a; i >= b; i--) {
      ans += freq[i];
      for(int j = 0; j < s.size(); j++) {
        if(s[j] - 'a' == i) {
          tails.emplace_back(j + 1);
        }
      }
    }
  }
  cout << abs(b - a) << " " << ans << endl;
  for(auto &v : tails) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t-- > 0) {
    solve();
  }
  return 0;
}