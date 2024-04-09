#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, m;
string s;

int main(){
    cin >> n >> m >> s;

    int cnt = 0;
    int atcoder = 0, muzi = m;
    rep(i, n){
        if(s[i] == '0'){
            atcoder = cnt;
            muzi = m;
        }else if(s[i] == '1'){
            if(muzi > 0) muzi--;
            else if(atcoder > 0) atcoder--;
            else cnt++;
        }else if(s[i] == '2'){
            if(atcoder > 0)atcoder--;
            else cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

