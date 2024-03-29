#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,m;
    cin >> n >> m;

    vector<int> v(n+1, false);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        v[a] = true;
    }

    int left = 1;
    while(left <= n) {
        int right = left;
        while(v[right] == true) right++;

        for (int i = right; i >= left; i--)
        {
            cout << i << ' ';
        }
        
        left = right + 1;
    }
    cout << endl;
}