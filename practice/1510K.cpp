#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<int> origin;

void op2(){
    for(int i = 0; i < n; i++){
        swap(origin[i], origin[i + n]);
    }
}

void op1(){
    for(int i = 0; i < 2 * n; i += 2){
        swap(origin[i], origin[i + 1]);
    }
}

bool same(){
    for(int i = 0; i < 2 * n; i++){
        if(a[i] != origin[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(2 * n);
    origin.resize(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
        origin[i] = i + 1;
    }
    int ans = 10005;
    for(int i = 0; i <= 2 * n; i++){
        if(same()){
            ans = min(ans, i);
            break;
        }
        if(i % 2){
            op1();
        }else{
            op2();
        }
        
    }
    for(int i = 0; i < 2 * n; i++){
        origin[i] = i + 1;
    }
    for(int i = 0; i <= 2 * n; i++){
        if(same()){
            ans = min(ans, i);
            break;
        }
        if(i % 2){
            op2();
        }else{
            op1();
        }
    }
    cout << (ans == 10005 ? -1 : ans) << endl;
    return 0;
}
