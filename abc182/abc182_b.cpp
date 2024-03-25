#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n, a[109], cnt[1009];

int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
    }

    rep2(i, 2, 1000){
        rep(j, n){
            if(a[j]%i == 0) cnt[i]++;                                                                    
        }
    }
    int MaxcntID = -1;
    int Maxcnt = 0;
    rep(i, 1000){
        if(Maxcnt < cnt[i]){
            Maxcnt = cnt[i];
            MaxcntID = i;
        }
    }
    cout << MaxcntID << endl;

}