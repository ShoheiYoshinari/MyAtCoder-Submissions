#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    long long a, b;
    cin >> a >> b;

    long long cnt = 0;
    while(true){
        long long num;
        
        if(a % b == 0 || b % a == 0){
            cnt += max(a/b, b/a) - 1;
            break;

        }
        if(a - b > 0){
            num = a / b;
            a -= b * num;
            cnt += num;
        }else if(b - a > 0){
            num = b / a;
            b -= a * num;
            cnt += num;
        }else if(a == b){
            break;
        }
    }
    cout << cnt << endl;
}