#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a;
    cin >> n >> a;
    int excess = n % 500;
    if(a >= excess) cout << "Yes" << endl;
    else cout << "No" << endl;
}