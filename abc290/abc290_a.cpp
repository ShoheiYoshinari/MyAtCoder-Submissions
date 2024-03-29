#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    int sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    for (int i = 0; i < m; i++)
    {
        sum += a[b[i] - 1];
    }
    
    cout << sum << endl;
}