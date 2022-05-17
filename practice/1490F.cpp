#include <iostream>
#include <vector>
#include <map>
#include <set> 

using namespace std;

int n;
map<int, int> freq;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        freq.clear();
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            freq[t] += 1;
        }
        set<int> uniC;
        for(auto &p : freq){
            uniC.insert(p.second);
        }
        int ans = 1e5 * 5;
        for(auto i : uniC){
            int now = 0;
            for(auto &p : freq){
                if(p.second < i){
                    now += p.second;
                }else{
                    now += p.second - i;
                }
            }
            ans = min(now, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
