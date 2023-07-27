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

const int PRECISION = 0;

void Sol(){
    int n,m; cin >> n >> m; vector<int> v(m),w; for(auto& i : v) cin >> i;
    for(int i = 0; i < m; i++){
        w.push_back(v[i]);
        for(int j = i + 1; j < m; j++) w.push_back(v[i] + v[j]);
    }
    auto Bound = [&](int x) -> bool { return x < 0 or x > n; };
    vector<int> d(n + 1, -1);
    d[0] = 0; queue<int> Q; Q.push(0);
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        for(auto c : w){
            auto nxt = cur + c;
            if(Bound(nxt) or d[nxt] != -1) continue;
            d[nxt] = d[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << d[n] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}