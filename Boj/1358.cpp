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

void Sol(){
    int n,m,x,y,q,ret = 0; cin >> n >> m >> x >> y >> q;
    int rd = m / 2;
    auto Check = [&](int r, int c) -> bool{
        auto d1 = ((r - x) * (r - x) + (c - (y + rd)) * (c - (y + rd)));
        auto d2 = ((r - (x + n)) * (r - (x + n)) + (c - (y + rd)) * (c - (y + rd)));
        if(d1 <= rd*rd or d2 <= rd*rd) return 1;
        return (x <= r and r <= x + n and y <= c and c <= y + m);
    };
    while(q--){
        int r,c; cin >> r >> c;
        ret += Check(r, c);
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}