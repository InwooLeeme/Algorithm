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
    int idx, st, en;
    bool operator < (const Query& q) const {
		if (st / sqrtn != q.st / sqrtn) return st < q.st;
		return en < q.en;
	}
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // input
    int n,m; cin >> n >> m;
    sqrtn = sqrt(n);
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    auto I = v;
    sort(I.begin(), I.end()); I.erase(unique(I.begin(), I.end()), I.end());
    auto IDX = [&](int x) -> int{ return lower_bound(I.begin(), I.end(), x) - I.begin(); };
    for(auto& i : v) i = IDX(i);
    // mo's
    vector<Query> Q(m);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        Q[i] = {i, --a, --b};
    }
    sort(Q.begin(), Q.end());
    vector<int> ret(m),cnt(I.size());
    int res = 0, s = Q[0].st, e = Q[0].en;
    auto Push = [&](int i) -> void{
        if(cnt[v[i]] == 2) res--;
        cnt[v[i]]++;
        if(cnt[v[i]] == 2) res++;
    };
    auto Pop = [&](int i) -> void{
        if(cnt[v[i]] == 2) res--;
        cnt[v[i]]--;
        if(cnt[v[i]] == 2) res++;
    };
    for(int i = s; i <= e; i++) Push(i);
    ret[Q[0].idx] = res;
    for(int i = 1; i < m; i++){
        while (Q[i].st < s) Push(--s);
		while (Q[i].st > s) Pop(s++);
        while (Q[i].en > e) Push(++e);
		while (Q[i].en < e) Pop(e--);
        ret[Q[i].idx] = res;
    }
    // print
    for(auto& c : ret) cout << c << "\n";
    return 0;
}