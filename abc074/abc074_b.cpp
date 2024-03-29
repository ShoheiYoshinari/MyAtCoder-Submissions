#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x;
    rep(i, n){
        int e;
        cin >> e;
        x.push_back(e);
    }

    int sum = 0;
    rep(i, n){
        if(x[i] > k - x[i]) sum += (k - x[i]) * 2;
        else sum += x[i] * 2;
    }
    cout << sum << endl;
}