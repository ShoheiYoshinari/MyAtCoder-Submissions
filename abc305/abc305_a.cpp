#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;

    int low = (n/5)*5;
    int high = low + 5;
    if(n - low > high - n) cout << high << endl;
    else cout << low << endl;
}