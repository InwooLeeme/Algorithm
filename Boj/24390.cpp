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

using pi2 = pair<int, int>;

map<int, int> dist;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string ss,m,s; cin >> ss;
    for(auto& i : ss) if(i == ':') i = ' ';
    stringstream in(ss);
    in >> m >> s;
    int en = stoi(m) * 60 + stoi(s);
    auto Bound = [&](int x) -> bool {return x < 0 || x > 3600; };
    dist[0] = 0;
    queue<pi2> Q;
    Q.push({0, 0});
    while(Q.size()){
        auto [cur, t] = Q.front(); Q.pop();
        if(cur == en and t) break;
        if(!Bound(cur + 10) and !dist.count(cur + 10)) dist[cur + 10] = dist[cur] + 1,Q.push({cur + 10, t});
        if(!Bound(cur + 60) and !dist.count(cur + 60)) dist[cur + 60] = dist[cur] + 1,Q.push({cur + 60, t});
        if(!Bound(cur + 600) and !dist.count(cur + 600)) dist[cur + 600] = dist[cur] + 1,Q.push({cur + 600, t});
        if(!t){
            if(t) dist[cur + 30] = dist[cur] + 1, Q.push({cur + 30, t});
            else dist[cur == 0 ? cur + 30 : cur] = dist[cur] + 1, Q.push({cur == 0 ? cur + 30 : cur, 1});
        }
    }
    cout << dist[en] << "\n";
    return 0;
}