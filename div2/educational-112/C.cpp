#include <iostream>

using namespace std;

int a[2][100050];

int main(){
    a[0][0] = 0, a[1][0] = 0;
    int T;
    cin >> T;
    while(T-- > 0){
        int m;
        cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> a[0][i];
            a[0][i] += a[0][i - 1];
        }
        for(int i = 1; i <= m; i++){
            cin >> a[1][i];
            a[1][i] += a[1][i - 1];
        }
        int ans = INT_MAX;
        for(int i = 1; i <= m; i++){
            ans = min(ans, max(a[1][i - 1], a[0][m] - a[0][i]));
        }
        cout << ans << endl;
    }
    return 0;
}
