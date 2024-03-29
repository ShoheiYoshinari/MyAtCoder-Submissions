#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
long long n, k, a[1000009];

bool ck(long long x){
    long long sum = 0;
    rep(i, n) sum += x/a[i];
    if(sum >= k) return true;
    return false;
}

int main() {
    cin >> n >> k;
    rep(i, n){
        cin >> a[i];
    }
    long long left = 1, right = 1000000000;
    while(left < right){
        int mid = (left + right)/2;
        bool ans = ck(mid);
        if(ans == false) left = mid + 1;
        if(ans == true) right = mid;
    }
    cout << left << endl;
}