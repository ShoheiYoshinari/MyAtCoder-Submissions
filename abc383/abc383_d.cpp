#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

const ll  MAX_N = 4000000000000LL;
const int L = 4000000;

vector<ll> primes;

void sieve() {
    vector<bool> is_prime(L + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= L; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = (ll)i * i; j <= L; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll count_numbers(ll N) {
    set<ll> result;
    ll p2, p4, p8;
    for (auto p : primes) {
        if(p <= N/p) p2 = p * p;
        else break;
        if(p2 <= N/p2) p4 = p2 * p2;
        else break;
        if(p4 <= N/p4) p8 = p4 * p4;
        else break;
        if (p8 <= N) {
            result.insert(p8);
            //cout << p << endl;
        } else {
            break;
        }
    }

    for (ll i = 0; i < primes.size(); ++i) {
        ll p1 = primes[i];
        ll p1_sq;
        if(p1 <= N/p1) p1_sq = p1 * p1;
        else break;

        for (ll j = i+1; j < primes.size(); ++j) {
            ll p2 = primes[j];
            ll p2_sq;
            if(p2 <= N/p2) p2_sq = p2 * p2;
            else break;
            if (p1_sq <= N / p2_sq){
                result.insert(p1_sq * p2_sq);
                //cout << p1_sq << ' ' << p2_sq << endl;
            }
            else break;
        }
    }

    return result.size();
}

int main() {
    ll N;
    cin >> N;
    sieve();
    cout << count_numbers(N) << endl;
    return 0;
}
