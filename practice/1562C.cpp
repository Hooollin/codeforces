#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int zero_pos = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                zero_pos = i;
            }
        }
        if(zero_pos == -1){
            cout << 1 << " " << (n + 1) / 2 << " " << 2 << " " << (n + 1) / 2 + 1 << endl;
        }else{
            zero_pos += 1;
            if(zero_pos <= (n + 1) / 2){
                cout << zero_pos << " " << n << " " << zero_pos + 1 << " " << n << endl;
            }else{
                cout << 1 << " " << zero_pos << " " << 1 << " " << zero_pos - 1 << endl;
            }
        }
    }
    return 0;
}