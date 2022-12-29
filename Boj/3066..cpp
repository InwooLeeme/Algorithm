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
    while(T--){
        int N; cin >> N;
        vector<int> LIS;
        vector<pair<int,int>> v(N);
        for(int i = 1; i <= N; i++){
            int t; cin >> t;
            v[i - 1] = {i, t};
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < N; i++){
            int t = v[i].second;
            if(LIS.empty() || LIS.back() < t) LIS.push_back(t);
            else *lower_bound(LIS.begin(), LIS.end(), t) = t;
        }
        cout << LIS.size() << "\n";
    }
    return 0;
}