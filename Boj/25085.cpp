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
    auto Check = [&](const string& x) -> bool{
        return equal(x.begin(), x.end(), x.rbegin());
    };
    for(int tc = 1; tc <= T; tc++){
        int N,cnt = 0; cin >> N;
        vector<int> v;
        for(int i = 1; i * i <= N; i++){
            if(N % i == 0){
                v.push_back(i); v.push_back(N / i);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(auto& i : v) if(Check(to_string(i))) cnt++;
        cout << "Case #" << tc << ": " << cnt << "\n";
    }
    return 0;
}