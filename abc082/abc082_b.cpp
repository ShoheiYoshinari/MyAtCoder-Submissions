#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end()); 
    //sの一番小さい文字列とtの一番大きい文字列を比較する。s < t でなければ、適当に並べても s < t となることはない
    if(s < t) cout << "Yes" << endl;
    else cout << "No" << endl;
}