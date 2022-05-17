#include <iostream>
#include <vector>
#include <stack>
#include <set> 

using namespace std;
using ll = long long;
const int maxn = 1e4;

int n;
vector<int> v;

void solve(){
    stack<int> ans;
    set<int> vis;
    int target = n;
    int i = n - 1;
    while(i >= 0){
        vis.insert(v[i]);
        if(v[i] != target){
            ans.push(v[i]);
        }else{
            cout << target << " ";
            while(!ans.empty()){
                cout << ans.top() << " ";
                ans.pop();
            }
            while(vis.find(target) != vis.end()){
                target -= 1;
            }
        }
        i -= 1;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        solve();
    }
    return 0;
}
