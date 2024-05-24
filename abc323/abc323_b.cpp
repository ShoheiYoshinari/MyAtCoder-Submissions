#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    string s[n];
    rep(i, n){
        cin >> s[i];
    }

    vector<int> win;

    rep(i, n){
        int cnt = 0;
        rep(j, n){
            if(s[i][j] == 'o') cnt++;
        }
        win.push_back(cnt);
    }

    for(int i = n-1; i >= 0; i--){
        rep(j, win.size()){
            if(i == win[j]){
                cout << j + 1 << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}