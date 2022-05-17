#include <iostream>
#include <vector>
#include <set>

const int inf = 100007;
using ll = long long;
using namespace std;

int n, k;
vector<int> arr;

bool valid(int x, int k, int n){
    int presum[n + 1];
    presum[0] = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] >= x){
            presum[i] = presum[i - 1] + 1;
        }else{
            presum[i] = presum[i - 1] - 1;
        }
    }
    int mx = presum[k], mn = 0;
    for(int i = k + 1; i <= n; i++){
        mn = min(presum[i - k] , mn);
        mx = max(presum[i] - mn, mx);
    }
    return mx > 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    arr.resize(n + 1);
    int l = inf, r = -inf;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        l = min(l, arr[i]);
        r = max(r, arr[i]);
    }       
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(valid(mid, k, n)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
