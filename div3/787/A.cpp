#include <bits/stdc++.h>

using namespace std;

void solve(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  bool sufficient = max(0, (x - a)) + max(0, (y - b)) <= c;
  cout << (sufficient ? "YES" : "NO") << endl;
} 

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T-- > 0){
    solve();
  }

  return 0;
}