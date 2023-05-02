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

using vi = vector<int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,c; cin >> n >> c;
    vi v(n);
    set<int> check;
    for(auto& i : v) cin >> i,check.insert(i);
    sort(v.begin(), v.end());
    auto Sol = [&]() -> int{
        if(binary_search(v.begin(), v.end(), c)) return 1;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
            if(v[i] + v[j] == c) return 1;
            int dif = c - v[i] - v[j];
            if(check.count(dif) and v[i] != dif and v[j] != dif) return 1;
        }
        return 0;
    };
    cout << Sol() << "\n";
    return 0;
}