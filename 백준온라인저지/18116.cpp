// 18116번 : 로봇 조립

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define X first
#define Y second
#define pb push_back
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using wector = vector<vector<int>>;
using tii = tuple<int, int, int>;

struct UnionFind
{
    vector<int> parent, rank, cnt;
    UnionFind(int n) : parent(n), rank(n, 1), cnt(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find(int x)
    {
        return x == parent[x] ? x : parent[x] = Find(parent[x]);
    }
    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b)
            return 0;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        rank[a] += rank[a] == rank[b];
        cnt[a] += cnt[b];
        return 1;
    }
};

int main()
{
    fastio;
    int N;
    cin >> N;
    UnionFind UF(1000001);
    while (N--)
    {
        char c;
        cin >> c;
        if (c == 'I')
        {
            int a, b;
            cin >> a >> b;
            UF.Union(a, b);
        }
        else
        { // Q
            int c;
            cin >> c;
            cout << UF.cnt[UF.Find(c)] << "\n";
        }
    }
    return 0;
}