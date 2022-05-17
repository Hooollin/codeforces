#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T-- > 0){
        string s;
        cin >> s;
        int f[11][2], g[11][2];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for(int i = 0; i < 10; i++){
            if(i % 2){
                if(s[i] == '0'){
                    g[i + 1][0] = g[i][0];
                    g[i + 1][1] = g[i][1];
                }else if(s[i] == '1'){
                    g[i + 1][0] = g[i][0] + 1;
                    g[i + 1][1] = g[i][1] + 1;
                }else{
                    g[i + 1][0] = g[i][0];
                    g[i + 1][1] = g[i][1] + 1;
                }
                f[i + 1][0] = f[i][0];
                f[i + 1][1] = f[i][1];
            }else{
                if(s[i] == '0'){
                    f[i + 1][0] = f[i][0];
                    f[i + 1][1] = f[i][1];
                }else if(s[i] == '1'){
                    f[i + 1][0] = f[i][0] + 1;
                    f[i + 1][1] = f[i][1] + 1;
                }else{
                    f[i + 1][0] = f[i][0];
                    f[i + 1][1] = f[i][1] + 1;
                }
                g[i + 1][0] = g[i][0];
                g[i + 1][1] = g[i][1];
            }
        }
        int ans = 10;
        for(int i = 1; i <= 10; i++){
            if(f[i][1] - g[i][0] > (10 - i + 1) / 2 || g[i][1] - f[i][0] > (10 - i) / 2){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}