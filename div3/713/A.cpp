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
        int n;
        cin >> n;
        map<int, int> mp;
        map<int, int> mpp;
        for(int i = 1; i <= n; i++){
            int t;
            cin >> t;
            mp[t] += 1;
            mpp[t] = i;
        }
        for(auto &p : mp){
            if(p.second == 1){
                cout << mpp[p.first] << endl;
                break;
            }
        }
    }
    return 0;
}
