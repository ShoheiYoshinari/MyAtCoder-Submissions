#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int h,m,a,b,c,d,ac,bd;
    cin >> h >> m;
      
    while(true){
        a = h / 10;
        b = h % 10;
        c = m / 10;
        d = m % 10;
        ac = a * 10 + c;
        bd = b * 10 + d;

        if(ac >= 0 && ac <= 23){
            if(bd >= 0 && bd <= 59) break;
        }
        m++;
        if(m == 60){
            m = 0;
            h++;
        }
        if(h == 24) h = 0;
    }
    cout << h << ' ' << m << endl;
}