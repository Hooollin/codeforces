#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
 
using namespace std;
 
void solve(){
  int n, m;
  cin >> n >> m;
  // f[i]: s[0...i]是否可以被表示
  // f[i] = true if f[j - 1]且s[j...i]存在, j from 0 - i - 1
  map<string, tuple<int, int, int>> seen;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < m - 1; j++){
      seen[s.substr(j, 2)] = {j + 1, j + 2, i + 1};
      if(j + 3 <= s.size()){
        seen[s.substr(j, 3)] = {j + 1, j + 3,i + 1};
      }
    }
  }
 
  string s;
  cin >> s;
  bool f[1050];
  int prev[1050];
  tuple<int, int, int> idx[1050];
  for(int i = 0; i < m; i++){
    f[i] = false;
    prev[i] = -1;
  }
  f[0] = true;
  for(int i = 2; i <= m; i++){
    for(int j = max(1, i - 3); j < i; j++){
      //cout << i << " " << j << ": " << s.substr(j - 1, i - j + 1) << endl;
      auto it = seen.find(s.substr(j - 1, i - j + 1));
      f[i] = f[j - 1] && it != seen.end();
      if(f[i]){
        prev[i] = j - 1;
        idx[i] = it->second;
        break;
      }
    }
  }
  if(f[m]){
    vector<tuple<int, int, int>> ans;
    int curr = m;
    while(prev[curr] != -1){
      ans.push_back(idx[curr]);
      curr = prev[curr];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto &[l, r, i] : ans){
      cout << l << " " << r << " " << i << endl;
    }
  }else{
    cout << "-1" << endl;
  }
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