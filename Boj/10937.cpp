#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

int n;
vector<string> board(12);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
bool Bound(int x, int y) { return x < 0 or x >= n or y < 0 or y >= n; }

int DB[4][4] = {
    {100, 70, 40, 0},
	{70, 50, 30, 0},
	{40, 30, 20, 0},
	{0, 0, 0, 0},
};

using pii = pair<int, int>;
constexpr int INF = 1e9 + 7;

struct MCMF { //reference : https://justicehui.github.io/hard-algorithm/2020/03/24/effective-mcmf/
    struct Edge {
        int nxt;
        int inv; //inverse edge index
        int res; //residual
        int cost; //cost
    };

    vector<vector<Edge>> adj;
    vector<int> h, inq; //johnson's algorithm, spfa
    vector<int> dist; //dijkstra
    vector<int> check, work; //max flow
    int sz, s, e; //source, sink

    MCMF(int sz) :
        adj(sz), h(sz), inq(sz),
        dist(sz), check(sz), work(sz),
        sz(sz), s(-1), e(-1) {
    }

    void set_source(int t) { s = t; }
    void set_sink(int t) { e = t; }
    void add_edge(int a, int b, int fl, int cost) {
        Edge forward{ b, (int)adj[b].size(), fl, cost };
        Edge reverse({ a, (int)adj[a].size(), 0, -cost });
        adj[a].push_back(forward);
        adj[b].push_back(reverse);
    }
    void init() {
        fill(h.begin(), h.end(), INF);
        fill(dist.begin(), dist.end(), INF);

        //johnson's algorithm with spfa
        queue<int> Q;
        inq[s] = 1;
        Q.push(s);
        while (Q.size()) {
            int cur = Q.front(); Q.pop(); inq[cur] = 0;
            for (auto i : adj[cur]) {
                if (i.res && h[i.nxt] > h[cur] + i.cost) {
                    h[i.nxt] = h[cur] + i.cost;
                    if (!inq[i.nxt]) {
                        inq[i.nxt] = 1;
                        Q.push(i.nxt);
                    }
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            for (auto& j : adj[i]) {
                if (j.res) j.cost += h[i] - h[j.nxt];
            }
        }

        //get shortest path DAG with dijkstra
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        dist[s] = 0;
        PQ.push({ dist[s], s });
        while (PQ.size()) {
            auto [cost, cur] = PQ.top();
            PQ.pop();
            if (dist[cur] ^ cost) continue;
            for (auto i : adj[cur]) {
                if (i.res && dist[i.nxt] > dist[cur] + i.cost) {
                    dist[i.nxt] = dist[cur] + i.cost;
                    PQ.push({ dist[i.nxt], i.nxt });
                }
            }
        }
        for (int i = 0; i < sz; i++) dist[i] += h[e] - h[s];
    }
    bool update() { //update shortest path DAG in O(V+E)
        int mn = INF;
        for (int i = 0; i < sz; i++) {
            if (!check[i]) continue;
            for (auto j : adj[i]) {
                if (j.res && !check[j.nxt]) mn = min(mn, dist[i] + j.cost - dist[j.nxt]);
            }
        }
        if (mn >= INF) return 0;
        for (int i = 0; i < sz; i++) {
            if (!check[i]) dist[i] += mn;
        }
        return 1;
    }
    int dfs(int cur, int fl) {
        check[cur] = 1;
        if (cur == e) return fl;
        for (; work[cur] < adj[cur].size(); work[cur]++) {
            auto& i = adj[cur][work[cur]];
            if (!check[i.nxt] && dist[i.nxt] == dist[cur] + i.cost && i.res) {
                int ret = dfs(i.nxt, min(fl, i.res));
                if (ret) {
                    i.res -= ret;
                    adj[i.nxt][i.inv].res += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    pii mcmf() { //cost, flow
        if (s == -1 || e == -1) return { -1, -1 };
        init();
        int cost = 0, fl = 0;
        do {
            fill(check.begin(), check.end(), 0);
            fill(work.begin(), work.end(), 0);
            int cur = 0;
            while (cur = dfs(s, INF)) {
                cost += dist[e] * cur;
                fl += cur;
                fill(check.begin(), check.end(), 0);
            }
        } while (update());
        return { cost, fl };
    }
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(auto& j : board[i]) if(j == 'F') j = 'D';
    }
    int s = n*n + 2, e = n*n + 3;
    MCMF mcmf((n * n) << 1);
    mcmf.set_source(s);
    mcmf.set_sink(e);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        if((i + j) & 1){ // (하얀 칸)
            mcmf.add_edge(s, i *n + j, 1, 0);
            mcmf.add_edge(i * n + j, e, 1 , 0);
            for(int d = 0; d < 4; d++){
                auto nx = i + dx[d], ny = j + dy[d];
                if(Bound(nx, ny)) continue;
                mcmf.add_edge(i * n + j, nx * n + ny, 1, -DB[board[i][j] - 'A'][board[nx][ny] - 'A']);
            }
        }
        else mcmf.add_edge(i * n + j, e, 1, 0);
    }
    cout << -mcmf.mcmf().first << "\n";
    return 0;
}