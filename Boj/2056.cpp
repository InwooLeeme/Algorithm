// 2056번 : 작업

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using wector = vector<vector<int>>;

int main()
{
    fastio;
    int n;
    cin >> n;
    vi adj[10001];
    vi indegree(n), time(n), d(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> time[i];
        cin >> x;
        while (x--)
        {
            int b;
            cin >> b;
            --b;
            indegree[i]++;
            adj[b].pb(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
        { // 들어오는 간선이 0이다 = 기본 작업
            d[i] = time[i];
            q.push(i);
        }
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (auto nxt : adj[cur])
        {
            d[nxt] = max(d[nxt], d[cur] + time[nxt]); // 현재 시간까지의 합 + 다음 시간의 최댓값
            if (--indegree[nxt] == 0)
                q.push(nxt);
        }
    }
    cout << *max_element(d.begin(), d.end()) << "\n";
    return 0;
}