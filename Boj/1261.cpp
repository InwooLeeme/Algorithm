// 1261번 : 알고스팟

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
#define MAX 101
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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int adj[MAX][MAX];
int dist[MAX][MAX];
int n, m;

void reset()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
        }
    }
}

void dijkstra()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[1][1] = adj[1][1];
    pq.push({dist[1][1], {1, 1}});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();
        if (dist[curX][curY] < weight)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int xx = curX + dx[i];
            int yy = curY + dy[i];
            int nWeight = weight + adj[xx][yy];
            if (xx < 1 || xx > m || yy < 1 || yy > n)
                continue;
            if (dist[xx][yy] > nWeight)
            {
                dist[xx][yy] = nWeight;
                pq.push({nWeight, {xx, yy}});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    reset();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }
    dijkstra();
    cout << dist[m][n] << "\n";
    return 0;
}