#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        int mn = n * 4;
        while(n-- > 0){
            cout << mn << " ";
            mn -= 2;
        }
        cout << endl;
    }
    return 0;
}