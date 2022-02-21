#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

constexpr int INF = 1e9 + 7;
vector<pii> adj[20001];

int32_t main()
{
  fastio;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }
  vector<int> dist(200001, INF);
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  dist[k] = 0;
  pq.push({dist[k], k});
  while(!pq.empty()){
    auto [cost, cur] = pq.top(); pq.pop();
    if(dist[cur] < cost) continue;
    for(auto [ncost, nxt] : adj[cur]){
      if(dist[nxt] > ncost + cost){
        dist[nxt] = ncost + cost;
        pq.push({dist[nxt], nxt});
      }
    }
  }
  for(int i = 1; i <= n; i++) dist[i]==INF ? cout << "INF\n" : cout << dist[i] << "\n";
}