#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int n, k;
        cin >> n >> k;
        vector<int> cs(n);
        for(int i = 0; i < n; i++){
            cin >> cs[i];
        }
        int ans = 0;
        int now = cs[0];
        for(int i = 1; i < n; i++){
            if(cs[i] * 100 > now * k){
                int add = (cs[i] * 100 - now * k);
                ans += add;
                now += add;
            }
            now += cs[i];
        }
        cout << ans << endl;
    }
    return 0;
}
