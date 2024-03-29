#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        sum += m[i];
    }
    sort(m.begin(),m.end());
    ans = (x - sum) / m[0] + n ;
    cout << ans << endl;
}
