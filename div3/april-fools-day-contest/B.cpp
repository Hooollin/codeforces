#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a;
    cin >> a;
    for(int i = 1; i * i <= a; i++){
        if(i * i <= a && (i + 1) * (i + 1) > a){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
