#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long h;
    cin >> h;

    long long sumMonster = 1, cnt = 0;
    while(h != 1){
        h = h / 2;
        cnt += sumMonster;
        sumMonster  *= 2;
    }
    cout << cnt + sumMonster << endl;
}