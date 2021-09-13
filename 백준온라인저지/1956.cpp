// 1956번 : 운동

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
#define INF 1000000000
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
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
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

void printGraph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF" << ' ';
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int n, m;

int main()
{
    fastio;
    cin >> n >> m;
    resetGraph();
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    floyd(n);
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((dist[i][j] != INF && dist[j][i] != INF))
            {
                ans = min(ans, dist[i][j] + dist[j][i]);
            }
        }
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}