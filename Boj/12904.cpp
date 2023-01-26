#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int_fast64_t
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t; cin >> s >> t;
    function<bool(string)> F = [&](string cur) -> bool{
        if(cur.size() <= s.size()) return cur == s;
        bool ret = 0;
        if(cur.back() == 'A') ret |= F(cur.substr(0, cur.size() - 1));
        if(cur.back() == 'B'){
            cur.pop_back();
            reverse(cur.begin(), cur.end());
            ret |= F(cur);
        }
        return ret;
    };
    cout << F(t) << "\n";
}   
