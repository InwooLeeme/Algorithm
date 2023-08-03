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

void Sol(){
	int n; cin >> n;
	vector<bool> vist(11111);
	for(int i = 0,a,b; i < n; i++){
		cin >> a >> b;
		for(int j = a; j < b; j++) vist[j] = 1;
	}
	int ret = 0;
	for(int i = 0; i < 11111; i++) ret += vist[i];
	cout << ret << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}
