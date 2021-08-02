// 14938번 : 서강그라운드

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

int n, m, r; // n : 지역의 개수, m : 수색 범위, r : 길의 개수
int dist[MAX][MAX];

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
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

int main()
{
    fastio;
    cin >> n >> m >> r;
    vi items(n + 1);
    reset(n);
    for (int i = 1; i <= n; i++)
        cin >> items[i];
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    floyd(n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    { // i : 행(출발 정점)
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        { // j : 열(도착 정점)
            if (i == j || (0 < dist[i][j] && dist[i][j] <= m))
            {
                cnt += items[j];
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}