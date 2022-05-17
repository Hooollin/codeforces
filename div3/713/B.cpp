#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 405;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int kases;
    cin >> kases;
    while(kases-- > 0){
        int n;
        cin >> n;
        char m[n + 1][n + 1];
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> m[i][j];
                if(m[i][j] == '*'){
                    if(x1 == 0){
                        x1 = i;
                        y1 = j;
                    }else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        if(x1 == x2){
            int nx;
            if(x1 == 1){
                nx = x1 + 1;
            }else{
                nx = x1 - 1;
            }
            m[nx][y1] = '*';
            m[nx][y2] = '*';
        }else if(y1 == y2){
            int ny;
            if(y1 == 1){
                ny = y1 + 1;
            }else{
                ny = y1 - 1;
            }
            m[x1][ny] = '*';
            m[x2][ny] = '*';
        }else{
            m[x1][y2] = '*';
            m[x2][y1] = '*';
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << m[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
