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
using tii = tuple<int, int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  	int k,r,n,m; cin >> k >> r >> n;
  	vector<pt> v(n);
  	vector<int> chk;
  	for(int i = 0; i < n; i++) chk.push_back(i < k ? 0 : 1);
  	for(auto& [a, b] : v) cin >> a >> b;
  	cin >> m;
  	vector<tii> pos(m);
  	for(auto& [a, b, c] : pos) cin >> a >> b >> c;
  	int mx = 0;
  	do{
  		int sum = 0;
  		vector<pt> vv;
  		for(int i = 0; i < n; i++) if(!chk[i]) vv.push_back(v[i]);
  		for(auto& [x, y, c] : pos){
  			bool flag = 0;
  			for(auto& [a, b] : vv){
  				if(sqrt((a - x) * (a - x) + (b - y) * (b - y)) <= r){
  					flag = 1;
  					break;
				  }
			}
			if(flag) sum += c;
		  }
  		mx = max<int>(mx, sum);
	}while(next_permutation(chk.begin(), chk.end()));
  	cout << mx << '\n';
    return 0; 
}
