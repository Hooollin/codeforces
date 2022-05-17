#include <iostream>
#include <algorithm>

using namespace std;

bool dfs(string &a, string &b, string &s, int x, int y, int diff){
  if(x < diff && y < 0){
    return true;
  }
  int va = a[x] - '0', vs = s[y] - '0', vb = 0;
  if(va <= vs){
    vb = vs - va;
    b.push_back(vb + '0');
    if(dfs(a, b, s, x - 1, y - 1, diff)){
      return true;
    }
    b.pop_back();
  }
  if(y == 0 || s[--y] - '0' != 1){
    return false;
  }
  vs += 10;
  vb = vs - va;
  if(vb < 10){
    b.push_back(vb + '0');
    if(dfs(a, b, s, x - 1, y - 1, diff)){
      return true;
    }
    b.pop_back();
  }
  return false;
}
void solve(){
  string a, s;
  cin >> a >> s;

  int diff = s.size() - a.size();
  if(diff < 0){
    cout << -1 << endl;
    return;
  }
  while(a.size() < s.size()){
    a.insert(a.begin(), '0');
  }
  string b;
  if(dfs(a, b, s, (int)a.size() - 1, (int)s.size() - 1, diff)){
    reverse(b.begin(), b.end());
    cout << stoll(b) << endl;
  }else{
    cout << -1 << endl;
  }
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