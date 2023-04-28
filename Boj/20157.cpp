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

constexpr int INF = 1e9 + 7;

using pt = pair<int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,mx = 0; cin >> n;
    map<pt, int> M;
    for(int i = 0,a,b; i < n; i++){
        cin >> a >> b;
        int g = __gcd(abs(a), abs(b));
        M[{a / g, b / g}]++;
        mx = max<int>(mx, M[{a / g, b / g}]);
    }
    cout << mx << "\n";
    return 0;
}