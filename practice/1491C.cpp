#include <iostream>
#include <vector>

using ll = long long;
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T-- > 0){
        ll n;
        cin >> n;
        vector<ll> ways(n + 1), S(n + 1);

        for(int i = 0; i < n; i++){
            cin >> S[i];
        }
        ll ans = 0;
        for(ll now = 0; now < n; now++){
            // [now + 2, now + S[now]]是一定要跳的
            for(ll nxt = now + 2; nxt <= min(n - 1, now + S[now]); nxt++){
                ways[nxt] += 1;
            }
            // 如果还需要从这里开始跳
            if(S[now] - ways[now] > 1){
                // 需要跳的次数
                ans += S[now] - ways[now] - 1;
            }
            if(ways[now] + 1 > S[now]){
                ways[min(n - 1, now + 1)] += ways[now] + 1 - S[now];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
