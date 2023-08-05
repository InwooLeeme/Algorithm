#pragma GCC target("avx,avx2,fma")
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

using p = pair<int, int>;

const int PRECISION = 0;

void Main(){
	int n,k; cin >> n >> k;
	vector<int> v(n); for(auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	auto Check = [&](const int mid) -> bool{
		int ret = 0;
		for(auto& i : v) if(i > mid) ret += abs(i - mid);
		return ret <= k;
	};
	int lo = -1,hi = int(5e18);
	while(lo + 1 < hi){
		int mid = lo + hi >> 1;
		if(!Check(mid)) lo = mid;
		else hi = mid;
	}
	cout << hi << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();	
    return 0;
}
