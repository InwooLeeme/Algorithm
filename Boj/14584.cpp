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
    int n,flag = 0;
    string s; cin >> s >> n;
    vector<string> v(n);
    for(auto& i : v) cin >> i;
    for(int x = 0; x < 26; x++){
        auto r = s;
        for(auto& i : r) i = char(((i - 'a' + x + 26) % 26) + 'a');
        for(const auto& c : v){
            if(r.find(c) != -1){
                cout << r << '\n';
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    return 0;
}