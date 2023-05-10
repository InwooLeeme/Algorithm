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

struct P{
    int score, time;
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,ret = 0; cin >> n;
    vector<P> v;
    while(n--){
        int t,a,b; cin >> t;
        if(t){
            cin >> a >> b;
            v.push_back({a, b});
        }
        if(!v.empty()){
            v.back().time--;
            if(!v.back().time){
                ret += v.back().score;
                v.pop_back();
            }
        }
    }
    cout << ret << "\n";
    return 0;
}