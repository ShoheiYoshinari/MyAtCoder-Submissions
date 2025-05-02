#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

#include <bits/stdc++.h>
using namespace std;

/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
    insert(word): 単語 word を Trie 木に挿入する
    search(word): 単語 word が Trie 木にあるか判定する
    start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
    count(): 挿入した単語の数を返す
    size(): Trie 木の頂点数を返す
    計算量：insert, search ともに O(M)（Mは単語の長さ）
*/
template <int char_size, int base>
struct Trie {
    struct Node {            // 頂点を表す構造体
        vector<int> next;    // 子の頂点番号を格納。存在しなければ-1
        vector<int> accept;  // 末端がこの頂点になる単語の word_id を保存
        int c;               // base からの間隔をint型で表現したもの
        int common;          // いくつの単語がこの頂点を共有しているか
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;  // trie 木本体
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    // 単語の挿入
    void insert(const string &word, int word_id) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = (int)nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);
    }
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }

    // 単語とprefixの検索
    bool search(const string &word, bool prefix = false) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].accept.size() > 0;
    }

    // prefix を持つ単語が存在するかの検索
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }

    // prefix を持つ単語が存在するかの検索
    bool has_prefix(const string& word){
        int node_id = 0;
        for(int i = 0; i <(int)word.size(); i++){
            if(!nodes[node_id].accept.empty()) return true;
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if(next_id == -1){
                return false;
            }
            node_id = next_id;
        }
        return !nodes[node_id].accept.empty();
    }

    // 挿入した単語の数
    int count() const {
        return (nodes[0].common);
    }
    // Trie木のノード数
    int size() const {
        return ((int)nodes.size());
    }

    // 指定したprefixを持つ単語の削除
    int del(const string &prefix){
        int node_id = 0;
        for (int i = 0; i < (int)prefix.size(); i++) {
            int c = (int)(prefix[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return 0;
            }
            node_id = next_id;
        }

        stack<int> st;
        int accept_cnt = 0;
        st.push(node_id);
        while(!st.empty()){
            int id = st.top();
            st.pop();
            accept_cnt += nodes[id].accept.size();
            nodes[id].accept.clear();
            for(int i = 0; i < char_size; i++){
                if(nodes[id].next[i] != -1){
                    st.push(nodes[id].next[i]);
                }
            }
        }
        return accept_cnt;
    }

    bool exist_prefix(const string &prefix){
        int node_id = 0;
        for (int i = 0; i < (int)prefix.size(); i++) {
            int c = (int)(prefix[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = next_id;
            if(nodes[node_id].accept.size() > 0) return true;
        }
        return false;
    }
};

int main(){
    int q;
    cin >> q;
    Trie<26, 'a'> trie, y;
    int del_cnt = 0;
    while(q--){
        int t;
        string s;
        cin >> t >> s;
        if(t == 1){
            int res = y.del(s);
            del_cnt += res;
            trie.insert(s);
        }else if(t == 2){
            if(!trie.exist_prefix(s)){
                y.insert(s);
            }
        }
        cout << y.count() - del_cnt << endl;
    }
    return 0;
}