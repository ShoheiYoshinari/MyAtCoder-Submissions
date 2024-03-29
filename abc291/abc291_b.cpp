#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,a;
    cin >> n;
    vector<int> x;
    rep(i, 5 * n) {
        cin >> a;
        x.push_back(a);
    }
    sort(x.begin(),x.end());
    double sum = 0;

    for (int i = n; i < 4 * n ; i++)
    {
        sum += x[i];
    }
    cout << fixed << setprecision(15) << sum / (3 * n) << endl;
}