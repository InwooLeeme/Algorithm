#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << ' ' << __gcd(a, b) << "\n";
    }
}