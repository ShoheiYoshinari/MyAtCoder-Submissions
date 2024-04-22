#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define rep(i, s) for(int i = 0;i < (int)s; i++)
#define rep2(i, v, s) for(int i = (int)v; i <= (int)s; i++)
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const double PI = acos(-1);

char toLower(char c) {
    return ('A' <= c && c <= 'Z') ? ('a' + c - 'A') : c;
}

int main(){
    string s, t, tt;
    cin >> s >> t;
    rep(i, t.size()) tt += toLower(t[i]);
    if(t[2] == 'X') s += 'x';

    int dp[300009];
    dp[0] = 0;

    int pos = 0;
    rep(i, s.size()){
        if(tt[pos] == s[i]){
            dp[i+1] = dp[i] + 1;
            pos++;
        }else{
            dp[i+1] = dp[i];
        }
    }
    if(dp[s.size()] == t.size()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;

}