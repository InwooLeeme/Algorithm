// https://www.acmicpc.net/problem/14567

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 100001
#define INF 1e9 + 7
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
	int n, m;
	cin >> n >> m;
	vector<int> adj[1001];
	vector<int> indegree(n), check(n);
	for (int i = 0; i < m; i++)
	{
		int prev, cur;
		cin >> prev >> cur;
		--prev, --cur;
		adj[prev].pb(cur);
		indegree[cur]++;
	}
	// 위상 정렬 준비
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (!indegree[i])
		{
			check[i] = 1;
			q.push(i);
		}
	// 위상 정렬 시작
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (auto nxt : adj[cur])
		{
			if (--indegree[nxt] == 0)
			{
				check[nxt] = check[cur] + 1;
				q.push(nxt);
			}
		}
	}
	for (auto i : check)
		cout << i << ' ';
	cout << "\n";
	return 0;
}