#include <iostream>

using namespace std;

void solve() {
  int n, s, r;
  cin >> n >> s >> r;

  int stolen = s - r;
  int mean = r / (n - 1);
  int more = r % (n - 1);
  for(int i = 0; i < n - 1 - more; i += 1) {
    cout << mean << " ";
  }
  for(int i = 0; i < more; i += 1) {
    cout << (mean + 1) << " ";
  }
  cout << stolen << endl;
}

int main() {
  int T;

  cin >> T;
  while(T-- > 0) {
    solve();
  }

  return 0;
}
