// 1504번 : 특정한 최단 경로

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cassert>
#define X first
#define Y second
#define pb push_back
#define MAX 801
#define INF 1e9
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ffor(i, x) for (int(i) = 0; (i) < (x); ++(i))
#define coutln(x) cout << x << '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

vector<pair<int, int>> adj[MAX]; // 노드들의 정보들을 담는 벡터

int v1, v2;     // v1,v2 : 거쳐가야하는 정점
int n, e;       // n : 정점의 갯수, e : 간선의 갯수
int n1, n2, n3; // n1 : 1 -> v1까지, n2 : v2->v3까지,
int e1, e3;     // e1 : 1 -> v2, e2 : v2 -> v1, e3 : v1 -> n

int dijkstra(int start, int dest)
{
    vector<int> dist(MAX, INF); //최단거리를 저장하는 배열, dist배열 초기화 해준다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < weight)
            continue;
        if (cur == dest)
            return dist[cur];
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int nWeight = adj[cur][i].first;
            int next = adj[cur][i].second;
            if (dist[next] > nWeight + weight)
            {
                dist[next] = nWeight + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return INF;
}

int main()
{
    fastio;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
        adj[b].pb({c, a});
    }
    cin >> v1 >> v2;
    n1 = dijkstra(1, v1);
    n2 = dijkstra(v1, v2);
    n3 = dijkstra(v2, n);
    e1 = dijkstra(1, v2);
    e3 = dijkstra(v1, n);
    if ((n1 + n2 + n3 >= INF || n1 + n2 + n3 < 0) || (e1 + n2 + e3 >= INF || e1 + n2 + e3 < 0))
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << min(n1 + n2 + n3, e1 + n2 + e3) << "\n";
    }
    return 0;
}