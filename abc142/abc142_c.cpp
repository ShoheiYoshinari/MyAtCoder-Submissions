#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    rep(i, n){
        int ai;
        cin >> ai;
        a.push_back(make_pair(ai, i));
    }

    sort(a.begin(), a.end());
    for(auto p : a){
        cout << p.second + 1 << ' ';
    }
    cout << endl;
}