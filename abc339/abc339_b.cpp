#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int h, w, n;

int main(){
    cin >> h >> w >> n;
    char s[h][w];
    rep(i, h) rep(j, w) s[i][j] = '.';

    int ni = 0, nj = 0, now = 1000;
    rep(i, n){
        if(s[ni][nj] == '.'){
            now++;
            s[ni][nj] = '#';
            
        }else{
            now--;
            s[ni][nj] = '.';
        }
        ni += di[now%4] + h;
        nj += dj[now%4] + w;
        ni %= h;
        nj %= w;
    }



    rep(i, h){
        rep(j, w) cout << s[i][j];
        cout << endl;
    }
    return 0;
}