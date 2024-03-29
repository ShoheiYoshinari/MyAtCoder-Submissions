#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    bool ans = false;
    int i = 0;
    for (;i < a; i++)
    {
        if(s[i] < '0' || s[i] > '9') ans = true;
    }
    if(s[i] != '-') ans = true;
    i++;
    for (;i < a+b+1; i++)
    {
        if(s[i] < '0' || s[i] > '9') ans = true;
    }
    
    if(ans) cout << "No" << endl;
    else cout << "Yes" << endl;    
}