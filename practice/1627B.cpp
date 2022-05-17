#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve(){
  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> q;
  set<pair<int, int>> vis;
  int sx = (n + 1) / 2, ex = (n + 1) / 2 + (n % 2 == 0);
  int sy = (m + 1) / 2, ey = (m + 1) / 2 + (m % 2 == 0);

  for(int i = sx; i <= ex; i++){
    for(int j = sy; j <= ey; j++){
      q.push({i, j});
      vis.insert({i, j});
    }
  }

  int now = 0, tot = 0, d = n / 2 + m / 2;
  while(!q.empty()){

    int sz = q.size();
    while(sz-- > 0){
      cout << d << " ";

      pair<int, int> point = q.front(); q.pop();
      //cout << "point: " << point.first << " " << point.second << endl;
      for(int k = 0; k < 4; k++){
        int nx = dx[k] + point.first, ny = dy[k] + point.second;
        if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && vis.find({nx, ny}) == vis.end()){
          //cout << "nx, ny: " << nx << " " << ny << endl;
          vis.insert({nx, ny});
          q.push({nx, ny});
        }
      }
    }
    d++;
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

