#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h),t(h);
    rep(i, h) cin >> s[i];
    rep(i, h) cin >> t[i];

    vector<string> st(w),tt(w);
    rep(i, h){
        rep(j, w){
            st[j].push_back(s[i][j]);
            tt[j].push_back(t[i][j]);
        }
    }
    sort(st.begin(),st.end());
    sort(tt.begin(),tt.end());

    if(st == tt) cout << "Yes" << endl;
    else cout << "No" << endl;
}
