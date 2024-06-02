#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int time;
    bool is_start;
};

int main() {
    int N;
    cin >> N;

    vector<Event> events;

    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, true});
        events.push_back({r, false});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.time != b.time)
            return a.time < b.time;
        return a.is_start > b.is_start;  // prioritize start over end when times are the same
    });

    long long active_intervals = 0;
    long long result = 0;

    for (const auto& event : events) {
        if (event.is_start) {
            result += active_intervals;  // new interval intersects with all currently active intervals
            active_intervals++;
        } else {
            active_intervals--;
        }
    }

    cout << result << endl;

    return 0;
}
