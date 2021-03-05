#include <iostream>
#include <cstdio>
using namespace std;

int n, U, R, D, L;

// 所有的边都小于n - 1一定是true
// 四个角上放不放格子


void solve(){
    bool valid = false;
    for(int choose = 0; choose < (1 << 4); choose++){
        int tU = U, tR = R, tD = D, tL = L;
        for(int i = 0; i < 4; i++){
            if(choose & (1 << i)){
                if(i == 1){
                    tU -= 1;
                    tL -= 1;
                }else if(i == 2){
                    tL -= 1;
                    tD -= 1;
                }else if(i == 3){
                    tR -= 1;
                    tD -= 1;
                }else{
                    tU -= 1;
                    tR -= 1;
                }
            }
        }
        if(tU >= 0 && tU < n - 1 && tR >= 0 && tR < n - 1 && tD >= 0 && tD < n - 1 && tL >= 0 && tL < n - 1){
            valid = true;
            break;
        }
    }
    printf("%s\n", valid ? "YES" : "NO");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T-- > 0){
        scanf("%d%d%d%d%d", &n, &U, &R, &D, &L);
        solve();
    }
    return 0;
}