// 1012번 : 유기농 배추(DFS 실버 1)

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ffor(i, x) for (int(i) = 0; (i) < (x); ++(i))
#define fffor(i, x) for (int(i) = 1; (i) <= (x); ++(i))
#define cc(x) cin >> (x);
#define ccc(x) \
    int(x);    \
    cin >> (x);
#define coo(x) cout << x << '\n';
#define cob(x) cout << x << ' ';
#define ii pair<int, int>
#define ll long long
#define MAX 51
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int INF = 1e9 + 7;

int graph[MAX][MAX] = {
    0,
};
bool vist[MAX][MAX] = {
    false,
};
int m, n, k; // m : 가로길이, n : 세로길이, k : 배추의 위치의 갯수

int main()
{
    int tc;
    while (tc--)
    {
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}