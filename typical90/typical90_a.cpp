#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n,l,k;
int a[1 << 18];

bool solve(int mid) {
    int cnt = 0; 
    int pre = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] - pre >= mid && l - a[i] >= mid){
            cnt += 1;
            pre = a[i];
        }
    }
    if(cnt >= k) return true;
    else return false;
}

int main() {
    cin >> n >> l >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int left = -1;
    int right = l + 1;

    while (right - left > 1){
        int mid = left + (right - left) / 2;

        if(solve(mid) == false) right = mid;
        else left = mid;
    }
    cout << left << endl;
    return 0;
}
