#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i];
    
    rep(i, n-1){
        cout << a[i] <<' ';
       if(a[i] > a[i+1]){
        while(a[i] > a[i+1]+1){
            a[i]--;
            cout << a[i] << ' ';
        }
       }else if(a[i] < a[i+1]){
        while(a[i]+1 < a[i+1]){
            a[i]++;
            cout << a[i] << ' ';
        }
       }       
    }
    cout << a[n-1] << endl;
}