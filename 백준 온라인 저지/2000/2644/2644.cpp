// 2644번 : 촌수 계산
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m; // n: 전체 사람의 수, m:부모 자식들 간의 관계 개수

int num1, num2; // 촌수 계산해야하는 두사람 번호

int x, y; //부모 자식간의 관계
int dist[101];

int family[101][101];

bool visit[101];

queue<int> q;

void bfs(int i)
{
    visit[i] = true;
    q.push(i);
    int temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int k = 0; k <= n; k++)
        {
            if (family[temp][k] == 1 && visit[k] == false)
            {
                visit[k] = true;
                dist[k] = dist[temp] + 1;
                q.push(k);
            }
        }
    }
}

int main()
{
    cin >> n;            // 전체 사람의 수
    cin >> num1 >> num2; // 관계를 구해야 하는 사람
    cin >> m;            // 부모-자식 간의 관계 수

    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        family[a][b] = 1;
        family[b][a] = 1;
    }
    bfs(num1);
    if (dist[num2] != 0)
    {
        cout << dist[num2] << '\n';
    }
    else
    {
        cout << "-1" << '\n';
    }
    return 0;
}