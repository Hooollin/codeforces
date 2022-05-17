#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int maxv = n, minv = 1;
        if(a[1] == maxv && a[n] == minv){
            cout << 3 << endl;
        }else if(a[1] == maxv || a[n] == minv){
            cout << 2 << endl;
        }else if(a[1] != minv && a[n] != maxv){
            cout << 2 << endl;
        }else{
            int ans = 0;
            for(int i = 2; i < n; i++){
                if(a[i] != i){
                    ans = 1;
                    break;
                }
            }
            cout << ans << endl;
        }       
    }
    return 0;
}
