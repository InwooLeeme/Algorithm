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
	int n; while(cin >> n and n){
		vector<string> v(n); for(auto& i : v) cin >> i;
		vector<string> u,d,ret;
		for(int i = 0; i < (n >> 1) + (n & 1 ? 1 : 0); i++) u.push_back(v[i]);
		for(int i = (n >> 1) + (n & 1 ? 1 : 0); i < n; i++) d.push_back(v[i]);
		for(int i = 0; i < min<int>(d.size(), u.size()); i++){
			cout << u[i] << "\n" << d[i] << "\n";
		}
		if(n & 1) cout << u.back() << "\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();	
    return 0;
}
