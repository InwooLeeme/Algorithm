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
    int n; cin >> n;
    set<string> s;
    while(n--){
      string a,b; cin >> a >> b;
      if(b == "enter") s.insert(a);
      else if(b == "leave" && a == *(s.find(a))) s.erase(a);
    }
    vector<string> names;
    for(auto &p : s) names.pb(p);
    sort(names.begin(), names.end());
    reverse(names.begin(), names.end());
    for(auto &p : names) cout << p << "\n";
    return 0;
}