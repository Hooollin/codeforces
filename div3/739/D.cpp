#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<string> &ts, string &s){
  int ans = (int)s.size() + 1;
  for(auto &t : ts){
    int i = 0, j = 0;
    while(i < (int)t.size() && j < (int)s.size()){
      if(s[j] == t[i]){
        i++;
      }
      j++;
    }
    ans = min(ans, (int)s.size() + (int)t.size() - 2 * i);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> ts;
  long long v = 1;
  for(int i = 0; i < 63; i++){
    ts.push_back(to_string(v));
    v <<= 1;
  }

  int T;
  cin >> T;
  while(T-- > 0){
    int n;
    cin >> n;
    string t = to_string(n);
    cout << solve(ts, t) << endl;
  }
  return 0;
}