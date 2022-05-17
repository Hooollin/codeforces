#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> C(n);
    for(int i = 0; i < n; ++i){
        cin >> C[i];
    }

    bool biggest_idx = -1;
    for(int i = 0; i < n; ++i){
        if(C[i] == 1){
            biggest_idx = i;
            break;
        }
    }

    if(-1 == biggest_idx){
        cout << "NO" << endl;
        return;
    }

    reverse(C.begin(), C.end());
    reverse(C.begin(), C.begin() + biggest_idx + 1);
    reverse(C.begin() + biggest_idx, C.end());

    for(int i = 0; i < n - 1; ++i){
        if(C[i + 1] - C[i] > 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T-- > 0){
        solve();
    }

    return 0;
}
