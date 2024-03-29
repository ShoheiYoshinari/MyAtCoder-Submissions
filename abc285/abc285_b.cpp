#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j <= n - i - 1; j++) {
            if(s[j] != s[i + j]) cnt++;
            else break;
        }
        cout << cnt << endl;
    }
}