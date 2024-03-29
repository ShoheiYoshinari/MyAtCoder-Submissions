#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int num = k;
    for(int i = 0; i < n; i++){
        if(n - k > 0){
            cout << a[num+i] << ' ';
            k++;
        }else{
            cout << '0' << ' ';
        }
    }
    cout << endl;
}