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

constexpr int MOD = 1e9 + 7;

int32_t main(){
    fastio;
    int T; cin >> T; cin.ignore();
    for(int t=1; t<=T; t++) {
        string str; cin >> str;
        int ret = 1;
        for(int i=0; i<str.length(); i++) {
            vector<char> v;
            if(i > 0) v.push_back(str[i-1]);
            v.push_back(str[i]);
            if(i+1 < str.length()) v.push_back(str[i+1]);
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            ret = (ret * v.size()) % MOD;
        }
        cout << "Case #" << t << ": " << ret << "\n";
    }
    return 0;
}