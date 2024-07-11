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

const int PRECISION = 0;

constexpr int MOD = int(1e9) + 7;
int D[1'000'011] = {0, 1, 2, 3, 4, };

void Main(){
    int n,m; cin >> n >> m;
    int x = n * m;
    for(int i = 5; i <= 1'000'000; i++) D[i] = 3 * D[i - 3] % MOD;
    cout << D[x] << "\n";
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
