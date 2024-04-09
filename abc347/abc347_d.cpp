#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

unsigned popcount(unsigned c){
    unsigned cnt = 0;
    while(c){
        if(c%2 == 1) cnt++;
        c /= 2;
    }
    return cnt;
}

int main(){
    unsigned a, b;
    unsigned long C;
    cin >> a >> b >> C;
    unsigned c = popcount(C);

    if((a+b+c)%2 != 0 || a+b+c > 120 || a > b+c || b > a+c || c > a+b){
        cout << -1 << endl;
        return 0;
    }

    unsigned n00{60-(a+b+c)/2}, n01{(-a+b+c)/2}, n10{(a-b+c)/2}, n11{(a+b-c)/2};

    unsigned long x{}, y{};
    for(unsigned B = 60; B--;){
        x *= 2;
        y *= 2;

        if(1 & (C >> B)){
            if(n10){
                x++;
                n10--;
            }else{
                y++;
                n01--;
            }
        }else{
            if(n00){
                n00--;
            }else{
                x++;
                y++;
                n11--;
            }
        }
    }

    cout << x << ' ' << y << endl;
    return 0;
}