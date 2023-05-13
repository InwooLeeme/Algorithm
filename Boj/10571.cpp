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

using pt = pair<double, double>;

void testcase(){
	int n; cin >> n;
	vector<pt> v(n);
	vector<int> d(n + 1);
	for(auto& [a, b] : v) cin >> a >> b;
	for(int i = 0; i < n; i++){
		d[i] = 1;
		for(int j = 0; j <= i; j++){
			if(v[i].first > v[j].first and v[i].second < v[j].second) d[i] = max<int>(d[i], d[j] + 1);
		}
	}
	cout << *max_element(d.begin(), d.end()) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--) testcase();
    return 0;   
}
