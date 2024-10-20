#include <bits/stdc++.h>
using namespace std;

int min_distance(int from, int to, int n, int other_hand) {
    int clockwise_dist = (to - from + n) % n;
    int counter_clockwise_dist = (from - to + n) % n;

    if (clockwise_dist < counter_clockwise_dist) {
        if ((from < other_hand && other_hand < to) || (to < from && (other_hand > from || other_hand < to))) {
            return counter_clockwise_dist;
        } else {
            return clockwise_dist;
        }
    } else {
        if ((to < other_hand && other_hand < from) || (from < to && (other_hand > to || other_hand < from))) {
            return clockwise_dist;
        } else {
            return counter_clockwise_dist;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<char> h(q);
    vector<int> t(q);
    
    for (int i = 0; i < q; i++) {
        cin >> h[i] >> t[i];
        t[i]--;
    }

    int l = 0, r = 1;
    int ans = 0;

    for (int i = 0; i < q; i++) {
        if (h[i] == 'R') {
            ans += min_distance(r, t[i], n, l);
            r = t[i];
        } else {
            ans += min_distance(l, t[i], n, r);
            l = t[i];
        }
    }

    cout << ans << endl;
    return 0;
}
