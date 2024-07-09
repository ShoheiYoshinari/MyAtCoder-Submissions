#include <bits/stdc++.h>
using namespace std;

// マスの状態を表す構造体
struct State {
    string stones;  // 現在の石の並び
    int moves;      // 現在までの操作回数

    State(string s, int m) : stones(s), moves(m) {}
};

// 幅優先探索を使って最小操作回数を求める関数
int min_operations(string S, string T) {
    int N = S.size();
    
    // まず、白石と黒石の数が一致するか確認する
    int countS[2] = {0, 0}; // [白石の数, 黒石の数]
    int countT[2] = {0, 0}; // [白石の数, 黒石の数]

    for (char c : S) countS[c == 'W']++;
    for (char c : T) countT[c == 'W']++;

    if (countS[0] != countT[0] || countS[1] != countT[1]) return -1;

    // 幅優先探索のためのキューと訪問済みセット
    queue<State> q;
    set<string> visited;

    // 初期状態をキューに追加
    q.push(State(S, 0));
    visited.insert(S);

    // BFS開始
    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // 目的状態に達したら操作回数を返す
        if (current.stones == T) return current.moves;

        // 2つ並んだ石を移動させる操作を試みる
        for (int i = 0; i < N - 1; ++i) {
            // 2つ並んだ石を探す
            if (current.stones[i] != '.' && current.stones[i + 1] != '.') {
                // 空きマスを探して移動させる
                for (int j = 0; j < N + 1; ++j) {
                    if (current.stones[j] == '.' && current.stones[j + 1] == '.') {
                        // 石を移動させる
                        string next = current.stones;
                        swap(next[i], next[j]);
                        swap(next[i + 1], next[j + 1]);

                        // 新しい状態が未訪問ならキューに追加
                        if (visited.find(next) == visited.end()) {
                            q.push(State(next, current.moves + 1));
                            visited.insert(next);
                        }
                    }
                }
            }
        }
    }

    // 目的状態に到達できない場合
    return -1;
}

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    S += "..";
    T += "..";

    int result = min_operations(S, T);
    cout << result << endl;

    return 0;
}
