#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> a;

void solve(){
    int ans = 0;
    vector<int> idx(n);
    for(int i = 0; i < n; i++){
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int x, int y){
            return a[x] < a[y];
            });
    vector<int> pwins;
    long long presum = 0;
    for(int i = 0; i < n - 1; i++){
        presum += a[idx[i]];
        if(presum >= a[idx[i + 1]]){
            pwins.push_back(idx[i]);
        }else{
            pwins.clear();
        }
    }
    pwins.push_back(idx[n - 1]);
    sort(pwins.begin(), pwins.end());
    cout << pwins.size() << endl;
    for(int i = 0; i < pwins.size(); i++){
        cout << pwins[i] + 1 << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}
