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
	int n,q,idx = -1; cin >> n;
	vector<string> v(n); for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] == "?") idx = i;
	}
	cin >> q; vector<string> w(q); for(auto& i : w) cin >> i;
	if(n == 1){
		cout << w[0] << "\n";
		return;
	}
	for(auto& c : w){
		set<string> S;
		v[idx] = c;
		for(int i = 0; i < n; i++){
			if(i == idx) continue;
			S.insert(v[i]);
		}
		if(S.count(c)) continue;
		if(idx == 0 and v[idx + 1].front() == c.back()){
			cout << c << "\n";
			return;
		}
		else if(idx == n - 1 and v[idx - 1].back() == c.front()){
			cout << c << "\n";
			return;
		}
		else if(0 < idx and idx < n - 1 and v[idx - 1].back() == c.front() and c.back() == v[idx + 1].front()){
			cout << c << "\n";
			return;
		}
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
