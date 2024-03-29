#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    vector<int> o, e;
    rep(i, n){
        int a;
        cin >> a;
        if(a%2 == 0){
            o.push_back(a);
        }else{
            e.push_back(a);
        }
    }
    sort(o.begin(), o.end());
    reverse(o.begin(), o.end());
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    int ans = -1;
    if(o.size() >= 2) ans = max(ans, o[0] + o[1]);
    if(e.size() >= 2) ans = max(ans, e[0] + e[1]);

    cout << ans << endl;

}