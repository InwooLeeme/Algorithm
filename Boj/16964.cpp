// DFS 스페셜 저지

#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
bool visit[MAX] = {
    false,
};
vector<int> order;         // 입력으로 들어온 정점 순서
vector<int> expectedVisit; // 실제로 방문한 정점 순서
void dfs(int v)
{
    visit[v] = true;
    cout << v << '\n';
    for (int i; i < graph[v].size(); i++)
    {
        int next = graph[v][i];
        if (visit[next])
            continue;
        dfs(next);
    }
}

int main()
{
    fastio;
    int n = 0; // 정점의 개수
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        order.push_back(x);
    }
    for (int i : graph[2])
    {
        cout << i;
    }
    for (int i = 0; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(1);
    return 0;
}