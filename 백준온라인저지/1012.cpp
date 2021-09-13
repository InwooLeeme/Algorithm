#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 50
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

using namespace std;

int graph[MAX][MAX];
bool vist[MAX][MAX];
int m, n, k; // m : 가로길이, n : 세로길이, k : 배추의 위치

int main()
{
    fastio;
    int tc;
    cin >> tc;
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
            cout << graph[i][j];
        }
        cout << "\n";
    }
    return 0;
}