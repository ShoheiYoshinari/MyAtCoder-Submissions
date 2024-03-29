#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,x;
    cin >> n >> x;
    x = abs(x);
    vector<int> a;
    int b;
    rep(i, n) {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());

    if(x == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    rep(i, n){
        for(int j = i+1; j < n; j++){
            if(a[j] - a[i] == x) {
                cout << "Yes" << endl;
                return 0;
            }else if(a[j] - a[i] > x) {
                break;
            }else if(a[j] < x) {
                break;
            }
        } 
    }
    cout << "No" << endl;

}