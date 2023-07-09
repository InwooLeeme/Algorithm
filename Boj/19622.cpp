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

using ti3 = tuple<int, int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<ti3> v(n);
    vector<int> d(n + 1, -1);
    for(auto& [a, b, c] : v)  cin >> a >> b >> c;
    auto Sol = [&](int x, auto&& Sol) -> int{
        if(x >= n) return 0;
        int& ret = d[x];
        if(ret != -1) return ret;
        return ret = max<int>(Sol(x + 1, Sol), Sol(x + 2, Sol) + get<2>(v[x]));
    };
    cout << Sol(0, Sol) << "\n";
    return 0;
}