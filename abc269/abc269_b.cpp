#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    vector<string> s(10);
    rep(i, 10) cin >> s[i];
    int a, b, c, d;
    int cnt = 0;
    rep(i, 10){
        rep(j, 10){
            if(s[i][j] == '#' && cnt == 0){
                a = i, c = j;
                cnt++;
            }
        }
    }
    int cntx = 0;
    rep(i, 10){
        if(s[i][c] == '#') cntx++;
    }
    b = a + cntx - 1;
    int cnty = 0;
    rep(j, 10){
        if(s[a][j] == '#') cnty++;
    }
    d = c + cnty - 1;

    cout << a+1 << ' ' << b+1 << endl;
    cout << c+1 << ' ' << d+1 << endl;

} 