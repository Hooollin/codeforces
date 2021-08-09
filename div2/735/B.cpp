#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        long long ans = INT_MIN;
        for(int i = max(1, n - 2 * k); i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max(1LL * i * j - 1LL * k * (arr[i] | arr[j]), ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}