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
const int MOD = int(1e9) + 7;

int minv(int a, int b) {
    if (a == 0 && b == 1) return 0;
    if (a == 1) return 1;
    return b - minv(b % a, a) * b / a;
}

void Main(){
    int n,ret = 0; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        int g = gcd(a, b); a /= g, b /= g;
        ret = (ret + b * minv(a, MOD)) % MOD;
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}