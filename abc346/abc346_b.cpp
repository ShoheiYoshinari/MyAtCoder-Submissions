#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

string s, tmp = "wbwbwwbwbwbw";
int w, b;

int main(){
    cin >> w >> b;
    rep(i, w+b){
        s += tmp;
    }

    int ww[2409], bb[2409];
    ww[0] = 0;
    bb[0] = 0;
    rep(i, s.size()){
        if(s[i] == 'w'){
            ww[i+1] = ww[i] + 1;
        }else{
            ww[i+1] = ww[i];
        }

        if(s[i] == 'b'){
            bb[i+1] = bb[i] + 1;
        }else{
            bb[i+1] = bb[i];
        }
    }

    rep2(i, 1, s.size()){
        rep2(j, i, s.size()){
            if(ww[j] - ww[i-1] == w && bb[j] - bb[i-1] == b){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;

}