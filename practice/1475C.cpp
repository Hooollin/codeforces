#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<pair<long long, long long>> ps;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int a, b, k;
        cin >> a >> b >> k;
        long long ans = ((long long)k * (k - 1)) / 2;
        ps.resize(k);
        map<int, long long> mp;
        for(int i = 0; i < k; i++){
            cin >> ps[i].first;
            mp[ps[i].first] += 1;
        }
        for(auto & p : mp){
            if(p.second > 1) ans -= p.second * (p.second - 1) / 2;
        }
        mp.clear();
        for(int i = 0; i < k; i++){
            cin >> ps[i].second;
            mp[ps[i].second] += 1;
        }
        for(auto &p : mp){
            if(p.second > 1) ans -= p.second * (p.second - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}
