#include <iostream>

using namespace std;

void quick_read(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    quick_read();
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        int a[n + 1];
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n != 0){
            cout << -1 << endl;
            continue;
        }
        int target = sum / n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > target){
                ans += 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

