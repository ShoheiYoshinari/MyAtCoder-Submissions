#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i+=2)
    {
        swap(s[i],s[i+1]);
    }
    cout << s << endl;
    

}