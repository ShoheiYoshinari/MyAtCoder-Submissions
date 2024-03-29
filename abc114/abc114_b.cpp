#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    int like = 753;
    int minAns = 1009;

    rep(i, s.size()-2){
        int tmp = (int)(s[i] - '0') * 100 + (int)(s[i + 1] - '0') * 10 + (int)(s[i + 2] - '0') - like;
        minAns = min(minAns, abs(tmp));
    }
    cout << minAns << endl;
}