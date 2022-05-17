#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve(){
    string s;
    cin >> s;
    string s1 = "0", s2 = "0";
    for(int i = 0; i < s.size(); i++){
        if(i % 2){
            s2 += s[i];
        }else{
            s1 += s[i];
        }
    }
    cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T-- > 0){
        solve();
    }
    return 0;
}