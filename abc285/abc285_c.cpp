#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    long long res = 0, add = 26,num = 0;
    for(int i = 1; i <= s.size() - 1; i++){
        res += add;
        add *= 26;
    }
    for(int i = 0; i < s.size(); i++){
        num *= 26;
        num += (s[i] - 'A');
    }
    cout << res + num + 1 << endl;
}