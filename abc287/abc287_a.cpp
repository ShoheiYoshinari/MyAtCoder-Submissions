#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    int sannsei = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if(s == "For") sannsei++;
    }
    if(sannsei > n / 2) cout << "Yes" <<endl;
    else cout << "No" << endl;

}