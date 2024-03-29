#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t,a;
    cin >> n >> t >> a;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    double dmin = 1e9, ans = -1;

    for (int i = 0; i < n; i++)
    {
        double T = t - h[i] * 0.006;
        double d = abs(a - T);
        if (d < dmin)
        {
            dmin = d;
            ans = i;
        }
        
    }
    
    cout << (ans + 1) << endl;

}