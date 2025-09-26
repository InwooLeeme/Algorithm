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

int n,m,res;

void solve(){
    cin >> n >> m;
    vector<bitset<2020>> vist(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; --a,--b;
        vist[a].set(b);
    }
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
        auto t = (vist[i] & vist[j]).count();
        res += ((t * (t - 1)) / 2);
    }
    cout << res << "\n";
}

void Main(){
    int t = 1; 
	//ri(t);
	while(t--) solve();
	/* for(int tc = 1; tc <= t; tc++){
		cout << "Case #" << tc << ": "; solve();
	} */
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
