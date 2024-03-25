#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int h, w;
string s[109];

int main(){
    cin >> h >> w;
    rep(i, h) cin >> s[i];

    string snuke = "snuke";
    string str;

    rep(i, h){
        rep(j, w){
            rep(k, 8){
                str = "";
                rep(l, 5){
                    int x = i + dx[k] * l;
                    int y = j + dy[k] * l;
                    if(x < 0 || x >= h || y < 0 || y >= w) break;
                    str += s[x][y];  
                }
                if(str == snuke){
                    rep(l, 5){
                        int x = i + dx[k] * l + 1;
                        int y = j + dy[k] * l + 1;
                        cout << x << ' ' << y << endl;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}