#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

const int N = 1e5 + 10;
vector<pair<int, int>> adj[N];
set<int> s;
bool ok = true;
int n, a, b;
void dfs1(int u, int par, int x) {
    if(u == b) return;
    s.insert(x);
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        dfs1(v, u, x ^ w);
    }
}

bool dfs2(int u, int par, int x) {
    if(u != b && s.count(x)) return true;
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        if(dfs2(v, u, w ^ x)) return true;
    } 
    return false;
}

void solve() {
    s.clear();
    cin >> n >> a >> b; --a, --b;
    forn(i, n) adj[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs1(a, -1, 0);
    if(dfs2(b, -1, 0)) cout << "YES\n";
    else cout << "NO\n";
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
