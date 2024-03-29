#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
int main() {
    
    int n,m;
    cin >> n >> m;
    vector<unsigned> a(1 << 9),b(1 << 9);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    a[n] = 1 << 9;
    b[m] = 1 << 9;
    
    int A = 0;
    int B = 0;
    int cnt = 1;
    vector<unsigned> a_rank(1 << 9),b_rank(1 << 9);
    while(n + m - cnt + 1 > 0) { 
        if(a[A] < b[B]) {
            a_rank[A] = cnt;
            cnt++;
            A++;
        }else{
            b_rank[B] = cnt;
            cnt++;
            B++;
        }
    }
    rep(i, n) cout << a_rank[i] << ' ';
    cout << endl;
    rep(i, m) cout << b_rank[i] << ' ';
    cout << endl;
    return 0;
}
*/
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m),c;
    map<long,long> mp;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i,n) c.push_back(a[i]);
    rep(i,m) c.push_back(b[i]);

    sort(c.begin(),c.end());
    rep(i, n+m) mp[c[i]] = i;

    rep(i, n) cout << mp[a[i]] + 1 << endl;
    rep(i, m) cout << mp[b[i]] + 1 << endl;

}