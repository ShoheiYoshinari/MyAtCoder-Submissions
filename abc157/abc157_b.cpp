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
#define rep(i, s) for(int i = 0; i < (int)s; i++)
int main(){
    int a[3][3];
    bool p[3][3];
    rep(i, 3){
        rep(j, 3){
            cin >> a[i][j];
            p[i][j] = false;
        }
    }

    int n, b;
    bool ans = false;
    cin >> n;
    rep(i, n){
        cin >> b;
        rep(i, 3){
            rep(j, 3){
                if(b == a[i][j]){
                p[i][j] = true;
                break;
                }
            }
        }
    }
    rep(i, 3){
        if(p[0][i] && p[1][i] && p[2][i]) ans = true;
        if(p[i][0] && p[i][1] && p[i][2]) ans = true;
    }
    if(p[0][0] && p[1][1] && p[2][2]) ans = true;
    if(p[0][2] && p[1][1] && p[2][0]) ans = true;

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}


