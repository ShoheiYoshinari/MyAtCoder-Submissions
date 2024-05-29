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
    int n, s;
    int a[69];
    bool dp[69][100009];
    cin >> n >> s;
    rep2(i, 1, n) cin >> a[i];

    rep2(i, 0, n){
        rep2(j, 0, s) dp[i][j] = false;
    }
    dp[0][0] = true;

    rep2(i, 1, n){
        rep2(j, 0, s){
            if(j < a[i]){
                if(dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }else{
                if(dp[i-1][j] == true || dp[i-1][j-a[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    if(dp[n][s]){
        vector<int> root;
        int place = n;
        int value = s;
        while(true){
            if(value == 0) break;

            if(dp[place-1][value] == true) place--;
            else{
                value -= a[place];
                root.push_back(place);
                place--;
            }
        }
        reverse(all(root));
        cout << root.size() << endl;
        rep(i, root.size()) cout << root[i] << ' ';
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
    
}