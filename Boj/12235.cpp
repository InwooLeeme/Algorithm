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

#define int int_fast64_t

int32_t main(){
    fastio;
    int T; cin >> T;
    for(int tc = 1,n,m; tc <= T; tc++){
        cin >> n >> m;
        vector<int> v(n);
        for(auto& i : v) cin >> i;
        sort(v.begin(), v.end());
        int st = 0,en = n - 1,ret = 0;
        while(st <= en){
            if(st == en){
                ret++;
                break;
            }
            else if(v[st] + v[en] <= m){
                ret++;
                st++;
                en--;
            }
            else ret++,en--;
        }
        cout << "Case #" << tc << ": " << ret << "\n";
    }
    return 0;
}