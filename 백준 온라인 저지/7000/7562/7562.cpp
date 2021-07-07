// 7562번 : 나이트의 이동(실버 2)

#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 300
using namespace std;

int graph[MAX][MAX] = {
    0,
}; // 인접 행렬 그래프
bool visit[MAX][MAX] = {
    false,
};

int l, sX, sY, dX, dY;                   // sx : 출발 x좌표, sy : 출발 y좌표, dx : 도착 x좌표, dy : 도착 y좌표, l : 그래프의 최대 크기
int dx[] = {2, 1, 2, 1, -1, -2, -2, -1}; // 8방향 x좌표 탐색
int dy[] = {1, 2, -1, -2, 2, 1, -1, -2}; // 8방향 y좌표 탐색
queue<pair<int, int>> Q;

//최단 거리를 구해야 하기 때문에 bfs를 사용

void bfs(int x, int y)
{
    visit[x][y] = true;
    while (!Q.empty())
    {
        auto cur = Q.front();
        visit[cur.first][cur.second] = true;
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            int newX = cur.first + dx[i];
            int newY = cur.second + dy[i];
            if (newX < 0 || newX >= l || newY < 0 || newY >= l)
                continue;
            if (visit[newX][newY] == false && graph[newX][newY] == 0)
            {
                graph[newX][newY] = graph[cur.first][cur.second] + 1;
                visit[newX][newY] = true;
                Q.push(make_pair(newX, newY));
            }
        }
    }
}

int main()
{
    fastio;
    int tc; // 테스트 케이스
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> l;
        cin >> sX >> sY;
        graph[sX][sY] = 1;
        Q.push(make_pair(sX, sY));
        cin >> dX >> dY;
        if (sX == dX && sY == dY)
        {
            cout << '0' << "\n";
            continue;
        }
        bfs(sX, sY);
        cout << graph[dX][dY] - 1 << "\n";
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                visit[i][j] = false;
                graph[i][j] = 0;
            }
        }
    }
    return 0;
}