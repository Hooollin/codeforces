#include <iostream>
#include <vector>

using namespace std;

const int maxn = (int)2e5 + 50;

vector<long long> a(maxn), b(maxn);

long long get(int a, int b){
    if(a % b == 0){
        return a / b;
    }
    return a / b + 1;
}

bool valid(long long d, long long t, long long n){
    long long have = 0;
    long long x = d;
    for(int i = 0; i < n - 1; i++){
        long long earn = a[i], need = b[i];
        if(t < have || get(t - have, earn) <= d){
            return true;
        }
        long long workd = need > have ? get(need - have, earn) : 0;
        have = workd * earn + have - need;
        d -= workd + 1;
        if(d < 0){
            return false;
        }
    }
    return have + a[n - 1] * d >= t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        long long n, c;
        cin >> n >> c;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++){
            cin >> b[i];
        }

        long long l = 1, r = (int)1e9 + 1;
        long long ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(valid(mid, c, n)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
