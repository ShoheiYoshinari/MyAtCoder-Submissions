#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> ans;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] != -1) {
            a[a[i]-1] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i] != -1) cnt++;
    }
    
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
    {
        if(a[i] != -1) cout << i+1 <<" ";
    }
    cout << endl;
}