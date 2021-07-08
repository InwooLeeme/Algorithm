// 1697번 : 숨바꼭질(실버 1)

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001

using namespace std;

int dist[MAX];
int n, k;

int main()
{
    fastio;
    cin >> n >> k;
    memset(dist, -1, sizeof(dist)); // 모든 거리를 -1로 초기화 시킨다
    queue<int> Q;
    dist[n] = 0;
    Q.push(n);
    while (!Q.empty())
    {
        int cur = Q.front(); // 현재 큐에 있는 좌표
        Q.pop();
        for (int i : {cur + 1, cur - 1, 2 * cur})
        {
            if (i < 0 || i > MAX - 1)
            {
                continue;
            }
            if (dist[i] != -1)
                continue;
            dist[i] = dist[cur] + 1;
            Q.push(i);
            if (i == k)
                break;
        }
    }
    cout << dist[k];
    return 0;
}