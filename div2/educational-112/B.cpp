#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int W, H;
        cin >> W >> H;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int tw = x2 - x1, th = y2 - y1;
        int w, h;
        cin >> w >> h;
        if(w + tw > W && h + th > H){
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        if(w + tw <= W && h + th <= H){
            int ta = 0, tb = 0;
            int a = y1, b = H - y2;
            if(a < h && b < h){
                ta = h - max(a, b);
            }
            a = x1, b = W - x2;
            if(a < w && b < w){
                tb = w - max(a, b);
            }
            ans = min(ta, tb);
        }else if(w + tw > W){
            int a = y1, b = H - y2;
            if(a < h && b < h){
                ans = h - max(a, b);
            }
        }else if(h + th > H){
            int a = x1, b = W - x2;
            if(a < w && b < w){
                ans = w - max(a, b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
