#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int k;
        cin >> k;
        bool enough = false;
        for(int i = 1; i <= 100; i++){
            for(int j = 0; j <= i; j++){
                if(j * 100 == i * k){
                    enough = true;
                    cout << i << endl;
                    break;
                }
            }
            if(enough){
                break;
            }
        }
    }

    return 0;
}
