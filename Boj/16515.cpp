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

int f[16]{ 1 };
double v[16]{ 1 };

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n; n = min<int>(n, 15);
    for (int i = 1; i <= 15; i++) f[i] = f[i - 1] * i;
	for (int i = 1; i <= 15; i++) v[i] = v[i - 1] + 1. / f[i];
    cout << fixed << setprecision(14) << v[n] << "\n";
    return 0;
}