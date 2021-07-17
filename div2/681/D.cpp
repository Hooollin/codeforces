#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 50;
const int inf = 1e7;
int v[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T-- > 0){
        int n, k;
        cin >> n >> k;
        v[0] = k;
        for(int i = 1; i < n; i++){
            cin >> v[i];
        }
        bool f = true;
        for(int i = 1; i < n; i++){
            if(v[i] < v[i - 1]){
                if(k < v[i - 1] - v[i]){
                    f = false;
                    break;
                }
                k -= v[i - 1] - v[i];
            }
        }
        cout << (f? "YES" : "NO") << endl;
    }
    return 0;
}
