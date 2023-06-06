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

int n,m;

pt Sol(vector<int>& v){
	if(v.size() == 0) return {0, 0};
	sort(v.begin(), v.end());
	int idx = v.size() - 1;
	pt ret = { 0, v.back()};
	while(idx >= 0){
		ret.first += v[idx];
		idx -= m;
	}
	return ret;
}


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  	cin >> n >> m;
  	vector<int> a,b;
  	for(int i = 0,t; i < n; i++){
  		cin >> t;
  		(t < 0 ? a : b).push_back(abs(t));
	}
	auto t1 = Sol(a),t2 = Sol(b);
	cout << (t1.first + t2.first) * 2 - max<int>(t1.second, t2.second) << "\n";
    return 0; 
}
