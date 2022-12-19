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

#define int int64_t

int32_t main(){
    fastio;
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        auto Check = [&](int x) -> bool{
            for(int i = x; i; i /= 10) if(i % 10 == 0) return 0;
            return 1;
        }; 
        for(int i = N + 1; ; i++){
            if(Check(i)){
                cout << i << "\n";
                break;
            }
        }
    }    
    return 0;
}