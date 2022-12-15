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
    int n,m,k; 
    while(cin >> n >> m >> k and n){
        deque<int> DQ;
        for(int i = 1; i <= n; i++) DQ.push_back(i);
        int ret = 0;
        while(k--){
            for(int j = 0; j < m - 1; j++){
                auto t = DQ.front();
                DQ.pop_front();
                DQ.push_back(t);
            }
            ret = DQ.front();
            DQ.pop_front();
        }
        cout << ret << "\n";
    }    
    return 0;
}