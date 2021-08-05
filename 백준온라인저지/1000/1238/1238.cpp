// 1238번 : 파티

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
#define MAX 1001
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

vector<pair<int, int>> adj[MAX]; // 노드들의 정보들을 담는 벡터

int n, m, x;

int dijk(int start, int end)
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
        if (cur == end)
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

void Input()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b}); // 단방향임
    }
}

void Solution()
{
    int ans = 0;
    int first1 = dijk(1, x);
    int first2 = dijk(x, 1);
    ans = first1 + first2;
    for (int i = 1; i <= n; i++)
    {
        int temp1 = dijk(i, x); // i -> x
        int temp2 = dijk(x, i); // x -> i
        int result = temp1 + temp2;
        ans = max(ans, result);
    }
    cout << ans;
    return;
}

int main()
{
    fastio;
    Input();
    Solution();
    return 0;
}