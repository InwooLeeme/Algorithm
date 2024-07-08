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

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const int PRECISION = 0;

int n,m;
int p[101010];
int v[101010];

int Find(int x){ return x == p[x] ? x : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b) return 0;
    p[b] = (v[a] > v[b] ? b : a);
    p[a] = (v[a] > v[b] ? b : a);
    v[a] = (v[a] > v[b] ? v[b] : v[a]);
    v[b] = (v[a] > v[b] ? v[b] : v[a]);
    return 1;
}

void Main(){
    iota(p, p + 101010, 0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    int ret = 0;
    min_pq<int> PQ;
    while(m--){
        int a,b; cin >> a >> b;
        Union(a, b);
    }
    for(int i = 1; i <= n; i++){
        if(i == Find(i)) PQ.push(v[Find(i)]);
    }
    while(PQ.size() > 1){
        auto f = PQ.top(); PQ.pop();
        ret += PQ.top() * f;
        PQ.pop();
        PQ.push(f);
    }
    cout << ret << "\n";
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
