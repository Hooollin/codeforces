#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int kases;
    cin >> kases;
    while(kases-- > 0){
        int n;
        cin >> n;
        int b[n + 3];
        for(int i = 1; i <= n + 2; i++){
            cin >> b[i];
        }
        sort(b + 1, b + n + 3);
        long long sum = 0;
        for(int i = 1; i <= n + 1; i++){
            sum += b[i];
        }
        if(sum == (long long)2 * b[n + 1]){
            for(int i = 1; i <= n; i++){
                cout << b[i] << " ";
            }
            cout << endl;
            continue;
        }
        int left = -1;
        for(int i = 1; i <= n + 1; i++){
            if(sum - b[i] == b[n + 2]){
                left = i;
                break;
            }
        }
        if(left != -1){
            for(int i = 1; i <= n + 1; i++){
                if(left != i){
                    cout << b[i] << " ";
                }
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
