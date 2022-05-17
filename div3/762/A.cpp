#include <iostream>

using namespace std;

void solve(){
  string s;
  cin >> s;

  int n = s.size();
  if(n % 2){
    cout << "NO" << endl;
    return;
  }

  bool is = true;
  int mid = n / 2;
  for(int i = 0; i < mid; i++){
    if(s[i] != s[i + mid]){
      is = false;
    }
  }
  cout << (is ? "YES" : "NO") << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T-- > 0){
    solve();
  }
}