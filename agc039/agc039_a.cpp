#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int main(){
    string s;
    long long k;
    cin >> s >> k;

    long long n = s.size();

    long long sm[109];
    long long f;
    long c = 0;
    sm[0] = 1;
    rep2(i, 1, n){
        if(s[i-1] == s[i]) sm[i] = sm[i-1] + 1;
        else sm[i] = 1;

        if(sm[i] == 1 && c == 0) f = sm[i-1], c++;
    }

    long long cnt = 0;
    if(sm[n-1] == n){
        cout << k * n / 2 << endl;
        return 0;
    }else{
        rep(i, n){
            if(!(sm[i]%2)) cnt++;
        }
        long long ans = cnt * k;
        if(s[n-1] != s[0]){
            cout << ans << endl;
            return 0;
        }else{
            if(f%2 && sm[n-1]%2) ans += k-1;
            cout << ans << endl;
            return 0;
        }
    }
}