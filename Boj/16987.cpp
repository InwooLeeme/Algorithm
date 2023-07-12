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

int n;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<pt> v(n);
    for(auto& [a, b] : v) cin >> a >> b; // 내구도, 무게
    auto Sol = [&](int x,auto&& Sol) -> int{
        if(x == n){ // base case
            int cnt = 0;
            for(int i = 0; i < n; i++) if(v[i].first <= 0) cnt++;
            return cnt;
        }
        if(v[x].first <= 0) return Sol(x + 1, Sol);
        int ret = 0,flag = 0;
        for(int i = 0; i < n; i++){
            if(i == x or v[i].first <= 0) continue;
            flag = 1;
            v[x].first -= v[i].second;
            v[i].first -= v[x].second;
            ret = max<int>(ret, Sol(x + 1, Sol));
            v[x].first += v[i].second;
            v[i].first += v[x].second;
        }
        if(!flag) return Sol(x + 1, Sol);
        return ret;
    };
    cout << Sol(0, Sol) << "\n";
    return 0;
}