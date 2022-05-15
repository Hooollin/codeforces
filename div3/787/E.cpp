#include <bits/stdc++.h>

using namespace std;

void solve(){ 
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  map<char, char> mp;
  char max_ch = 'a';
  for(auto &ch : s){
    if(ch <= max_ch) continue;
    // k至少为need才可以覆盖['a'~max_ch~ch]
    int need = ch - max_ch;
    // 可以覆盖
    if(need <= k){
      k -= need;
      for(char c = max_ch + 1; c <= ch; ++c){
        mp[c] = 'a';
      }
      max_ch = ch;
    }else{
      // [ch - k + 1 ~ ch]只能变成ch - k
      for(char c = ch - k + 1, nc = ch - k; c <= ch; ++c){
        mp[c] = nc;
      }
      break;
    }
  }

  for(auto &ch : s){
    if(mp.find(ch) != mp.end()){
      cout << mp[ch];
    }else{
      cout << ch;
    }
  }
  cout << endl;
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