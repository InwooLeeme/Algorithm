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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> d(n + 1, 0), v(n);
	for(auto& i : v) cin >> i;
	for(int i = 0; i < n; i++){
		d[i] = v[i];
		for(int j = 0; j < i; j++) if(v[i] < v[j]) d[i] = max<int>(d[i], d[j] + v[i]);
	}
	cout << *max_element(d.begin(), d.end()) << "\n";
    return 0;   
}
