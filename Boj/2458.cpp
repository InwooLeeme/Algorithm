// 2458번 : 키순서

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
#define MAX 501
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

int dist[MAX][MAX];

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

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    resetGraph();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    floyd(n);
    int ans = 0; // 정답
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] != INF || dist[j][i] != INF)
            { // 키가 작은 사람을 알거나 또는 키가 큰 사람을 알면
                cnt++;
            }
        }
        if (cnt == n - 1)
            ans++; // 자기 자신을 제외한 모든 사람과 연결되어 있으면
    }
    cout << ans;
    return 0;
}