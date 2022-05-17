#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 50;
int a[maxn], b[maxn];
bool valid(int K, int n){
    int now = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > K){
            now += b[i];

        }
        if(now > K) return false;

    }
    return true;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        int l = 1, r = 1;
        for(int i = 0; i < n; i++){cin >> a[i]; r = max(r, a[i]);}
        for(int i = 0; i < n; i++) cin >> b[i];
        int ans = 0;
        while(l <= r){
            int K = (l + r) >> 1;
            if(valid(K, n)){
                ans = K;
                r = K - 1;

            }else{
                l = K + 1;

            }

        }
        cout << ans << endl;

    }
    return 0;

}
