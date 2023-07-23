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

#define int int_fast64_t

int32_t main(){
    fastio;
    int n,m,ret = 0; cin >> n >> m;
    int l = 0,r = n - 1;
    vector<int> v(n); for(auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    while(l < r){
    	if(v[l] + v[r] > m) r--;
    	else l++,ret++,r--;
	}
    cout << ret << "\n";
    return 0;
}
