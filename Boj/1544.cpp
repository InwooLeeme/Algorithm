# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

struct Info{
    string s; 
    bool operator == (const Info& p){
        if(s.size() != p.s.size()) return 0;
        for(int i = 0; i < s.size(); i++){
            s.push_back(s[0]), s.erase(s.begin());
            if(s == p.s) return 1;
        }
        return 0;
    }
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<Info> v;
    for(int i = 0; i < n; i++){
        Info s; cin >> s.s;
        for(int i = 0; i < v.size() || (v.push_back(s), 0); i++) if(v[i] == s) break;
    }
    cout << v.size() << "\n";
    return 0;   
}