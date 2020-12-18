#include <iostream>

using namespace std;

const int maxn = 3e5 + 50;

int pre[maxn], suf[maxn];
int arr[maxn];

/*
    [1, 2, 1]
    [1, 1, 1]
    [1, 5, 1]
    [11, 7, 8, 8, 9, 8, 8, 6, 8]
    [6, 6, 6, 8, inf]
    [1,1,5]
    [3,2,1,2,1,3,4,5]
    [1,1,1]
    [6, 1, 1, 6, 3, 1, 6]
*/

const int inf = 1e8 + 50;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        pre[0] = inf;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            pre[i + 1] = min(pre[i], arr[i]);
        }
        suf[n] = inf;
        for(int i = n - 1; i >= 0; i--){
            suf[i] = min(suf[i + 1], arr[i]);
        }

        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(pre[i - 1] + suf[i] < arr[i - 1]){
                //cout << pre[i] << " " << suf[i] << endl;
                ans = false;
                break;
            }
        }
        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}