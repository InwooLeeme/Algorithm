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
    int n,sum = 0; cin >> n;
    vector<pt> v(n);
    for(auto& [a, b] : v) cin >> a >> b, sum += b;
    sort(v.begin(), v.end());
    sum = (sum & 1 ? sum + 1 : sum);
    int cur = 0;
    for(const auto& [a, b] : v){
        cur += b;
        if(cur >= (sum >> 1)){
            cout << a << "\n";
            return 0;
        }
    }
    return 0;
}