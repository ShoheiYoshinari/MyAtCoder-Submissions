#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string march = "MARCH";

struct INIT {
    INIT() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} init;

int main() {
    ll n;
    cin >> n;
    vector<string> names(n);
    for (auto& name : names) {
        cin >> name;
    }

    vector<ll> counts(5, 0);
    for (const auto& name : names) {
        for (size_t j = 0; j < march.size(); ++j) {
            if (name[0] == march[j]) {
                counts[j]++;
                break;
            }
        }
    }

    ll result = 0;
    vector<int> combination = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                result += counts[i] * counts[j] * counts[k];
            }
        }
    }

    cout << result << endl;
    return 0;
}
