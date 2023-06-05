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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ":\n";
        [&](){
            int n; cin >> n;
            vector<int> v(n); for(auto& c : v) cin >> c;
            map<int, vector<int>> M;
            for(int i = 1; i < (1 << n); i++){
                int sum = 0;
                vector<int> S;
                for(int j = 0; j < n; j++){
                    if(i & (1 << j)) sum += v[j],S.push_back(v[j]);
                }
                if(M.count(sum)){
                    for(auto& c : M[sum]) cout << c << " ";
                    cout << '\n';
                    for(auto& c : S) cout << c << " ";
                    cout << '\n';
                    return;
                }
                M[sum] = S;
            }
        }();        
    }
    return 0;
}