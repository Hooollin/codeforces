#include <iostream>

using namespace std;

void solve(){
  int n;
  cin >> n;

  int l = 1, r = n;
  int div = 0;
  while(r - l > 1){
    int m = (l + r) / 2;
    cout << "+ " << (n - m) << endl;
    int d;
    cin >> d;
    if(d > div){
      l = m;
    }else{
      r = m;
    }
    l = (l + n - m) % n;
    r = (r + n - m) % n;
    if(r == 0) r = n;
    div = d;
  }
  cout << "! " << div * n + l << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}