#include <iostream>

using namespace std;

void quick_read(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int solve(int n, int minidx, int maxidx){
    int ans = minidx + n - maxidx + 1;
    if (maxidx < ans) {
        ans = maxidx;
    }
    if (n - minidx + 1 < ans)
    {
        ans = n - minidx + 1;
    }
    return ans;
}

int main(){
    quick_read();
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        int a[n + 1];
        int minidx = -1, maxidx = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(minidx == -1 || a[i] < a[minidx]){
                minidx = i;
            }
            if(maxidx == -1 || a[i] > a[maxidx]){
                maxidx = i;
            }
        }
        cout << solve(n, min(minidx, maxidx), max(minidx, maxidx)) << endl;
    }
    return 0;
}
