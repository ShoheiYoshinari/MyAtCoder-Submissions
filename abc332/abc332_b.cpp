#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int k, g, m;

int main(){
    cin >> k >> g >> m;

    int glass = g;
    int mag = m;

    while(k--){
        if(glass == g) glass = 0;
        else if(mag == 0) mag = m;
        else{
            if(g - glass < mag){
                mag -= g - glass;
                glass = g;
            }else{
                glass += mag;
                mag = 0;
            }
        }
    }
    cout << glass << ' ' << mag << endl;
    return 0;
}