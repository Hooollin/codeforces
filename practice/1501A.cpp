#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n;
vector<pair<ll, ll>> pr;
vector<ll> tm;

void solve(){
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll a = pr[i].first, b = pr[i].second;
        ans += tm[i - 1] + a - pr[i - 1].second;
        if(i < n){
            ans += (b - a + 1) / 2;
            ans = max(b, ans);
        }
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        pr.clear();
        tm.clear();
        tm.resize(n);
        pr.push_back({0, 0});
        for(int i = 0; i < n; i++){
            pair<int, int> p;
            cin >> p.first >> p.second;
            pr.push_back(p);
        }
        for(int i = 0; i < n; i++){
            cin >> tm[i];
        }

        solve();
    }
    return 0;
}
