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

using pt = pair<int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int s,n,mx = 0; cin >> s >> n;
    vector<pt> v(n);
    for(auto& [a, b] : v) cin >> a >> b;
    for(int x = 0; x <= 100 - s; x++){
        for(int y = 0; y <= 100 - s; y++){
            int cnt = 0;
            auto Inside = [&](int a, int b, int c, int d, int l, int r) -> bool{ 
                return (a <= l and l <= b and c <= r and r <= d); 
            };
            for(auto& [a, b] : v) if(Inside(x, x + s, y, y + s, a, b)) cnt++;
            mx = max<int>(mx, cnt);
        }
    }
    cout << mx << "\n";
    return 0;
}