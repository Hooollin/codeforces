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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        long long ans = 0;
        for(int i = 1; i < n; i++){
            ans = max((long long)arr[i] * arr[i - 1], ans);
        }
        cout << ans << endl;
    }
    return 0;
}