#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


const int maxn = 3e5 + 50;

int a[maxn];
int idx[maxn];

int d[maxn];
int ans[maxn];


void solve(vector<int> &now, int m){
    vector<pair<int, int>> r;
    for(int i = 0; i < now.size(); i++){
        if(d[now[i]] == 1){
            r.push_back({now[i], a[now[i]]});
        }else{
            if(!r.empty()){
                pair<int, int> tp = r.back(); r.pop_back();
                ans[tp.first] = ans[now[i]] = (a[now[i]] - tp.second) / 2;
            }else{
                r.push_back({now[i], -a[now[i]]});
            }
        }
    }
    while(r.size() >= 2){
        pair<int, int> A = r.back(); r.pop_back();
        pair<int ,int> B = r.back(); r.pop_back();
        ans[A.first] = ans[B.first] = (2 * m - A.second - B.second) / 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T-- > 0){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            idx[i] = i;
            ans[i] = -1;
        }

        for(int i = 1; i <= n; i++){
            char t;
            cin >> t;
            if(t == 'L'){
                d[i] = -1;
            }else{
                d[i] = 1;
            }
        }
               
        sort(idx + 1, idx + n + 1, [&](int &i, int &j){
                return a[i] < a[j];
                });

        vector<int> now;
        for(int i = 1; i <= n; i++){
            if(a[idx[i]] % 2){
                now.push_back(idx[i]);
            }
        }
        solve(now, m);

        now.clear();
        for(int i = 1; i <= n; i++){
            if(a[idx[i]] % 2 == 0){
                now.push_back(idx[i]);
            }
        }
        solve(now, m);

        for(int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
