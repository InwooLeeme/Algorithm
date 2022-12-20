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
    int T; cin >> T; cin.ignore();
    while(T--){
        string s; cin >> s;
        auto ori = stoll(s);
        int ret = 0,flag = 0;
        vector<int> v;
        do{
            auto cur = stoll(s);
            if(ori < cur){
                ret = cur;
                flag = 1;
                break;
            }
        }while(next_permutation(s.begin(), s.end()));
        if(flag) cout << ret << "\n";
        else cout << "USELESS" << "\n";
    }
    return 0;
}