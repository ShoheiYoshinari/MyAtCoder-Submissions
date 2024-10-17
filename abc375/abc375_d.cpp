#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>

using namespace std;
using ll = long long;

struct INIT {
    INIT() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
    string s;
    cin >> s;

    map<char, int> mp;
    set<char> unique_chars(s.begin(), s.end()); 
    vector<char> char_vec(unique_chars.begin(), unique_chars.end());

    // 累積和を保持する2次元ベクトル (ユニークな文字数 × 文字列の長さ)
    vector<vector<ll> > ss(char_vec.size(), vector<ll>(s.size(), 0));

    for (int i = 0; i < char_vec.size(); i++) {
        char current_char = char_vec[i];
        for (int j = 2; j < s.size(); j++) {
            if (s[j-2] == current_char) {
                mp[current_char]++;
            }
            ss[i][j] += ss[i][j-1] + mp[current_char];
        }
    }

//    for(int i = 0; i < char_vec.size(); i++){
//       for(int j = 0; j < s.size(); j++){
//          cout << ss[i][j];
//     }
//    cout << endl;
// }

    ll cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < char_vec.size(); j++) {
            if (char_vec[j] == s[i]) {
                cnt += ss[j][i];
                break;
            }
        }
        //cout  << cnt << endl;
    }

    cout << cnt << endl;
    return 0;
}
