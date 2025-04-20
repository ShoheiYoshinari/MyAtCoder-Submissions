#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for(auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for(auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b){ a = b; return true; } return false; }
template<class T> constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T> constexpr T HINF() { return INF<T>()/2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
    INIT(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

struct City {
    int id;
    double cx, cy;
};

double dist2(double ax, double ay, double bx, double by) {
    double dx = ax - bx, dy = ay - by;
    return dx*dx + dy*dy;
}

vector<int> clusteringAssignment(const vector<City>& cities, const vector<int>& groupSize, int iterationLimit = 10) {
    int n = cities.size(), m = groupSize.size();
    vector<City> seedCities;
    vector<int> seedIndices;
    int first = 0;
    seedCities.push_back(cities[first]);
    seedIndices.push_back(first);
    for (int k = 1; k < m; k++) {
        double bestD = -1;
        int bestIdx = -1;
        rep(i, n) {
            if(find(seedIndices.begin(), seedIndices.end(), cities[i].id) != seedIndices.end())
                continue;
            double dmin = 1e18;
            for(auto &seed : seedCities)
                dmin = min(dmin, dist2(cities[i].cx, cities[i].cy, seed.cx, seed.cy));
            if(dmin > bestD) {
                bestD = dmin;
                bestIdx = i;
            }
        }
        seedCities.push_back(cities[bestIdx]);
        seedIndices.push_back(cities[bestIdx].id);
    }
    vector<int> assign(n, -1);
    vector<vector<pair<double,int>>> cityPref(n);
    for (int iter = 0; iter < iterationLimit; iter++) {
        vector<int> remain = groupSize;
        vector<int> newAssign(n, -1);
        rep(i, n) {
            cityPref[i].clear();
            for (int g = 0; g < m; g++) {
                double d = dist2(cities[i].cx, cities[i].cy, seedCities[g].cx, seedCities[g].cy);
                cityPref[i].push_back({d, g});
            }
            sort(cityPref[i].begin(), cityPref[i].end());
        }
        rep(i, n) {
            for(auto &p : cityPref[i]) {
                int g = p.second;
                if(remain[g] > 0) {
                    newAssign[i] = g;
                    remain[g]--;
                    break;
                }
            }
            if(newAssign[i] == -1)
                newAssign[i] = 0;
        }
        if(newAssign == assign) break;
        assign = newAssign;
        vector<double> sumX(m, 0), sumY(m, 0);
        vector<int> count(m, 0);
        rep(i, n) {
            int g = assign[i];
            sumX[g] += cities[i].cx;
            sumY[g] += cities[i].cy;
            count[g]++;
        }
        for (int g = 0; g < m; g++) {
            if(count[g] > 0) {
                seedCities[g].cx = sumX[g] / count[g];
                seedCities[g].cy = sumY[g] / count[g];
            }
        }
    }
    return assign;
}

vector<pair<double,double>> computeCentroids(const vector<int>& assign, const vector<City>& cities, int m) {
    vector<double> sumX(m, 0), sumY(m, 0);
    vector<int> count(m, 0);
    int n = cities.size();
    rep(i, n) {
        int g = assign[i];
        sumX[g] += cities[i].cx;
        sumY[g] += cities[i].cy;
        count[g]++;
    }
    vector<pair<double,double>> centroids(m, {0,0});
    rep(g, m) {
        if(count[g] > 0)
            centroids[g] = {sumX[g]/count[g], sumY[g]/count[g]};
    }
    return centroids;
}

vector<int> fixGroupSizes(vector<int> assign, const vector<int>& groupSize, const vector<City>& cities) {
    int n = cities.size(), m = groupSize.size();
    vector<int> count(m, 0);
    rep(i, n) count[assign[i]]++;
    bool updated = true;
    while(updated){
        updated = false;
        auto centroids = computeCentroids(assign, cities, m);
        vector<int> deficit;
        rep(g, m){
            if(count[g] < groupSize[g])
                deficit.push_back(g);
        }
        rep(i, n){
            int g = assign[i];
            if(count[g] <= groupSize[g]) continue;
            double currD = dist2(cities[i].cx, cities[i].cy, centroids[g].first, centroids[g].second);
            for (int j : deficit){
                double newD = dist2(cities[i].cx, cities[i].cy, centroids[j].first, centroids[j].second);
                if(newD < currD){
                    assign[i] = j;
                    count[g]--;
                    count[j]++;
                    updated = true;
                    break;
                }
            }
        }
    }
    rep(g, m){
        while(count[g] > groupSize[g]){
            rep(i, n){
                if(assign[i]==g){ assign[i] = -1; count[g]--; break; }
            }
        }
    }
    rep(g, m){
        while(count[g] < groupSize[g]){
            rep(i, n){
                if(assign[i]==-1){ assign[i]=g; count[g]++; break; }
            }
        }
    }
    return assign;
}

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n) { rep(i, n) par[i]=i; }
    int find(int x) { return par[x]==x ? x : par[x]=find(par[x]); }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx==ry) return false;
        par[ry] = rx; return true;
    }
};

struct Edge {
    int u, v;
    ll d;
};
vector<Edge> buildMST(const vector<City>& groupCities) {
    vector<Edge> edges;
    int gs = groupCities.size();
    rep(i, gs){
        for(int j = i+1; j < gs; j++){
            double dx = groupCities[i].cx - groupCities[j].cx;
            double dy = groupCities[i].cy - groupCities[j].cy;
            ll d = (ll)floor(dx*dx + dy*dy);
            int u = groupCities[i].id, v = groupCities[j].id;
            if(u > v) swap(u,v);
            edges.push_back({u, v, d});
        }
    }
    sort(all(edges), [](const Edge &a, const Edge &b){
        if(a.d==b.d){
            if(a.u==b.u) return a.v < b.v;
            return a.u < b.u;
        }
        return a.d < b.d;
    });
    vector<Edge> mst;
    vector<int> idToIndex(10000, -1);
    rep(i, gs){
        idToIndex[groupCities[i].id] = i;
    }
    UnionFind uf(gs);
    for(auto &e : edges){
        int idx_u = idToIndex[e.u], idx_v = idToIndex[e.v];
        if(uf.unite(idx_u, idx_v)){
            mst.push_back(e);
            if(mst.size() == (unsigned)(gs-1))
                break;
        }
    }
    return mst;
}

void adjustCoordinatesHalf(vector<City>& cities, int &queriesUsed, int Q, int L) {
    int n = cities.size();
    if(queriesUsed >= Q) return;
    int sampleSize = L;
    vector<int> subset;
    {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        random_shuffle(perm.begin(), perm.end());
        for (int i = 0; i < sampleSize; i++) {
            subset.push_back(perm[i]);
        }
    }
    cout << "? " << sampleSize;
    for (int idx : subset) {
        cout << " " << cities[idx].id;
    }
    cout << "\n" << flush;
    queriesUsed++;
    set<pair<int,int>> mstQuery;
    for (int i = 0; i < sampleSize - 1; i++){
        int a, b;
        cin >> a >> b;
        mstQuery.insert({a, b});
    }
    vector<City> subsetCities;
    for (int idx : subset) {
        subsetCities.push_back(cities[idx]);
    }
    vector<Edge> mstEst = buildMST(subsetCities);
    set<pair<int,int>> mstEstSet;
    for (auto &e : mstEst){
        mstEstSet.insert({e.u, e.v});
    }
    double eta = 0.01;
    map<int, pair<double,double>> adjust;
    for (auto &e : mstQuery) {
        if(mstEstSet.find(e) == mstEstSet.end()){
            int idx_u = -1, idx_v = -1;
            for (int idx : subset) {
                if(cities[idx].id == e.first) idx_u = idx;
                if(cities[idx].id == e.second) idx_v = idx;
            }
            if(idx_u == -1 || idx_v == -1) continue;
            double dx = cities[idx_v].cx - cities[idx_u].cx;
            double dy = cities[idx_v].cy - cities[idx_u].cy;
            adjust[idx_u].first  += eta * dx;
            adjust[idx_u].second += eta * dy;
            adjust[idx_v].first  -= eta * dx;
            adjust[idx_v].second += eta * dy;
        }
    }
    for (auto &e : mstEstSet) {
        if(mstQuery.find(e) == mstQuery.end()){
            int idx_u = -1, idx_v = -1;
            for (int idx : subset) {
                if(cities[idx].id == e.first) idx_u = idx;
                if(cities[idx].id == e.second) idx_v = idx;
            }
            if(idx_u == -1 || idx_v == -1) continue;
            double dx = cities[idx_v].cx - cities[idx_u].cx;
            double dy = cities[idx_v].cy - cities[idx_u].cy;
            adjust[idx_u].first  -= eta * 0.5 * dx;
            adjust[idx_u].second -= eta * 0.5 * dy;
            adjust[idx_v].first  += eta * 0.5 * dx;
            adjust[idx_v].second += eta * 0.5 * dy;
        }
    }
    for (auto &p : adjust) {
        int idx = p.first;
        cities[idx].cx += p.second.first;
        cities[idx].cy += p.second.second;
    }
}

vector<int> getDifficultCities(const vector<City>& cities, double threshold) {
    int n = cities.size();
    vector<Edge> mst = buildMST(cities);
    vector<double> error(n, 0.0);
    for(auto &e : mst){
        error[e.u] = max(error[e.u], (double)e.d);
        error[e.v] = max(error[e.v], (double)e.d);
    }
    vector<int> difficult;
    for (int i = 0; i < n; i++){
        if(error[i] > threshold)
            difficult.push_back(i);
    }
    return difficult;
}

int main(){
    int n, m, q, L, dummyW;
    cin >> n >> m >> q >> L >> dummyW;
    vector<int> groupSize(m);
    rep(i, m) cin >> groupSize[i];
    
    vector<City> cities;
    rep(i, n) {
        int lx, rx, ly, ry;
        cin >> lx >> rx >> ly >> ry;
        double cx = (lx + rx) / 2.0;
        double cy = (ly + ry) / 2.0;
        cities.push_back({i, cx, cy});
    }
    
    int queriesUsed = 0;
    while(queriesUsed < q){
        adjustCoordinatesHalf(cities, queriesUsed, q, L);
    }
    
    // 全体の中から誤差が大きい都市を抽出して部分補正
    double errorThreshold = 1e7; // 閾値（適宜調整）
    vector<int> difficult = getDifficultCities(cities, errorThreshold);
    if(!difficult.empty() && difficult.size() < (size_t)n) {
        adjustCoordinatesHalf(cities, queriesUsed, q, L);
    }
    
    // クラスタリングとグループ割当
    vector<int> assign = clusteringAssignment(cities, groupSize, 20);
    assign = fixGroupSizes(assign, groupSize, cities);
    vector<vector<int>> groups(m);
    rep(i, n) {
        groups[assign[i]].push_back(cities[i].id);
    }
    
    // 各グループ内でMST構築
    vector<vector<Edge>> groupEdge(m);
    rep(g, m) {
        vector<City> groupCities;
        for (int id : groups[g])
            groupCities.push_back(cities[id]);
        groupEdge[g] = buildMST(groupCities);
    }
    
    // 出力
    cout << "!" << "\n";
    rep(g, m) {
        rep(i, groups[g].size())
            cout << groups[g][i] << (i+1 == groups[g].size() ? "\n" : " ");
        for (auto &e : groupEdge[g])
            cout << e.u << " " << e.v << "\n";
    }
    return 0;
}
