#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = a; i <= b; i++){
        int s = i % 10 , t = i /10000 % 10;
        int u = i /10 % 10, v = i /1000 % 10;
        if(s == t && u == v) cnt++;
    }
    cout << cnt << endl;
    
}
