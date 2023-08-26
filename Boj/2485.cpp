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

const int PRECISION = 0;

void Main(){
	int n,ret = 0,prv = 0; cin >> n;
	vector<int> v(n),w;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(i) w.push_back(v[i] - prv);
		prv = v[i];
	}
	int g = w[0];
	for(int i = 0; i < (int)w.size(); i++) g = __gcd(g, w[i]);
	ret = (v.back() - v[0]) / g - n + 1;
	cout << ret << "\n"; 
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
