#include <iostream>
#include <set>
#include <cmath>

using ll = long long;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        ll x;
        cin >> x;
        set<ll> st;
        for(ll i = 1; i <= 10000; i++){
            st.insert((ll)pow(i, 3));
        }
        bool found = false;
        for(auto val : st){
            if(st.find(x - val) != st.end()){
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}
