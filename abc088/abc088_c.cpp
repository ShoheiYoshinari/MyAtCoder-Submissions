#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int c[3][3];

int main(){
    rep(i, 2){
        rep(j, 2) cin >> c[i][j];
    }

    rep(i, 100){
        rep(j, 100){
            rep(k, 100){
                bool ok1 = false, ok2 = false, ok3 = false;
                if(c[0][0] - i == c[0][1] - j && c[0][1] - j == c[0][2] - k) ok1 = true;
                if(c[1][0] - i == c[1][1] - j && c[1][1] - j == c[1][2] - k) ok2 = true;
                if(c[2][0] - i == c[2][1] - j && c[2][1] - j == c[2][2] - k) ok3 = true;

                if(ok1 && ok2 && ok3){
                    cout << "Yes" << endl;
                    return 0;
                }

            }
        }
    }
    cout << "No" << endl;
    return 0;
}