#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int t;
    cin >> t;
    rep(l, t){
        int n;
        cin >> n;
        vector<int> p(n+1);
        rep(i, n) cin >> p[i];

        int cnt = 0;
        set<int> s;
        rep(i, n){
            if(p[i] > i) s.insert(i);
            if(p[i] <= i){
                for(int j = i; j >= p[i]; j--){
                    if(p[i] < p[j]) s.insert(j);
                }
            }
        }
        cnt = n - s.size();
        cout << cnt << endl;
    }
}