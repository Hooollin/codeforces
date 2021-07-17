#include <iostream>
#include <map> 

using namespace std;


map<int, int> valid = {{1, 1}, {2, 5}, {5, 2}, {8, 8}, {0, 0}};

bool good(int h, int m, int maxh, int maxm){
    int nh = 0, nm = 0;
    for(int i = 0; i < 2; i++){
        if(!valid.count(h % 10)){
            return false;
        }
        nh = nh * 10 + valid[h % 10];
        h /= 10;
    }
    for(int i = 0; i < 2; i++){
        if(!valid.count(m % 10)){
            return false;
        }          
        nm = nm * 10 + valid[m % 10];
        m /= 10;
    }
    //cout << nm << " " << nh << endl;
    return nm < maxh && nh < maxm;
}

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int maxh, maxm, h, m;
        char deli;
        cin >> maxh >> maxm >> h >> deli >> m;
        while(true){
            if(good(h, m, maxh, maxm)){
                if(h < 10){
                    cout << 0;
                }
                cout << h << ":";
                if(m < 10){
                    cout << 0;
                }
                cout << m << endl;;
                break;
            }
            m += 1;
            if(m == maxm){
                m = 0;
                h += 1;
                if(h == maxh){
                    h = 0;
                }
            }
        }
    }

    return 0;
}
