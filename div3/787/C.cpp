#include <bits/stdc++.h>

using namespace std;

void solve(){
  string s;
  cin >> s;

  int n = s.size();

  int a = 1, b = n;
  for(int i = 0; i < n; ++i){
    if(s[i] == '1'){
      a = i + 1;
    }
  }
  for(int i = n - 1; i >= 0; --i){
    if(s[i] == '0'){
      b = i + 1;
    }
  }
  
  //cout << "(" << a << " " << b << ")" << endl;
  cout << (b - a + 1) << endl;
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