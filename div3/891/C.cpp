#include <cassert>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * min value shows up for at least n - 1 times.
 * second min value shows up for at least n - 2 times.
 * etc,.
 */
void solve() {
  int n;
  cin >> n;
  map<long long, int> mp;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    long long t;
    cin >> t;
    mp[t]++;
  }
  int count = n - 1;
  for (auto &&[val, freq] : mp) {
    // cout << "a: " << freq << " " << count << endl;
    while (freq > 0) {
      // cout << freq << " " << val << endl;
      cout << val << " ";
      freq -= count;
      --count;
    }
  }
  // why is cout << (mp.rbegin()->first + 1LL) << " " falty?
  // corner case: all same value
  assert(count == 0);
  while (count >= 0) {
    cout << (mp.rbegin()->first) << " ";
    --count;
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
