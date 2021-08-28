#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;


int gcd(int a, int b){
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

int v(int a){
    int cnt = 0;
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0){
            a /= i;
            cnt++;
            i = 1;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int a, b, k;
        cin >> a >> b >> k;
        int k = gcd(a, b);
        if(k == 1){
            cout << "No" << endl;
        }else if(a == b){
            if(k == 0 || k == 2){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            int v = 2;
            while(v * v <= k){
                if(k % v == 0){
                    break;
                }
            }

        }
    }   
    return 0;
}