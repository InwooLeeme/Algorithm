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
  	int n,m,ret = 0; cin >> n >> m;
  	priority_queue<int, vector<int>, greater<int>> PQ;
  	for(int i = 0; i < n; i++){
  		int a,b; cin >> a >> b;
  		vector<int> score(a);
  		for(auto& I : score) cin >> I;
  		sort(score.rbegin(), score.rend());
  		int s = 1;
  		if(a >= b) s = score[b - 1];
  		PQ.push(s);
	}
	while(!PQ.empty()){
		auto t = PQ.top(); PQ.pop();
		if(m - t >= 0) m -= t,ret++;
	}
  	cout << ret << "\n";
    return 0; 
}
