// 11562번 : 백양로 브레이크

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
#define MAX 251
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

void resetGraph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = i == j ? 0 : INF;
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
            { // j : 열(도착 정점)
                // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int n, m, k; // 질문의 수

int main()
{
    fastio;
    cin >> n >> m;
    resetGraph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;
        if (b == 0)
        { // 단방향
            dist[u][v] = 0;
            dist[v][u] = 1;
        }
        else if (b == 1)
        { // 양방향
            dist[u][v] = 0;
            dist[v][u] = 0;
        }
    }
    floyd(n);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << "\n";
    }
    return 0;
}