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
#define rep(s, t) for(int s = 0; s < (int)t; s++)


int main(){
    int h, w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }
    int min = 1e9;
    int sum = 0;
    rep(i ,h){
        rep(j, w){
            if(min > a[i][j]){
                min = a[i][j];
            }
        }
    }
    rep(i, h){
        rep(j, w){
            sum  += a[i][j] - min;
        }
    }
    cout << sum << endl;

}