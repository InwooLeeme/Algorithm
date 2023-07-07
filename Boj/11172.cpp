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

struct Circle{ int x,y,r;};
struct P{string name; Circle c;};

void testcase(){
    int n; cin >> n;
    vector<P> v(n);
    for(auto& I : v) cin >> I.name >> I.c.x >> I.c.y >> I.c.r;
    auto Check = [&](Circle& a, Circle& b) -> bool{
        return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) < (a.r + b.r) * (a.r + b.r);
    };
    vector<int> ret(n);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            cnt += Check(v[i].c, v[j].c);
        }
        ret[i] = cnt;
    }
    int cnt = 0,mx = *max_element(ret.begin(), ret.end()),idx = max_element(ret.begin(), ret.end()) - ret.begin();
    for(auto& i : ret) if(i == mx) cnt++;
    if(cnt >= 2) cout << "TIE" << "\n";
    else cout << v[idx].name << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) testcase();
    return 0;
}