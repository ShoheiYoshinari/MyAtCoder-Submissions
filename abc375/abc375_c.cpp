#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
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
using ll = long long;
using ull = unsigned long long;

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;
int main() {
    int n;
    cin >> n;
    vector<vector<char> > a(n+1, vector<char> (n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }

    vector<vector<char> > b(n+1, vector<char> (n+1, '$'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int d = min({i, j, n+1-i, n+1-j});
            d %= 4;
            int ni = i, nj = j;
            for(int c = 0; c < d; c++){
                int ti = nj, tj = n + 1 - ni;
                ni = ti, nj = tj;
            }
            b[ni][nj] = a[i][j];
            
        }
    }
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            cout << b[x][y];
        }
        cout << endl;
    }

}