#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<array<int, 2>>> &g, int pre, int now, int except, 
          int xor_w, vector<int> &xor_ws) {
  for(auto &a : g[now]) {
    int nxt = a[0], w = a[1];
    if(nxt == except || nxt == pre) {
      continue;
    }
    xor_ws.push_back(xor_w ^ w);
    dfs1(g, now, nxt, except, xor_w ^ w, xor_ws);
  }
}

bool dfs2(vector<vector<array<int, 2>>> &g, int pre, 
          int now, int target, int xor_w) {
  if(now == target) {
    return xor_w == 0;
  }
  bool ans = false;
  for(auto &a : g[now]) {
    int nxt = a[0], w = a[1];
    if(nxt == pre) continue;
    ans |= dfs2(g, now, nxt, target, xor_w ^ w);
  }
  return ans;
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<vector<array<int, 2>>> g(n + 1, vector<array<int, 2>>());
  for(int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  if(dfs2(g, 0, a, b, 0)) {
    cout << "YES" << endl;
    return;
  }

  vector<int> x, y;
  dfs1(g, 0, a, b, 0, x);
  // buggy code: dfs1(g, 0, b, a, 0, y);
  dfs1(g, 0, b, 0, 0, y);

  set<int> st;
  for(auto &v : x) {
    st.insert(v);
  }

  bool good = false;
  for(auto &v : y) {
    if(st.find(v) != st.end() || v == 0) {
      good = true;
      break;
    }
  }
  cout << (good ? "YES" : "NO") << endl;
}

int main() {
  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }
  return 0;
}
