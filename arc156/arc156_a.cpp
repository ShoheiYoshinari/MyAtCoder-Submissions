#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int t;
int n[200009];
string s[200009];

int main(){
    cin >> t;
    rep(i, t) cin >> n[i] >> s[i];

    rep(i, t){
        int one = count(s[i].begin(), s[i].end(), '1');
        bool adj = 0;
        if(one%2 == 1){
            cout << "-1" << endl;
            continue;
        }
        rep(j, n[i]-1){
            if(s[i][j] == '1' && s[i][j] == s[i][j+1]) adj = 1;
        }
        if(one != 2 or !adj){
            cout << one / 2 << endl;
            continue;
        }
        if(n[i] == 3){
            cout << "-1" << endl;
            continue;
        }
        if(n[i] == 4 && s[i] == "0110"){
            cout << "3" << endl;
            continue;
        }
        cout << "2" << endl;
    }
}
