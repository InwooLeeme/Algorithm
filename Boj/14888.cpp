#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

constexpr int INF = int(2e9);

int n,a,b,c,d,mx = -INF, mn = INF;
int v[22];

void f(int depth, int cur, int a, int b, int c, int d){
    if(a < 0 || b < 0 || c < 0 || d < 0) return;
    if(depth == n){
        mx = max<int>(mx, cur);
        mn = min<int>(mn, cur);
        return;
    }
    f(depth + 1, cur + v[depth], a - 1, b, c, d);
    f(depth + 1, cur - v[depth], a, b - 1, c, d);
    f(depth + 1, cur * v[depth], a, b, c - 1, d);
    f(depth + 1, cur / v[depth], a, b, c, d - 1);
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> a >> b >> c >> d;
    f(1, v[0], a, b, c, d);
    cout << mx << "\n" << mn << "\n";
    return 0;
}