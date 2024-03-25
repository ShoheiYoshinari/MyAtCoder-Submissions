#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1, 0, -1, 0};
const int dy[]={0, 1, 0, -1}; 
const double PI = acos(-1);

int h, w, n;
string t, s[509];

int main(){
    cin >> h >> w >> n;
    cin >> t;
    rep(i, h) cin >> s[i];

    int cnt = 0;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '.'){
                bool ok = true;
                int x = i, y = j;
                rep(k, n){
                    if(t[k] == 'L')y--;
                    if(t[k] == 'R')y++;
                    if(t[k] == 'U')x--;
                    if(t[k] == 'D')x++;

                    if(x < 0 || x >= h || y < 0 || y >= w){
                        ok = false;
                        break;
                    }
                    if(s[x][y] == '#'){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;

}