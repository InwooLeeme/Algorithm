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

int sqrtn;
struct Query{
    int idx,st,en;
    bool operator<(const Query& q) const{
        if(st / sqrtn != q.st / sqrtn) return st < q.st;
        return en < q.en;
    };
};
const int sz = int(1e7);
int cnt[sz + 10];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m; cin >> n >> m;
    sqrtn = sqrt(n);
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    vector<Query> Q(m);
    for(int i = 0,a,b; i < m; i++){
        cin >> a >> b;
        Q[i] = {i, --a, --b};
    }
    sort(Q.begin(), Q.end());
    vector<int> ret(m);
    int cur = 0,s = Q[0].st,e = Q[0].en;
    for(int i = s; i <= e; i++){
        cur -= cnt[v[i]] * cnt[v[i]] * v[i];
        cnt[v[i]]++;
        cur += cnt[v[i]] * cnt[v[i]] * v[i];
    }
    ret[Q[0].idx] = cur;
    for(int i = 1; i < m; i++){
        auto [idx, st, en] = Q[i];
        while(s < st){
            cur -= cnt[v[s]] * cnt[v[s]] * v[s];
            cnt[v[s]]--;
            cur += cnt[v[s]] * cnt[v[s]] * v[s];
            s++;
        }
        while(s > st){
            s--;
            cur -= cnt[v[s]] * cnt[v[s]] * v[s];
            cnt[v[s]]++;
            cur += cnt[v[s]] * cnt[v[s]] * v[s];
        }
        while(e < en){
            e++;
            cur -= cnt[v[e]] * cnt[v[e]] * v[e];
            cnt[v[e]]++;
            cur += cnt[v[e]] * cnt[v[e]] * v[e];
        }
        while(e > en){
            cur -= cnt[v[e]] * cnt[v[e]] * v[e];
            cnt[v[e]]--;
            cur += cnt[v[e]] * cnt[v[e]] * v[e];
            e--;
        }
        ret[idx] = cur;
    }
    for(auto& i : ret) cout << i << '\n';
    return 0;
}