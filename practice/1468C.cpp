#include <iostream>
#include <set>
#include <queue>

using namespace std;

int num = 1;

bool seen[(int)5e5 + 50];

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    }
};

queue<int> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int Mnext(){
    while(!q.empty() && seen[q.front()]){
        q.pop();
    }
    int now = q.front();
    seen[q.front()] = true;
    return now;
}

int Pnext(){
    while(!pq.empty() && seen[pq.top().first]){
        pq.pop();
    }
    int now = pq.top().first;
    seen[now] = true;
    pq.pop();
    return now;
}

int main(){
    for(int i = 0; i < 5e5 + 50; i++){
        seen[i] = false;
    }
    int Q;
    cin >> Q;
    while(Q-- > 0){
        int type, m;
        cin >> type;
        if(type == 1){
            cin >> m;
            q.push(num);
            pq.push({num, m});
            num += 1;
        }else if(type == 2){
            cout << Mnext() << " ";
        }else{
            cout << Pnext() << " ";
        }
    }
    return 0;
}
