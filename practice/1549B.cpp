#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(t[i] == '1'){
                if(s[i] == '0'){
                    ans++;
                }else{
                    if(i > 0 && s[i - 1] == '1'){
                        ans++;
                        s[i - 1] = '-';
                    }else if(i < n - 1 && s[i + 1] == '1'){
                        ans++;
                        s[i + 1] = '-';
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}