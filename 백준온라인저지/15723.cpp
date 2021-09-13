// 15723번 : n단 논법

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
#define MAX 27
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

int dist[MAX][MAX];

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

void floyd()
{
    for (int k = 0; k < MAX; k++)
    { // k : 거쳐가는 정점
        for (int i = 0; i < MAX; i++)
        { // i : 행(출발 정점)
            for (int j = 0; j < MAX; j++)
            {   // j : 열(도착 정점)
                // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int n, m;

int main()
{
    fastio;
    cin >> n;
    resetGraph();
    char a, b;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> s >> b;
        dist[a - 'a'][b - 'a'] = 1;
    }
    cin >> m;
    floyd();
    while (m--)
    {
        char x, y;
        string s;
        cin >> x >> s >> y;
        cout << (dist[x - 'a'][y - 'a'] == INF ? 'F' : 'T') << "\n";
    }
    return 0;
}