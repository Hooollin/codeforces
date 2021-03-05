#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
string s, t;
int ans = 0;

void solve(){
    vector<int> l(m + 1), r(m + 1);
    for(int i = 0, j = 0; i < n && j < m; i++){
        if(s[i] == t[j]){
            l[j++] = i;
        }
    }
    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--){
        if(s[i] == t[j]){
            r[j--] = i;
        }
    }
    for(int i = 0; i < m - 1; i++){
        ans = max(r[i + 1] - l[i], ans);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    solve();
    return 0;
}
