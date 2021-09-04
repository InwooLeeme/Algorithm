// 4195번 : 친구 네트워크

#include <bits/stdc++.h>
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
    int Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b)
            return cnt[a];
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        rank[a] += rank[a] == rank[b];
        cnt[a] += cnt[b];
        return cnt[a];
    }
};

int main()
{
    fastio;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, cnt = 1;
        cin >> n;
        UnionFind UF(2 * n);
        unordered_map<string, int> UM;
        for (int i = 1; i <= n; i++)
        {
            string a, b;
            cin >> a >> b;
            if (!UM.count(a))
                UM[a] = cnt++;
            if (!UM.count(b))
                UM[b] = cnt++;
            cout << UF.Union(UM[a], UM[b]) << "\n";
        }
    }
    return 0;
}