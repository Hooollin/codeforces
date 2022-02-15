#include <iostream>
#include <vector>
#include <map>

using namespace std;

int p[200050];

int find(int x){
  if(p[x] == x) return p[x];
  return p[x] = find(p[x]);
}

void uni(int x, int y){
  x = find(x), y = find(y);
  p[x] = y;
}

void solve(){
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<vector<int>> edges;
  for(int i = 0; i < m; i++){
    int vi, ui, wi;
    cin >> vi >> ui >> wi;
    ans |= wi;
    edges.push_back({vi, ui, wi});
  }
  for(int i = 31; i >= 0; i--){
    if((ans >> i) & 1){
      for(int i = 1; i <= n; i++){
        p[i] = i;
      }
      for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        if((w >> i) & 1){
          continue;
        }
        uni(u, v);
      }
      map<int, int> cnt;
      for(int i = 1; i <= n; i++){
        cnt[find(i)]++;
      }
      if((int)cnt.size() == 1){
        ans ^= 1 << i;
        vector<vector<int>> rem;
        for(auto &e : edges){
          if(e[2] >> i & 1){
            continue;
          }
          rem.push_back(e);
        }
        edges = move(rem);
      }
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