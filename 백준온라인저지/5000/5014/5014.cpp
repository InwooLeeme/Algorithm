// 5014번 : 스타트 링크

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cmath>
#include <map>
#include <deque>
#include <limits.h>
#include <utility>
#include <list>
#include <unordered_map>
#include <string.h>
#include <random>
#include <queue>
#define max 1000001
#define ffor(i, x) for (int(i) = 0; (i) < (x); ++(i))
#define INF 1e9
#define pii pair<int, int>
#define lli long long int
using namespace std;

int vist[max];
int u, d, f, g, s; // f : 사무실의 총 수, u : 위로가는 버튼, d: 아래로가는 버튼,
// g : 도착지의 위치, s : 현재 있는 곳

int bfs(int x)
{
    queue<pii> Q; // <위치,시간>순
    Q.push(make_pair(x, 0));
    int ans = 0;
    while (!Q.empty())
    {
        int cur = Q.front().first;
        int time = Q.front().second;
        vist[cur] = true;
        Q.pop();
        if (cur == g)
        {
            return time;
        }
        for (int i : {cur + u, cur - d})
        {
            if (i <= 0 || i > f)
                continue;
            if (vist[i])
                continue;
            Q.push(make_pair(i, time + 1));
            vist[i] = true;
        }
    }
    return -1;
}

int main()
{
    cin >> f >> s >> g >> u >> d;
    int ans = bfs(s);
    if (ans != -1)
    {
        printf("%d", ans);
    }
    else
        printf("use the stairs");
    return 0;
}