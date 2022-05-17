#include <iostream>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        if(n % 2){
            // win half, lose half
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(j - i <= n / 2){
                        cout << 1 << " ";
                    }else{
                        cout << -1 << " ";
                    }
                }
            }
        }else{
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(j - i < n / 2){
                        cout << 1 << " ";
                    }else if(j - i > n / 2){
                        cout << -1 << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
