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
    for(int tc = 1,ret = 0; tc <= T; tc++){
        int N; cin >> N;
        map<int, bool> M;
        for(int i = 0,x; i < N; i++){
            cin >> x;
            if(!M.count(x)) ret = i + 1;
            M[x] = 1;
        }
        cout << "Case " << tc << ": " << ret << "\n";
    }
    return 0;
}