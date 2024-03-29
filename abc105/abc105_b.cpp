#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool ans = false;
    for (int i = 0; i <= 100/4; i++){
        for (int j = 0; j < 100/7; j++){
            int total = 4 * i + 7 * j;
            if(total == n) ans = true;
        }
    }
    
    if(ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
 }