# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using pt = pair<int, string>;

int n,m;
vector<int> g[440044];
int indegree[440044];
int check[440044];
map<string, int> M;
map<int, string> revM;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int idx = 1;
    for(int i = 0; i < n; i++){
        string a,b; cin >> a >> b;
        if(!M.count(a)) M[a] = idx++,revM[idx - 1] = a;
        if(!M.count(b)) M[b] = idx++,revM[idx - 1] = b;
        g[M[a]].push_back(M[b]);
        indegree[M[b]]++;
    }
    queue<int> Q;
    for(int i = 1; i < idx; i++){
        if(!indegree[i]){
            Q.push(i);
            check[i] = 1;
        }
    }
    vector<int> vist(idx, 0);
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        vist[cur] = 1;
        for(auto nxt: g[cur]){
            if(--indegree[nxt] == 0){
                check[nxt] = check[cur] + 1;
                Q.push(nxt);
            }
        }
    }
    for(int i = 1; i < idx; i++){
        if(!vist[i]){
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<pt> v;
    for(int i = 1; i < idx; i++) v.push_back({check[i], revM[i]});
    sort(v.begin(), v.end());
    for(auto& i : v) cout << i.second << "\n";
    return 0;   
}
