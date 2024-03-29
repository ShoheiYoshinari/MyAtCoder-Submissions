#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cin >> q;

    rep(i, q){
        int num;
        cin >> num;
        if(num == 1){
            int k,x;
            cin >> k >> x;
            a[k-1] = x;
        }else{
            int k;
            cin >> k;
            cout << a[k-1] << endl;
        }
    }
    return 0;
}