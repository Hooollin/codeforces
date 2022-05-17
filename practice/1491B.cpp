#include <iostream>
#include <vector>

using namespace std;

int n, v, h;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n >> v >> h;
        int ans = INT_MAX;
        int now, next;
        cin >> now;
        for(int i = 1; i < n; i++){
            cin >> next;
            int diff = abs(now - next);
            if(diff == 0){
                ans = min(ans, min(h + v, h + h));
            }else if(diff == 1){
                ans = min(ans, min(h, v));
            }else{
                ans = 0;
            }
            now = next;

        }
        printf("%d\n", ans);
    }
    return 0;
}
