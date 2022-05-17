#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int f[6][200050];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string now = "abc";
    int k = 0;

    do{
        f[k][0] = 0;
        int p = 0;
        for(int i = 1; i <= n; i++, p = (p + 1) % 3){
            f[k][i] = f[k][i - 1] + (now[p] != s[i - 1]);
        }
        k++;
    }while(next_permutation(now.begin(), now.end()));
    
    while(m-- > 0){
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        int ans = r - l + 1;
        for(int i = 0; i < 6; i++){
            ans = min(f[i][r + 1] - f[i][l], ans);
        }
        cout << ans << endl;
    }
    return 0;
}
