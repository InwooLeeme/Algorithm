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
    while(1){
        vector<string> v;
        int n; cin >> n;
        if(!n) break;
        while(n--){
            string s; cin >> s;
            v.push_back(s);
        }
        int w; cin >> w;
        while(w--){
            string s; cin >> s;
            v.push_back(s);
        }
        auto cp =  [&](string& a, string& b) -> bool{
            if(a[0] != b[0]){
                if(a[0] == 'S') return true;
                else if(b[0] == 'S') return false;
                else if(a[0] == 'M') return true;
                else return false;
            }
            return a[1] < b[1];
        };
        sort(v.begin(), v.end(), cp);
        for(auto& c : v) cout << c << ' ';
        cout << '\n';
    }
    return 0;
}