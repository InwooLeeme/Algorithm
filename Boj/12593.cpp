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
  	int T; cin >> T;
  	for(int tc = 1; tc <= T; tc++){
  		cout << "Case #" << tc << ": ";
  		[&](){
  			int r,k,n; cin >> r >> k >> n;
			deque<int> DQ;
			for(int i = 0,t; i < n; i++) cin >> t,DQ.push_back(t);
			int ret = 0;
			while(r--){
				int cur = 0;
				deque<int> Q;
				while(1){
					if(cur + DQ.front() > k or DQ.empty()) break;
					auto s = DQ.front();
					DQ.pop_front();
					cur += s;
					Q.push_back(s);
				}
				while(!Q.empty()){
					DQ.push_back(Q.front());
					Q.pop_front();
				}
				ret += cur;
			}
			cout << ret << '\n';				
		}();
	  }
    return 0; 
}
