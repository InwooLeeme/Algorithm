#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ii pair<int, int>
#define ll long long
#define MAXW 51
#define MAXH 14
using namespace std;

int map[MAXW][MAXH];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}