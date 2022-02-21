// 1197번 : 최소 스패닝 트리

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 100001
#define INF 1e9 + 7
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define sz(a) int((a).size())

int root[MAX];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        root[i] = i;
}

int find(int x)
{
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool Union(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return false;
    root[x] = y;
    return true;
}

struct Edge
{
    int u, v, w;
    Edge() : Edge(-1, -1, 0) {}
    Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
    bool operator<(const Edge &O) const { return w < O.w; };
};

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    Edge e[MAX];
    init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = Edge(a - 1, b - 1, c);
    }
    sort(e, e + m); // 간선을 가중치를 기준으로 오름차순 정렬
    // result : 가중치 합, cnt : 뽑은 간선의 수
    int result = 0, cnt = 0;
    for (int i = 0;; i++)
    {
        if (Union(e[i].u, e[i].v))
        {
            result += e[i].w;
            if (++cnt == n - 1)
                break; // n - 1개의 간선을 뽑으면 나감.(MST)의 조건
        }
    }
    cout << result;
    return 0;
}
