#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;

bool solve(int mid) {

    cout << '?' << ' ' << mid << endl;
    int s;
    cin >> s;
    if(s == 0) return true;
    else return false;
}
    
int main() {
    cin >> n;
    
    int left = 1;
    int right = n;

    while (right - left > 1){
        int mid = left + (right - left) / 2;

        if(solve(mid) == false) right = mid;
        else left = mid;
    }
    cout << '!' << ' ' << left << endl;
    return 0;
}
