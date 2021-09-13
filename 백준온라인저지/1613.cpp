// 1613번 : 역사

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
#define MAX 401
#define INF 1e9
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

int dist[MAX][MAX] = {};

void resetGraph()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            dist[i][j] = INF;
        }
    }
}

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    { // k : 거쳐가는 정점
        for (int i = 1; i <= n; i++)
        { // i : 행(출발 정점)
            for (int j = 1; j <= n; j++)
            {   // j : 열(도착 정점)
                // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int n, m, s;

int main()
{
    fastio;
    cin >> n >> m;
    resetGraph();
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1; // u가 v보다 먼저 일어남
    }
    floyd(n);
    cin >> s;
    while (s--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF && dist[b][a] == INF)
            cout << 0 << "\n";
        else if (dist[a][b] != INF)
            cout << -1 << "\n";
        else if (dist[b][a] != INF)
            cout << 1 << "\n";
    }
    return 0;
}