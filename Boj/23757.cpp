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

using pt = pair<int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
    priority_queue<int, vector<int>> PQ;
    for(int i = 0,t; i < n; i++) cin >> t,PQ.push(t);
    vector<int> v(m); for(auto& i : v) cin >> i;
    for(auto& i : v){
        if(!PQ.empty() and PQ.top() >= i){
            auto s = PQ.top(); PQ.pop();
            PQ.push(s - i);
        }
        else{
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
    return 0; 
}
