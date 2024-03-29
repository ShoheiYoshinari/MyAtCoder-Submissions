#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int x[3],y[3];
    rep(i, 3) cin >> x[i] >> y[i];
    int aans,bans;
    if(x[0] == x[1]) aans = x[2];
    if(x[1] == x[2]) aans = x[0];
    if(x[2] == x[0]) aans = x[1];

    if(y[0] == y[1]) bans = y[2];
    if(y[1] == y[2]) bans = y[0];
    if(y[2] == y[0]) bans = y[1];

    cout << aans << " " << bans << endl;
}