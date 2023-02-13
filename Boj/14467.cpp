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
    int n,ret = 0; cin >> n;
    map<int, int> M;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        if(!M.count(a)){
            M[a] = b;
            continue;
        }
        if(M.count(a) and M[a] != b){
            M[a] = b;
            ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}