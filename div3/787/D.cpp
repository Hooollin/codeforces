#include <bits/stdc++.h>

using namespace std;

int p[200050];
vector<int> g[200050];

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

void dfs(int node){
  // leaf
  if((int)g[node].size() == 0){
    return;
  }

  for(auto &child : g[node]){
    dfs(child);
  }
  
  assert(g[node].size() > 0);
  uni(node, g[node][0]);
}

void dfs2(int node, map<int, vector<int>> &paths){
  paths[find(p[node])].push_back(node);
  for(auto &child : g[node]){
    dfs2(child, paths);
  }
}

void solve(){
  int n;
  cin >> n;

  for(int i = 1; i <= n; ++i){
    g[i].clear();
    p[i] = i;
  }

  int root = -1;
  for(int i = 1; i <= n; ++i){
    int pi;
    cin >> pi;
    if(pi == i){
      root = i;
    }else{
      g[pi].push_back(i);
    }
  }
  assert(root != -1);

  dfs(root);

  map<int, vector<int>> paths;
  dfs2(root, paths);

  cout << paths.size() << endl;

  for(auto &[ances, path] : paths){
    cout << path.size() << endl;
    for(auto &node : path){
      cout << node << " ";
    }
    cout << endl;
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