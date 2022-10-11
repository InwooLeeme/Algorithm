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
    int n; cin >> n;
    vector<int> v(n, 0),D(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++){
        D[i] = D[i - 1] + abs(v[i] - v[i - 1]);
		if (i > 1) D[i] = min(D[i], D[i - 2] + abs(v[i] - v[i - 2]));
    }
    cout << D[n - 1];
    return 0;
}