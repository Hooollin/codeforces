#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int kases;
    cin >> kases;
    while(kases-- > 0){
        int a, b;
        cin >> a >> b;
        string s;
        for(int i = 0; i < a + b; i++){
            char t;
            cin >> t;
            s += t;
        }
        bool canDo = true;
        int n = s.size();
        for(int i = 0; i < n / 2; i++){
            //都是问号
            if(s[i] == '?' && s[n - i - 1] == '?'){
                continue;
            }
            //都不是问号
            if(s[i] != '?' && s[n - i - 1] != '?'){
                if(s[i] != s[n - i - 1]){
                    canDo = false;
                    break;
                }else{
                    if(s[i] == '1'){
                        b -= 2;
                    }else{
                        a -= 2;
                    }
                }
            }else{ // 有一个是问号
                if(s[i] == '?'){
                    s[i] = s[n - i - 1];
                    if(s[i] == '1'){
                        b -= 2;
                    }else{
                        a -= 2;
                    }
                }else{
                    s[n - i - 1] = s[i];
                    if(s[i] == '0'){
                        a -= 2;
                    }else{
                        b -= 2;
                    }
                }
            }
        }
        //cout << a << " " << b << " " << s << endl;
        for(int i = 0; i < n / 2; i++){
            if(s[i] == '?'){
                if(a >= 2){
                    s[i] = s[n - i - 1] = '0';
                    a -= 2;
                }else{
                    s[i] = s[n - i - 1] = '1';
                    b -= 2;
                }
            }
        }
        if(n % 2){
            if(s[n / 2] == '?'){
                if(a > 0){
                    s[n / 2] = '0';
                    a -= 1;
                }else{
                    s[n / 2] = '1';
                    b -= 1;
                }
            }else{
                if(s[n / 2] == '1') b -= 1;
                else a -= 1;
            }
        }
        //cout << a << " " << b << endl;
        if(a != 0 || b != 0){
            cout << -1 << endl;
        }else{
            cout << s << endl;
        }
    }
    return 0;
}
