#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int n, l, r;
        cin >> n >> l >> r;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        long long ans = 0;
        for(int i = 0; i < n - 1; i++){
            int x = l - a[i], y = r - a[i];
            ans += (int)(upper_bound(a + i + 1, a + n, y) - lower_bound(a + i + 1, a + n, x));
        }
        cout << ans << endl;
    }
    return 0;
}