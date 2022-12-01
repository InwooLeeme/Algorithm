#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int64_t

int32_t main(){
    fastio;
    int n;
    cin >> n;
    int best = LLONG_MAX, retx = -1, rety = -1;
    for (int x = 0; x <= n; ++x) {
        int y = int(sqrt(n * n - x * x));
        while (y * y + x * x <= n * n) {
            ++y;
        }
        if (y * y + x * x < best || (y * y + x * x == best && rand() % 2 == 0)) {
            retx = x;
            rety = y;
            best = y * y + x * x;
        }
    }
    cout << retx << " " << -rety;
    return 0;
}