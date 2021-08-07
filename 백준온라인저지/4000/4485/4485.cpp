// 4485번 : 녹색 옷 입은 애가 젤다지?

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
#define MAX 126
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
int dy[4] = {-1, 0, 1, 0};

int adj[MAX][MAX];
int dist[MAX][MAX];

int n;

void reset()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            dist[i][j] = INF;
        }
    }
}

void dijkstra()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[1][1] = adj[1][1];
    pq.push({dist[1][1], {1, 1}}); // 1번 정점에서 시작하므로 1번 정점의 가중치와 좌표값을 대입
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();
        if (dist[curX][curY] < weight)
            continue; // 이미 최솟값이므로 패스
        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            int nextWeight = weight + adj[nextX][nextY];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > n)
                continue;
            if (dist[nextX][nextY] > nextWeight)
            {
                dist[nextX][nextY] = nextWeight;
                pq.push({nextWeight, {nextX, nextY}});
            }
        }
    }
}

int main()
{
    fastio;
    int tc = 1;
    while (cin >> n)
    {
        reset();
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> adj[i][j];
            }
        }
        dijkstra();
        printf("Problem %d: %d\n", tc, dist[n][n]);
        tc++;
    }
    return 0;
}