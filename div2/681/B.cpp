#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int l = 0, r = s.size() - 1;
        int ans = 0;
        // deleting leading and trailing 0's
        int zero = 0, one = 0;
        while(l <= r && s[l] == '0') l++;
        while(l <= r && s[r] == '0') r--;
        while(l <= r && s[l] == '1') {one = 1;l++;}
        while(l <= r){
            int zerostart = l;
            while(l <= r && s[l] == '0') l++;
            if(l > r){
                break;
            }
            int zcnt = l - zerostart;
            while(l <= r && s[l] == '1'){
                l++;
            }
            if(zcnt * b <= a){
                zero += zcnt;
            }else{
                one += 1;
            }
        }
        ans = one * a + zero * b;
        cout << ans << endl;
    }
    return 0;
}