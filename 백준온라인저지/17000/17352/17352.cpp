// 17352번 : 여러분의 다리가 되어 드리겠습니다!

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cassert>
#define X first
#define Y second
#define pb push_back
#define MAX 300001
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

int height[MAX]; // 트리의 높이
int root[MAX];   // 루트 노드들

int find(int x)
{
    // 루트 노드가 자신이면 그대로 반환
    if (root[x] == x)
    {
        return x;
    }
    else
        return root[x] = find(root[x]);
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다. 즉, 높이가 더 높은 쪽을 root로 삼음
    if (height[x] < height[y])
    {
        root[x] = y; // x의 root를 y로 변경
    }
    else
    {
        root[y] = x; // y의 root를 x로 변경
        if (height[x] == height[y])
            height[x]++; // 만약 높이가 같다면 합친 후 (x의 높이 + 1)
    }
}

// 루트 노드 준비
void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
        height[i] = 0;
    }
}

int main()
{
    fastio;
    int n;
    cin >> n;
    reset(n);
    for (int i = 0; i < n - 2; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b); // 입력 받은 집합들을 합친다.
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == find(i))
            printf("%d ", i);
    }
    return 0;
}