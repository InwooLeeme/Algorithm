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

using pt = pair<int, string>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    vector<pt> v(n);
    for(auto& [a, b] : v) cin >> a >> b;
    map<char, int> check;
    for(auto& i : s) check[i]++;
    int mn = int(2e9);
    for(int i = 1; i < (1 << n); i++){
        map<char, int> M;
        int cost = 0;
        bool flag = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                cost += v[j].first;
                for(auto& k : v[j].second) M[k]++;
            }
        }
        for(auto& [a, b] : check){
            if(!M.count(a)) {flag = 1; break;}
            if(b > M[a]) {flag = 1; break;}
        }
        if(!flag) mn = min<int>(mn, cost);
    }
    cout << (mn == 2e9 ? -1 : mn) << "\n";
    return 0;
}