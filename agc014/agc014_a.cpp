#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int tmp1, tmp2, tmp3;
    int cnt = 0;
    while(a%2 == 0 && b%2 == 0 && c%2 == 0){
        if(a == b && b == c){
            cout << "-1" << endl;
            return 0;
        }
        tmp1 = a;
        tmp2 = b;
        tmp3 = c;
        a = tmp2/2 + tmp3/2;
        c = tmp1/2 + tmp2/2;
        b = tmp1/2 + tmp3/2;

        cnt++;
    }
    cout << cnt << endl;

}