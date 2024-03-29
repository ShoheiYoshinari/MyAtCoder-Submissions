#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int tmp = 200005, cnt = 0;

    rep(i, n){
        if(tmp > p[i]){
            cnt++;
            tmp = p[i];
        }
    }
    cout << cnt << endl;
}