#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    bool ans = false;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if(n == i * j) ans = true;
        }
    }

    if(ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;

}