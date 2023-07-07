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
    int n; cin >> n;
    vector<pt> v(n);
    for(int i = 0,a,b,c; i < n; i++){
        string s; cin >> s >> a >> b >> c;
        v[i] = {2*a + 3*b + c, s};
    }
    sort(v.begin(), v.end(), [&](pt& a, pt& b){
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    });
    if(!n) return 0;
    if(v.size() > 1) cout << v[0].second << "\n" << v[1].second << "\n";
    else cout << v[0].second << "\n";
    return 0;
}