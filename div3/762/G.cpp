#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int p[200050];

int find(int x){
  if(p[x] == x){
    return x;
  }
  return p[x] = find(p[x]);
}

void uni(int x, int y){
  x = find(x), y = find(y);
  p[x] = y;
}

void do_uni(map<int, vector<vector<int>>> &ms, int limit){
  for (auto &[k, v] : ms){
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b){ 
      return a[1] < b[1]; });
    int n = v.size();
    for (int i = 1; i < n; i++){
      if(v[i][1] - v[i - 1][1] <= limit){
        uni(v[i - 1][0], v[i][0]);
      }
    }
  }
}

void solve(){
  for(int i = 0; i < 200050; i++){
    p[i] = i;
  }

  int n, k;
  cin >> n >> k;

  int l = 0, r = 0; 

  vector<vector<int>> mines;
  map<int, vector<vector<int>>> x_mines, y_mines;
  for(int i = 0; i < n; i++){
    int x, y, t;
    cin >> x >> y >> t;
    r = max(t, r);
    x_mines[x].push_back({i, y, t});
    y_mines[y].push_back({i, x, t});
    mines.push_back({x, y, t});
  }

  do_uni(x_mines, k);
  do_uni(y_mines, k);

  map<int, int> min_explosion_time;
  for(int i = 0; i < n; i++){
    int pa = find(i);
    if(min_explosion_time.find(pa) == min_explosion_time.end()){
      min_explosion_time[pa] = (int)1e9 + 5;
    }
    min_explosion_time[pa] = min(min_explosion_time[pa], mines[i][2]);
  }

  auto valid = [mines, min_explosion_time](int time) -> bool {
    int k = time + 1;
    for(auto &[pa, v] : min_explosion_time){
      if(v > time){
        --k;
      }
    }
    return k >= 0;
  };

  int ans = 0;
  while(l <= r){
    int mid = (l + r) / 2;
    if(valid(mid)){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
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