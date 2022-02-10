#include <iostream>
using namespace std;

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  int d = b - c;
  if(0 == (d + b) % a && (d + b) / a > 0){
    cout << "YES" << '\n';
    return;
  }
  if((a + c) % 2 == 0 && (a + c) / 2 % b == 0 && (a + c) / 2 / b > 0){
    cout << "YES" << '\n';
    return;
  }
  d = b - a;
  if(0 == (d + b) % c && (d + b) / c > 0){
    cout << "YES" << '\n';
    return;
  }
  cout << "NO" << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while(T-- > 0){
    solve();
  }
  return 0;
}