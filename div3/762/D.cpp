#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve(){
  int m, n;
  cin >> m >> n;

  int l = 1, r = 1;
  vector<vector<int>> p(m, vector<int>(n));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> p[i][j];
      r = max(r, p[i][j]);
    }
  }

  auto valid = [p, m, n](int k){
    bool multiple = m <= n - 1;
    vector<int> maxv(n, 0);
    for(int i = 0; i < m; i++){
      //cout << "i, row, chance: " << i << " " << row << " " << chance << endl;
      int cnt = 0;
      for(int j = 0; j < n; j++){
        if(p[i][j] >= k){
          cnt++;
          maxv[j] = max(maxv[j], p[i][j]);
        }
      }
      if(m >= n - 1){
        multiple |= cnt >= 2;
      }
    }

    if(!multiple) return false;

    for(int i = 0; i < n; i++){
      if(maxv[i] < k){
        return false;
      }
    }

    return true;
  };

  int ans = 0;
  while(l <= r){
    int mid = (l + r) / 2;
    if(valid(mid)){
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << ans << endl;
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