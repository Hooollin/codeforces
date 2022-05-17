#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T-- > 0){
        int n, m;
        cin >> n >> m;
        vector<int> planks(n), desired(n);   
        map<int, int> colors;

        map<int, vector<int>> topaint;
        for(int i = 0; i < n; i++){
            cin >> planks[i];
        }
        for(int i = 0; i < n; i++){
            cin >> desired[i];
            if(desired[i] != planks[i]){
                if(topaint.find(desired[i]) == topaint.end()){
                    topaint[desired[i]] = vector<int>();
                }
                topaint[desired[i]].push_back(i);
            }else{
                colors[desired[i]] = i;
            }
        }
        vector<int> ans;
        int more = 0;
        for(int i = 0; i < m; i++){
            int now;
            cin >> now;
            // 如果可以变成bi
            if(topaint.find(now) != topaint.end()){
                int loc = topaint[now].back();
                topaint[now].pop_back();
                if(topaint[now].empty()){
                    topaint.erase(now);
                }
                while(more){
                    ans.push_back(loc);
                    more--;
                }
                ans.push_back(loc);
                colors[now] = loc;
            }else if(colors.find(now) != colors.end()){
                int loc = colors[now];
                ans.push_back(loc);
                while(more){
                    ans.push_back(loc);
                    more--;
                }
            }else{
                more += 1;
            }
        }
        if(more || topaint.size() > 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            for(int i = 0; i < ans.size(); i++){
                cout << (ans[i] + 1) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
