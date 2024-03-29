#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int n, a, b;
   string s;
   cin >> n >> a >> b >> s;
   int fgn = 1, cnt = 0;
   rep(i, s.size()){
      bool ans = false;
      if(s[i] == 'a'){
         if(a + b > cnt){
            ans = true;
            cnt++;
         }
      }else if(s[i] == 'b'){
         if(a + b > cnt && b >= fgn){
            ans = true;
            cnt++;
            fgn++;
         }
      }
      if(ans) cout << "Yes" << endl;
      else cout << "No" << endl;
   }

}