#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cave[100050];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cave[i].clear();
        }
        vector<pair<int, long long>> least;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            long long maxv = 0;
            for(int j = 0; j < k; j++){
                long long ki;
                cin >> ki;
                cave[i].push_back(ki);
                if(ki - j + 1 > maxv){
                    maxv = ki - j + 1;
                }
            }
            least.push_back({i, maxv});
        }
        sort(least.begin(), least.end(), [&](pair<int, long long> &a, pair<int, long long> &b){
            return a.second < b.second;
        });
        long long extra = 0, ans = 0;
        for(int i = 0; i < n; i++){
            //cout << least[i].first << " " << least[i].second << " ";
            if(ans + extra < least[i].second){
                ans = least[i].second - extra;
            }
            extra += cave[least[i].first].size();
            //cout << ans << " " << extra << endl;
        }
        cout << ans << endl;
    }
    return 0;
}