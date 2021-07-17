#include <iostream>
#include <cmath>

using ll = long long;
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        ll n;
        cin >> n;
        
        // short(short + 1) = long * (long - 1);
        // long = short + 1;
        // short + short + 1 = another short ** 2;
        //
        int ans = 0;
        for(ll i = 3; i * i <= 2 * n - 1; i += 2){
            ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}
