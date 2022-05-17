#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void dfs(int now, int weight, vector<vector<int>> &g, map<pair<int, int>, int> &ew, set<int> &vis){
  for(auto &nxt : g[now]){
    if(vis.find(nxt) == vis.end()){
      ew[{min(now, nxt), max(now, nxt)}] = weight;
      vis.insert(nxt);
      int next_weight = weight == 2 ? 3 : 2;
      dfs(nxt, next_weight, g, ew, vis);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T-- > 0){
    int n;
    cin >> n;

    vector<pair<int, int>> edges;
    vector<int> deg(n + 1);
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
      deg[u]++;
      deg[v]++;
      edges.push_back({min(u, v), max(u, v)});
    }

    bool valid = true;
    int leaf = 0;
    for(int i = 1; i <= n; i++){
      if(deg[i] > 2){
        cout << -1 << endl;
        valid = false;
        break;
      }
      if(deg[i] == 1){
        leaf = i;
      }
    }

    if(!valid){
      continue;
    }

    map<pair<int, int>, int> ew;
    set<int> vis;
    vis.insert(leaf);
    dfs(leaf, 2, g, ew, vis);
    for(auto &e : edges){
      cout << ew[e] << " ";
    }
    cout << endl;
  }
  return 0;
}